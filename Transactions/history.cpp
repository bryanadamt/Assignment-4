// ------------------------------------------------ history.cpp -----------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a history function
// --------------------------------------------------------------------------------------------------------------------

#include "history.h"
#include <iostream>

using namespace std;

//---------------------------- setData(ifstream &infile, char transactionType) --------------------------------
bool History::setData(ifstream &infile, char transactionType) {

    //set the transaction type
    setTransactionType(transactionType);

    //set the customer ID
    int customerID;
    infile >> customerID;
    setCustomersID(customerID);

    //there is no way for the method to fail, so we return true
    return true;
}


//---------------------------- doTrans(BST movies[], HashTable& customers) --------------------------------
void History::doTrans(BST movies[], HashTable& customers) {

    //create a temporary pointer to a Customer
    Customers* customers;

    //retrieve the customer that this Transaction requires
    if(customers.retrieveCustomer(getCustomersID(), customers)){

        //if we successfully retrieve the customer then store their name for
        // getString purposes
        customerName = customers->getFirstName() + " " + customers->getLastName();

        //display the customer's history
        customers->displayHistory();

    }else{

        //otherwise we weren't able to find the customer, print an error
        cout << "ERROR: " << *customers << " does not have an account";
    }
}


//---------------------------- getString() --------------------------------
string History::getString() const {

    //print out the string representation of this Transaction
    stringstream ss;
    ss << "Displayed ";
    ss << customerName;
    ss << "'s transaction history.";

    return ss.str();
}