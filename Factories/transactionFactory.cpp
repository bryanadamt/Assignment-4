// ------------------------------------------------ transactionFactory.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is to make transactions
// --------------------------------------------------------------------------------------------------------------------

#include "transactionFactory.h"
#include <iostream>
#include <sstream>
using namespace std;

//---------------------------- transactionMaker(stringstream&) -------------------------------------
// Takes a line from the file and create a transaction object based on the data
Transactions* TransactionFactory::transactionMaker(stringstream& lineData, HashTable* customerDatabase) {
    Transactions *transaction = NULL;

    char type;
    lineData >> type;

    if (type != 'B' && type != 'R' && type != 'I' && type != 'H') {
        cout << "Invalid input detected " << type;
        cout << " is not a valid type. Line is deleted."<< endl;
        return NULL;
    }

    if (type == 'I') {
        transaction = new Inventory();
    } else if (type == 'H') {
        int customerID;
        lineData >> customerID;
        transaction = new History(customerID, customerDatabase);
    } else {
        BSTree* movieDatabase[97]; //movie database
        int customerID;
        char type, genre; 
        Movies* movie;
        MovieFactory m;

        lineData >> customerID >> type >> genre;
        movie = m.movieMaker(genre, lineData);

        if (type == 'B') {
            transaction = new Borrow(customerID, type, genre, movie, customerDatabase);
        } else if (type == 'R') {
            transaction = new Return(customerID, type, genre, movie, customerDatabase);
        }
    }

    return transaction;
}