// ------------------------------------------------ hashTable.cpp -----------------------------------------------------
// Ayumi Oishi, CSS 343B
// Created: 10/6/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a customer
// --------------------------------------------------------------------------------------------------------------------

#include "hashTable.h"

using namespace std;

//---------------------------- HashTable() --------------------------------
HashTable::HashTable() {
    for(int i = 0; i < HASHSIZE; i++){
        array[i] = NULL;
    }
}

//---------------------------- retrieve(int customerID, Customers*& foundCustomer) --------------------------------
bool HashTable::retrieve(int customerID, Customers*& foundCustomer) {
    int hashed = hash(customerID);
    Node* current = array[hashed];
    while (current != NULL){
        if(current->data->getCustomerID() == customerID) {
            foundCustomer = current->data;
            return true;
        } else {
            current = current->next;
        }
    }
    return false;
}

//---------------------------- insert(Customers* customer) --------------------------------
void HashTable::insert(Customers* customer){
    int IDHash = hash(customer->getCustomerID());
    Node* current = array[IDHash];
    Node* previous = NULL;

    while(current != NULL){
        if(customer->getCustomerID() == current->data->getCustomerID()){
            return;
        } else {
            previous = current;
            current = current->next;
        }
    }

    if(previous == NULL) {
        current->next = new Node(customer, NULL);
    } else {
        previous->next = new Node(customer, NULL);
    }
}

//---------------------------- hash(int customerID) --------------------------------
int HashTable::hash(int customerID) {
    return customerID % HASHSIZE;
}

//---------------------------- buildHashTable(ifstream& input) --------------------------------
void HashTable::buildHashTable(ifstream& input) {
    // while(!input.eof()) {
    //     Customers* temp = new Customers;
    //     if(temp->setCustomerData(input)) {
    //         if(!input.eof()) {
    //             insert(temp);
    //         }
    //     }
    // }
}

int main() {}