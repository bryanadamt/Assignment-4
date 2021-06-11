#ifndef BSTREE_H
#define BSTREE_H

#include "../Movies/movies.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class BSTree {

    //friend ostream& operator<<(ostream& out, const BSTree& toPrint);

    public:
        // // Destructor
        // ~BSTree();

        // // Delete the tree
        // void makeEmpty();
        // Insert
        bool insert(Movies*);
        // Retrieve
        bool retrieve(const Movies*, Movies *&) const;
        // Display BSTree Inorder
        void displayInOrder() const;
    private:
        struct Node{
            Movies* movie;
            Node* left;
            Node* right;
        };

        Node* root;

        // Helper Functions
	    void makeEmptyHelper(Node *&);
        bool insertHelper(Node *&, Movies *&);
	    void retrieveHelper(const Movies *, Movies *&, Node *) const;
        void displayHelper(Node*) const;
};

#endif