// ------------------------------------------------ hashTable.cpp -----------------------------------------------------
// Ayumi Oishi, CSS 343B
// Created: 10/6/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a customer
// --------------------------------------------------------------------------------------------------------------------

#include "hashtable.h"

using namespace std;

//---------------------------- HashTable() --------------------------------
HashTable::HashTable(){
    for(int i = 0; i < HASHSIZE; i++){
        array[i] = NULL;
    }
}

//---------------------------- retrieve(int customerID, Customers*& foundCustomer) --------------------------------
bool HashTable::retrieve(int customerID, Customers*& foundCustomer) {
    int hash = hash(customerID);
    Node* current = array[hash];
    while (current != nullptr){
        if(current->data->getCustomerID() == customerID) {
            foundCustomer = current->data;
            return true;
        } else {
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

    // store the head Node of the array
    Node* current = array[IDHash];
    Node* previous = nullptr;

    while(current != nullptr){
        if(customer->getCustomerID() == current->data->getCustomerID()){
            return;
        } else {
            previous = current;
            current = current->next;
        }
    }

    if(previous == nullptr) {
        current->next = new Node(customer, nullptr);
    } else {
        previous->next = new Node(customer, nullptr);
    }
}

//---------------------------- hash(int customerID) --------------------------------
int HashTable::hash(int customerID) {
    return customerID % HASHSIZE;
}

//---------------------------- buildHashTable(ifstream& infile) --------------------------------
void HashTable::buildHashTable(ifstream& infile) {
    while(!infile.eof()) {
        Customers* temp = new Customers;
        if(temp->setCustomerData(infile)) {
            if(!infile.eof()) {
                insert(temp);
            }
        }
    }
}