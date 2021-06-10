// ------------------------------------------------ borrow.cpp -----------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a borrow function
// --------------------------------------------------------------------------------------------------------------------

#include "borrow.h"
#include <iostream>

using namespace std;

//---------------------------- setData(ifstream& infile, char transactionType) --------------------------------
bool Borrow::setData(ifstream& infile, char transactionType){

    //set the transaction type
    setTransactionType(transactionType);

    //set the customer ID
    int customerID;
    infile >> customerID;
    SetCustomersID(customerID);

    //set the format
    char format;
    infile >> format;
    setFormat(format);


    if(format != 'D'){
        cout << "ERROR: '" << format << "' is not a currently allowed movie "
                "format" << endl;

        return false;
    }

    //set the genre of the movie
    char genre;
    infile >> genre;

    //create a partially filled out movie class so we can search the
    // correlating movie BST when we perform the transaction
    Movies* partialMovie = movieFactory.createPartialMovie(genre, infile);
    setMovie(partialMovie);

    return (partialMovie != nullptr);
}


//---------------------------- doTrans(BST movies[], HashTable &customers) --------------------------------
void Borrow::doTrans(BST movies[], HashTable &customers) {

    //create a pointer for a movie and a customer, respectively, so we can
    // hold the results of retrieval from the customers hashtable and the
    // movies BST
    Movies* stockedMovie;
    Customers* customers;
    Movies* movie = getMovie();
    char genre = movie->getGenre();

    //if the customer exists
    if(customers.retrieveCustomer(getCustomersID(), customers)) {

        //if we can find the movie
        if (movies[genre - 'A'].retrieve(movie, stockedMovie)) {

            //and copies of the movie are in stock
            if (stockedMovie->getStock() > 0) {

                //let the customer borrow the movie -- the borrowMovie method
                // makes a copy of the movie with stock == 1,  and then we
                // reduce the stock of the store's copy of the movie by 1
                customers->borrowMovie(movie);
                stockedMovie->setStock(stockedMovie->getStock() - 1);

                //store the title of the movie for use in getString
                movieTitle = stockedMovie->getTitle();

                //insert the operation into the customer's history, since it
                // was completed
                customers->insertHistory(getString());

                //otherwise print out one of the following errors, depending
                // on what went wrong
            } else {

                cout << "ERROR: " << "there are no copies of " <<
                     stockedMovie->getTitle() << " currently in stock " << endl;
            }

        } else {

            cout << "ERROR: " << *movie << " is not in stock" << endl;
        }
    }else{

        cout << "ERROR: " << getCustomersID()
             << " is not a valid account" << endl;
    }
}


//---------------------------- getString() --------------------------------
string Borrow::getString() const {

    return "Borrowed " + movieTitle + ".";

}
