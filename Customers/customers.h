// ------------------------------------------------ customers.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a customer
// --------------------------------------------------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <fstream>
#include "../Data Structures/bstree.h"

using namespace std;

class Customers {

    public:

    // set the customer
    bool setCustomer(ifstream &infile);

    // display the customer's history
    void displayHistory();

    // add a tansaction into the customer's history
    void addTransaction();

    // get the customer's history
    void getHistory();

    // getters and setters
    int getCustomerID() const;
    string getFirstN() const;
    string getLastN() const;

    private:
        // Unique Id Number
        int customerID;
        // first name
        string firstN;
        // last name
        string lastN;
};

#endif