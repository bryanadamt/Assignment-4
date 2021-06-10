// ------------------------------------------------ inventory.cpp -----------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a inventory function
// --------------------------------------------------------------------------------------------------------------------

#include "inventory.h"
#include <iostream>

using namespace std;

//---------------------------- setData(ifstream& infile, char transactionType) --------------------------------
bool Inventory::setData(ifstream& infile, char transactionType){

    //set the transaction type
    setTransactionType(transactionType);

    //return true, this method is always successful
    return true;

}


//---------------------------- doTrans(BST movies[], HashTable &customers) --------------------------------
void Inventory::doTrans(BST movies[], HashTable &customers) {

    //print some returns to separate the inventory from the previous output
    cout << endl << endl;

    //print out all movie inventories
    for(int i = 0; i < CURRENTMOVIEGENRES; i++){

        cout << HEADERSTRING << endl;
        cout << setw(HEADERLENGTH) << movieGenreNames[i] << endl;
        cout << HEADERSTRING << endl << endl;

        //print out a head line
        cout << HEADERTITLE << HEADERSTOCK << endl << endl;

        //print the given binary tree of movies
        cout << movies[movieGenres[i] - 'A'] << endl;
    }

    //print more returns to separate what comes after the inventory
    cout << endl << endl;
}


//---------------------------- getString() --------------------------------
string Inventory::getString() const {

    //print the string representing this Transaction
    return "Viewed store inventory.";
}