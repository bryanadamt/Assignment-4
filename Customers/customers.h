// ------------------------------------------------ customers.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a customer
// --------------------------------------------------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>
#include <iostream>

#include "../Data_Structures/bstree.h"

using namespace std;

class Customers {

    friend ostream& operator<<(ostream& stream, const Customers& customer);

public:

    // constructor and destructor
	Customers();
	Customers(string firstN, string lastN, int customerID);
	~Customers();    
    

    // display the customer's history
    void displayHistory();

    // insert the customer's history
	void insertHistory(string historyToInsert);

    // // borrow a movie from the movie store
    // void borrowMovie(Movies*& movie);

    // // get a borrowed movie to return it
    // bool getBorrowedMovie(Movies*& movie, Movies*& returnMovie);


    // getters and setters
    int getCustomerID() const;
    string getFirstN() const;
    string getLastN() const;

	bool setCustomerID(int customerID);
	bool setFirstN(string firstN);
	bool setLastN(string lastN);
	bool setCustomerData(string firstN, string lastN, int customerID);


private:
    // Unique ID Number
    int customerID;
    // first name
    string firstN;
    // last name
    string lastN;
    
    vector<string> borrowingHistory;

};

#endif