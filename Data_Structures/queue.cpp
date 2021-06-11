// ------------------------------------------------ queue.cpp -----------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 10/6/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of queue
// --------------------------------------------------------------------------------------------------------------------

#include "queue.h"
#include <iostream>
#include <sstream>

using namespace std;

//---------------------------- ~Queue() --------------------------------
Queue::~Queue(){

    Node* store; // temp node

    while (head != nullptr) {

        store = head;
        head = head->next; // pointer for the next node

        delete store->data;
        store->data = nullptr;

        delete store; // deletes head
    }

    head = nullptr; // remove the pointer
}



//---------------------------- push(Transactions* transaction) --------------------------------
void Queue::push(Transactions* transaction) {

    if (head == nullptr) {
        // if the list is empty
        head = new Node(transaction, nullptr);

    } else {

        Node* current = head;

        while (current->next != nullptr) {

            current = current->next;
        }

        current->next = new Node(transaction, nullptr); // add to the end
    }
}


//---------------------------- pop() --------------------------------
Transactions* Queue::pop() {

    Node* store = head;
    Transactions* transaction = nullptr;

    if (head != nullptr) {

        transaction = head->data;
        head = head->next;
        delete store;

    }

    return transaction;
}


//---------------------------- empty() --------------------------------
bool Queue::empty() {
    // return if the head of the list is empty
    return (head == nullptr);
}

//---------------------------- buildQueue(ifstream &infile) --------------------------------
void Queue::buildQueue(ifstream &infile) {

    // read the transaction type
    char transactionType;
    infile >> transactionType;

    while(!infile.eof()) {

        // create a pointer
        Transactions* temp = nullptr;

        if(transactionFactory.createTransaction(transactionType, temp, infile)){

            // when the transaction was created, push it into the queue
            push(temp);

        }else{

            // remove the rest of the line
            string store;
            getline(infile, store);

            // delete the temporary transaction
            if(temp != nullptr) delete temp;
        }

        // read the next transaction type
        infile >> transactionType;

        // break at the end of the file
        if(infile.eof()) break;
    }
}