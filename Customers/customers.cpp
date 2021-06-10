// ------------------------------------------------ customers.cpp -----------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a customer
// --------------------------------------------------------------------------------------------------------------------

#include "customers.h"
#include <iostream>

using namespace std;

//---------------------------- setCustomer() --------------------------------
// sets the customer's ID, first name, and last name from the file
//---------------------------------------------------------------------------

bool Customers::setCustomer(ifstream &infile){

    // read the customer's ID
    infile >> customerID;

    if (customerID < 0)
    {
        // display error message for the invalid user ID
        cout << "Error. Please check the customer ID" << endl;

        return false;
    }
    else
    {
        // read and set the customer's name from the file
        infile >> lastN;
        infile >> firstN;

        return true;
    }
    
}


//---------------------------- displayHistory() -----------------------------
// displays the customer's history
//---------------------------------------------------------------------------

void Customers::displayHistory(){

}

//---------------------------- addTransaction() -----------------------------
// adds a tansaction into the customer's history
//---------------------------------------------------------------------------

void Customers::addTransaction(){

}


//---------------------------- getHistory() ---------------------------------
// get the customer's history
//---------------------------------------------------------------------------

void Customers::getHistory(){

}

//---------------------------- operator<<(ostream& stream, const Customers& customer)---------------------------------
// print out the Customer's name, followed by their Iy
//---------------------------------------------------------------------------

ostream& operator<<(ostream& stream, const Customers& customer){

    stream << customer.getFirstN() << " " 
           << customer.getLastN() << " (ID: " 
           << customer.getCustomerID() << ")";

    return stream;
}

//---------------------------- getters and setters() --------------------------------
// returns the customer's ID, first name, and last name from the file
//---------------------------------------------------------------------------
int Customers::getCustomerID() const{
    return customerID;
}
string Customers::getFirstN() const{
    return firstN;
}
string Customers::getLastN() const{
    return lastN;
}