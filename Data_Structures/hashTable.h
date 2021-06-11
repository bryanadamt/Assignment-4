// ------------------------------------------------ hashTable.h -------------------------------------------------------
// Ayumi Oishi, CSS 343B
// Created: 10/6/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a hash table
// --------------------------------------------------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../Customers/customers.h"

using namespace std;

class HashTable {
    struct Node{

        Customers* data;
        Node* next;

        Node(Customers* c, Node* n) :
                data(c), next(n) {};
    };

    public:
        HashTable();

        bool retrieve(int customerID, Customers*& foundCustomer);
        void insert(Customers *customer);
        void buildHashTable(ifstream &infile);

    private:
        const int HASHSIZE = 97;
        Node* array[97];
        int hash(int customerID);
};

#endif