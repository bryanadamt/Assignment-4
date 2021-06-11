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


Customers::~Customers()
{

}

//---------------------------- insertHistory(string historyToInsert) -----------------------------
// adds a tansaction into the customer's history
//---------------------------------------------------------------------------
void Customers::insertHistory(string historyToInsert) 
{
    borrowingHistory.push_back(historyToInsert);

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







// //---------------------------- displayHistory() -----------------------------
// // displays the customer's history
// //---------------------------------------------------------------------------

// void Customers::displayHistory(){

//     queue<string> queue;
//     string temp;

//     cout << endl;
//     cout << "The borrowing history for " << firstN << " " << lastN << endl;

//     if(!borrowingHistory.empty()) {

//         // while there's transactions
//         while (!borrowingHistory.empty()) {

//             // pop the transaction
//             temp = borrowingHistory.top();
//             borrowingHistory.pop();

//             // print the transaction
//             cout << " * " << temp << endl;

//             // push it onto the queue
//             queue.push(temp);
//         }

//         // after printed all transactions, put them back in the queue
//         while (!queue.empty()) {

//             temp = queue.front();
//             borrowingHistory.push(temp);
//             queue.pop();
//         }

//         cout << endl;

//     }else{

//         // there's no transactions
//         cout << "This customer has no transaction history." << endl << endl;

//     }

// }



// //---------------------------- borrowMovie(Movies*& movie) ---------------------------------
// // borrow a movie from the movie store
// //---------------------------------------------------------------------------
// void Customers::borrowMovie(Movies*& movie) {

//     // create a copy of the movie and borrow one stock of it
//     Movies* copy = movie;
//     copy->setStock(1);

//     // insert it into the customer's borrowed movies
//     borrowedMovies.push(copy);
// }

// //---------------------------- getBorrowedMovie(Movies*& movie, Movies*& returnMovie) ---------------------------------
// // get a borrowed movie to return it
// //---------------------------------------------------------------------------
// bool Customers::getBorrowedMovie(Movies*& movie, Movies*& returnMovie) {

//     stack<Movies*> stack;
//     Movies* store;

//     while(!borrowedMovies.empty()) {

//         // check the first borrowed movie
//         store = borrowedMovies.front();

//         // there's a movie needed to be return
//         if (*movie == *store) {

//             // set the returnMovie
//             returnMovie = store;

//             // pop off the movie from the customer's borrowed movies
//             borrowedMovies.pop();

//             // back all elements into the queue
//             while(!stack.empty()){

//                 store = stack.top();
//                 borrowedMovies.push(store);
//                 stack.pop();

//             }

//             return true;

//         } else {

//             // there is no movie needed to be return
//             store = borrowedMovies.front();
//             stack.push(store);
//             borrowedMovies.pop();

//         }
//     }

//     // back all elements into the queue
//     while(!stack.empty()){

//         store = stack.top();
//         borrowedMovies.push(store);
//         stack.pop();

//     }

//     return false;

// }

int main() {
    
}