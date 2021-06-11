// ------------------------------------------------ borrow.h -------------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a borrow function
// --------------------------------------------------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H

#include "transactions.h"
#include "../Movies/movies.h"
#include "../Factories/movieFactory.h"
#include "../Data_Structures/hashTable.h"

using namespace std;

class Borrow : public Transactions {
    public:
        // Constructor
        Borrow(int, char, char, Movies*, HashTable*);
        void doBorrow(BSTree []);
    private:
        bool validChecker(BSTree []);
        Customers* customer = NULL;
};

#endif