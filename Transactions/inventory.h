// ------------------------------------------------ inventory.h -------------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a inventory function
// --------------------------------------------------------------------------------------------------------------------

#ifndef INVENTORY_H
#define INVENTORY_H

#include "transactions.h"


using namespace std;

class Inventory : public Transactions {

public:

    void doTrans(BST movies[], HashTable &customers);
    bool setData(ifstream& infile, char transactionType);


private:
    string getString() const;

};

#endif