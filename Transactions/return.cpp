// ------------------------------------------------ return.cpp -----------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a return function
// --------------------------------------------------------------------------------------------------------------------

#include "return.h"
#include <iostream>

using namespace std;

//---------------------------- setData(ifstream &infile, char transactionType) --------------------------------
bool Return::setData(ifstream &infile, char transactionType) {

    //set the transaction type
    setTransactionType(transactionType);

    //read in the customer's ID
    int customerID;
    infile >> customerID;
    setCustomersID(customerID);

    //read in the format
    char format;
    infile >> format;
    setFormat(format);

    //if we don't have a DVD, then it's an improper format, since only DVDs
    // are held at the store currently. print an error message and return false.
    if(format != 'D'){
        cout << "ERROR: '" << format << "' is not a currently allowed movie "
                "format" << endl;

        return false;
    }

    //read in the genre
    char genre;
    infile >> genre;

    //create a partially filled out movie class so we can search the
    // correlating movie BST when we perform the transaction
    Movies* partialMovie = movieFactory.createPartialMovie(genre, infile);
    setMovie(partialMovie);

    return (partialMovie != nullptr);
}


//---------------------------- method() --------------------------------
void Return::doTrans(BST movies[], HashTable& customers) {

    //create a pointer for a movie and a customer, respectively, so we can
    // hold the results of retrieval from the customers hashtable and the
    // movies BST
    Customers* customer;
    Movies* borrowedMovie;
    Movies* movie = getMovie();
    char genre = movie->getGenre();

    //if the customer exists
    if(customers.retrieveCustomer(getCustomersID(), customer)) {

        //and they have borrowed the movie that we want them to return
        if (customer->getBorrowedMovie(movie, borrowedMovie)) {

            //create a pointer for retrieving the movie from the movies BST
            // array
            Movies* moviePointer;

            //if we can find the movie -- to see if the store owns it
            if(movies[genre - 'A'].retrieve(borrowedMovie, moviePointer)){

                //insert the movie that we got from the customer into the
                // store inventory... since it has a stock of 1, it will
                // simply increment the stock of the movie in the store by 1
                movies[genre - 'A'].insert(borrowedMovie);

                //store the title of the movie for use in getString
                movieTitle = moviePointer->getTitle();

                //insert the operation into the customer's history, since it
                // was completed
                customer->insertHistory(getString());

            }else{

                cout << "ERROR: somehow " << *movie << " was checked out, but"
                        " doesn't exist in the store." << endl
                     << *customers << "returned it, but we never owned it in "
                        "the first place." << endl;

            }

        }else{

            cout << "ERROR: " << *customer
                 << " doesn't currently have " << *movie
                    << " checked out" << endl;
        }
    }else{

        cout << "ERROR: " << getCustomersID() << " is not a valid account";
    }
}


//---------------------------- method() --------------------------------
string Return::getString() const {

    //print the string representing this Transaction
    return "Returned " + movieTitle + ".";

}