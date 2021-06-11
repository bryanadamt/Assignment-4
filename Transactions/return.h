// ------------------------------------------------ return.h -------------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a return function
// --------------------------------------------------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

#include "transactions.h"
#include "../Movies/movies.h"
#include "../Data_Structures/bstree.h"
#include "../Factories/movieFactory.h"
#include "../Data_Structures/hashTable.h"

using namespace std;

class Return : public Transactions {
    public:
        // Constructor
        Return(int, char, char, Movies*, HashTable*);
        void doReturn(BSTree []);
    private:
        bool validChecker(BSTree []);
        Customers* customer = NULL;
};

#endif