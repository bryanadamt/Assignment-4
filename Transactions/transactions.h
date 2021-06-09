// ------------------------------------------------ transactions.h -------------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a transaction function
// --------------------------------------------------------------------------------------------------------------------

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "../Data Structures/bstree.h"
#include "../Data Structures/hashtable.h"

using namespace std;

class Transactions {

    public:
        virtual void doTrans();
        virtual bool setData();
        virtual string getString() const = 0;

        // getters and setters
        char getTransationType() const;
        int getCustomersID() const;
        char getFormat() const;
        //Movies* getMovie() const;


        void setTransactionType(char transactionType);
        void setCusomersID(int customerID);
        void setFormat(char format);
        //void setMovie(Movies* movie);

    private:
        int customerID;
        char transactionType;
        char genre;
        char format;
        //Movies* movie;

};

#endif