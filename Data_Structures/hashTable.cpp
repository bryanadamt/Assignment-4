// ------------------------------------------------ hashTable.cpp -----------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 10/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a customer
// --------------------------------------------------------------------------------------------------------------------

#include "hashtable.h"

using namespace std;

//---------------------------- HashTable() --------------------------------
HashTable::HashTable(){

    // set null
    for(int i = 0; i < MAXHASHSIZE; i++){
        array[i] = nullptr;
    }

}

//---------------------------- ~HashTable() --------------------------------
HashTable::~HashTable(){

    // create a current to hold nodes in the lists of the hashtable
    node* current;

    // go through the whole array
    for(int i = 0; i < MAXHASHSIZE; i++){

        // for each list, traverse the whole list
        while(array[i] != nullptr){

            // capture the node at the front and move the head of the list
            // forward
            current = array[i];
            array[i] = array[i]->next;

            // delete the data of the node
            delete current->data;
            current->data = nullptr;

            // delete the node itself
            delete current;

        }

        // dereference the bucket from the list to prevent dangling references
        array[i] = nullptr;
    }
}


//---------------------------- retrieveCustomer(int customerID, Customers*& foundCustomer) --------------------------------

bool HashTable::retrieveCustomer(int customerID, Customers*& foundCustomer) {

    // hash the ID of the customer
    int IDHash = hash(customerID);

    //p oint to the list in the specified bucket defined by the hashed ID integer
    node* current = array[IDHash];

    // traverse the whole list
    while (current != nullptr){

        // if we find the desired customer which we want to retrieve
        if(current->data->getCustomerID() == customerID){

            // point the foundCustomer pointer at it and return true to
            // indicate that we found them
            foundCustomer = current->data;
            return true;

        }else{

            // check the next list
            current = current->next;
        }
    }

    // return false when customer's not founded
    return false;
}

//---------------------------- insert(Customers* customer) --------------------------------
void HashTable::insert(Customers* customer){

    //hash the customer's ID
    int IDHash = hash(customer->getCustomerID());

    //store the head node of the bucket
    node* current = array[IDHash];
    node* previous = nullptr;

    while(current != nullptr){

        if(customer->getCustomerID() == current->data->getCustomerID()){

            cout << "ERROR: duplicate ID " << customer->getCustomerID()
                 << " not inserted." << endl;

            delete customer;

            return;

        }else{

            previous = current;
            current = current->next;
        }
    }

    if(previous == nullptr) {

        //put the customer in at the front of the list, pointing to the previous
        // head of the list
        current->next = new node(customer, nullptr);

    }else{

        //put the customer in at the front of the list, pointing to the previous
        // head of the list
        previous->next = new node(customer, nullptr);

    }
}

//---------------------------- hash(int customerID) --------------------------------
int HashTable::hash(int customerID) {

    // hash based on the maximum hash size, the size of the array. This is a
    // large prime number
    return customerID % MAXHASHSIZE;

}

//---------------------------- hash(int customerID) --------------------------------
void HashTable::buildHashTable(ifstream& infile) {

    //while the file has data to read
    while(!infile.eof()) {

        //create a new customer
        Customers* temp = new Customers;

        //if we are able to create a new Customer, aka all the data is correct
        if(temp->setCustomer(infile)){

            //and we haven't reached the end of file (no reason to insert a
            // non-existent customer
            if(!infile.eof()) {

                //insert the customer
                insert(temp);

            }else{

                //this is not good data, delete it
                delete temp;

            }
        }else{

            // we were unable to create a customer, delete this malformed
            // abomination from hell
            delete temp;

        }
    }
}