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

//---------------------------- buildQueue(ifstream &input) --------------------------------
void Queue::buildQueue(ifstream &input) {

    // read the transaction type
    char transactionType;
    input >> transactionType;

    while(!input.eof()) {

        // create a pointer
        Transactions* temp = nullptr;

        if(transactionFactory.transactionMaker(transactionType, temp, input)){
            push(temp);
        }else{

            // remove the rest of the line
            string store;
            getline(input, store);

            // delete the temporary transaction
            if(temp != nullptr) delete temp;
        }

        // read the next transaction type
        input >> transactionType;

        // break at the end of the file
        if(input.eof()) break;
    }
}