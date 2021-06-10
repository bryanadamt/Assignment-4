// ------------------------------------------------ hashTable.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 10/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a hash table
// --------------------------------------------------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../Customers/customers.h"

using namespace std;

class HashTable {


    struct node{

        Customers* data;
        node* next;

        node(Customers* c, node* n) :
                data(c), next(n) {};
    };

    // set the array size as the MAXHASHSIZE
    node* array[97];


public:

    HashTable();
    ~HashTable();

    // retrieve function
	bool retrieveCustomer(int customerID, Customers*& foundCustomer);

    // insert function
    void insert(Customers *customer);

    // building function
	void buildHashTable(ifstream &infile);

private:
    const int MAXHASHSIZE = 97;
    int hash(int customerID);

};

#endif