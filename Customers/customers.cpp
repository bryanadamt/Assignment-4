// ------------------------------------------------ customers.cpp -----------------------------------------------------
// Ayui Oishi CSS 343B
// Created: 30/5/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a customer
// --------------------------------------------------------------------------------------------------------------------

#include "customers.h"
#include <stack>
#include <iostream>

using namespace std;

Customers::Customers()
{
	setFirstN("");
	setLastN("");
	setCustomerID(0);
}


Customers::Customers(string firstN, string lastN, int customerID)
{
	setFirstN(firstN);
	setLastN(lastN);
	setCustomerID(customerID);
}

//---------------------------- insertHistory(string historyToInsert) -----------------------------
// adds a tansaction into the customer's history
//---------------------------------------------------------------------------
void Customers::insertHistory(string historyToInsert) 
{
    borrowingHistory.push(historyToInsert);
}

//---------------------------- operator<<(ostream& stream, const Customers& customer)---------------------------------
// print out the customer's name and ID
//---------------------------------------------------------------------------

ostream& operator<<(ostream& stream, const Customers& customer){

    stream << customer.getFirstN() << " " 
            << customer.getLastN() << " (ID: " 
            << customer.getCustomerID() << ")" << endl;
    for (int i = 0; i < customer.borrowingHistory.size(); i++)
    {
        stream << " " << customer.borrowingHistory[i] << endl;
    }

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

bool Customers::setCustomerID(int customerID)
{
    if ((customerID < 0) || (customerID > 9999))
    {
        cout << "Error. Please check the customer ID: " << customerID << endl;
        return false;
    }
    else
    {
        customerID = customerID;
        return true;
    }
    
}

bool Customers::setFirstN(string firstN)
{
    this->firstN = firstN;
    return true;
}

bool Customers::setLastN(string lastN)
{
    this->lastN = lastN;
    return true;
}

bool Customers::setCustomerData(string firstN, string lastN, int customerID)
{
    return setFirstN(firstN) && setLastN(lastN) && setCustomerID(customerID);
}


//---------------------------- displayHistory() -----------------------------
// displays the customer's history
//---------------------------------------------------------------------------
void Customers::displayHistory(){
    queue<string> queue;
    string temp;
    cout << endl;
    cout << "Borrowing history for " << firstN << " " << lastN << endl;

    if (borrowingHistory.empty()) {
        cout << "No history found" << endl;
    }

    while (!borrowingHistory.empty()) {
        temp = borrowingHistory.top();
        borrowingHistory.pop();
        cout << " * " << temp << endl;
        queue.push(temp);
    }

    while (!queue.empty()) {
        temp = queue.front();
        borrowingHistory.push(temp);
        queue.pop();
    }
    cout << endl;
}

//---------------------------- borrowMovie(Movies*& movie) ---------------------------------
// borrow a movie from the movie store
//---------------------------------------------------------------------------
void Customers::borrowMovie(Movies* movie) {
    Movies* copy = movie;
    copy->setStock(1);
    borrowedMovies.push(copy);
}

//---------------------------- getBorrowedMovie(Movies*& movie, Movies*& returnMovie) ---------------------------------
// get a borrowed movie to return it
//---------------------------------------------------------------------------
bool Customers::getBorrowedMovie(Movies* movie, Movies* returnMovie) {
    stack<Movies*> stack;
    Movies* store;

    while(!borrowedMovies.empty()) {
        store = borrowedMovies.front();
        if (*movie == *store) {
            returnMovie = store;
            borrowedMovies.pop();
            while(!stack.empty()){
                store = stack.top();
                borrowedMovies.push(store);
                stack.pop();
            }
            return true;
        } else {
            store = borrowedMovies.front();
            stack.push(store);
            borrowedMovies.pop();
        }
    }
    while(!stack.empty()){
        store = stack.top();
        borrowedMovies.push(store);
        stack.pop();
    }
    return false;
}