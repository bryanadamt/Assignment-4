// ------------------------------------------------ transactionFactory.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is to make transactions
// --------------------------------------------------------------------------------------------------------------------

#include "../Transactions/borrow.h"
#include "../Transactions/history.h"
#include "../Transactions/inventory.h"
#include "../Transactions/return.h"
#include <iostream>
#include <sstream>

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

using namespace std;

class TransactionFactory {
    public:
        // Assign transaction that was read from the file to one of the transaction type
        Transactions* transactionMaker(stringstream&);
};

#endif