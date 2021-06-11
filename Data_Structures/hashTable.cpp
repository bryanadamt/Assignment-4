// ------------------------------------------------ hashTable.cpp -----------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 10/6/2021
// Date of Last Modification: 10/6/2021
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

    // create a current node
    node* current;

    // go through the whole array
    for(int i = 0; i < MAXHASHSIZE; i++){

        // traverse the whole list
        while(array[i] != nullptr){

            // capture the node at the front, move the head of the list forward
            current = array[i];
            array[i] = array[i]->next;

            // delete the node data
            delete current->data;
            current->data = nullptr;

            // delete the node
            delete current;

        }

        // dereference the array from the list
        array[i] = nullptr;
    }
}


//---------------------------- retrieveCustomer(int customerID, Customers*& foundCustomer) --------------------------------

bool HashTable::retrieveCustomer(int customerID, Customers*& foundCustomer) {

    // hash the customer's ID
    int IDHash = hash(customerID);

    // point to the list in the specified array defined by the hashed ID number
    node* current = array[IDHash];

    // traverse the whole list
    while (current != nullptr){

        
        if(current->data->getCustomerID() == customerID){

            // point the foundCustomer pointer at it and return true
            // when the customer was founded
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

    // hash the customer's ID
    int IDHash = hash(customer->getCustomerID());

    // store the head node of the array
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

        // put the customer in at the front of the list and 
        // point to the previous head of the list
        current->next = new node(customer, nullptr);

    }else{

        // put the customer in at the front of the list and
        // point to the previous head of the list
        previous->next = new node(customer, nullptr);

    }
}

//---------------------------- hash(int customerID) --------------------------------
int HashTable::hash(int customerID) {

    // hash based on the maximum hash size with a large prime number
    return customerID % MAXHASHSIZE;

}

//---------------------------- buildHashTable(ifstream& infile) --------------------------------
void HashTable::buildHashTable(ifstream& infile) {

    while(!infile.eof()) {

        // create a new customer
        Customers* temp = new Customers;

        // // all the data is correct if we are able to create a new Customers
        // if(temp->setCustomerData(infile)){

        //     if(!infile.eof()) {

        //         //insert the customer
        //         insert(temp);

        //     }else{

        //         delete temp;

        //     }
        // }else{

        //     // delete this when we are unable to create a customer
        //     delete temp;

        // }
    }
}