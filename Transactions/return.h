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
#include "../Factories/movieFactory.h"

using namespace std;

class Return : public Transactions {

public:

    void doTrans(BST movies[], HashTable &customers);
    bool setData(ifstream& infile, char transactionType);


private:
    string getString() const;
    string movieTitle;
    MovieFactory movieFactory;

};

#endif