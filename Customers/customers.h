// ------------------------------------------------ customers.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a customer
// --------------------------------------------------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stack>
#include <queue>
#include <fstream>
#include "../Data_Structures/bstree.h"

using namespace std;

class Customers {

    friend ostream& operator<<(ostream& stream, const Customers& customer);

public:

    // set the customer
    bool setCustomer(ifstream &infile);

    // display the customer's history
    void displayHistory();

    // insert the customer's history
	void insertHistory(string historyToInsert);

    // borrow a movie from the movie store
    void borrowMovie(Movies*& movie);

    // get a borrowed movie to return it
    bool getBorrowedMovie(Movies*& movie, Movies*& returnMovie);


    // getters and setters
    int getCustomerID() const;
    string getFirstN() const;
    string getLastN() const;

private:
    // Unique ID Number
    int customerID;
    // first name
    string firstN;
    // last name
    string lastN;
    
    stack<string> borrowingHistory;
    queue<Movies*> borrowedMovies;
};

#endif