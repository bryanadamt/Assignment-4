// ------------------------------------------------ transactions.h -------------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a transaction function
// --------------------------------------------------------------------------------------------------------------------

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "../Data_Structures/bstree.h"
#include "../Data_Structures/hashtable.h"
#include "../Movies/movies.h"

using namespace std;

class Transactions {

public:
    // getters and setters
    char getTransactionType() const;
    int getCustomersID() const;
    char getMediaType() const;
    Movies* getMovie() const;

    void setTransactionType(char transactionType);
    void setCustomersID(int customerID);
    void getMediaType(char mediaType);
    void setMovie(Movies* movie);

private:
    int customerID;
    char transactionType;
    char genre;
    char mediaType;
    Movies* movie;
};

#endif