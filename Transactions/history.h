// ------------------------------------------------ hitory.h -------------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a history function
// --------------------------------------------------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "transactions.h"
#include "../Customers/customers.h"
#include "../Data_Structures/hashTable.h"

using namespace std;

class History : public Transactions {
    public:
        History(int, HashTable*);
        void showHistory();
    private:
        Customers* customer;
};

#endif