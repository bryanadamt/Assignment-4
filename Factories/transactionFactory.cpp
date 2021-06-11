// ------------------------------------------------ transactionFactory.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is to make transactions
// --------------------------------------------------------------------------------------------------------------------

#include "transactionFactory.h"
#include <iostream>
using namespace std;

Transactions* TransactionFactory::transactionMaker(stringstream& lineData) {
    Transactions *transaction = NULL;

    char type;
    lineData >> type;

    return transaction;
}