// ------------------------------------------------ queue.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification: 10/6/2021
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of queue
// --------------------------------------------------------------------------------------------------------------------

#ifndef QUEUE_H
#define QUEUE_H

#include <fstream>
#include "../Transactions/transactions.h"
#include "../Factories/transactionfactory.h"

using namespace std;

class Queue {

    struct Node {
            Transactions* data;
            Node* next;

            Node(Transactions* d, Node* n) : data(d), next(n) {}

            Node() {
                next = nullptr;
            }
    };

private:
	TransactionFactory transactionFactory;

    Node* head = nullptr;

public:

    ~Queue();

    // push the top of the queue
	void push(Transactions* transaction);
	
	// pop the last element from the bottom of the queue.
	Transactions* pop();

    bool empty();

    // build a queue given an ifstream
	void buildQueue(ifstream& infile);
};
#endif