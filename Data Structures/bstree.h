#ifndef BSTREE_H
#define BSTREE_H

#include "../Movies/Movies.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class BSTree() {

    friend ostream& operator<<(ostream& out, const BSTree& toPrint);

    public:
        // Destructor
        ~BSTree();

        // Delete the tree
        void makeEmpty();
        // Insert
        void insert(Movies*);
        // Retrieve
        bool retrieve(const Movies*, Movies *&) const;
        // Display Inorder for ...
    private:
        struct Node{
            Movie* movie;
            Node* left;
            Node* right;
        };

        Node* root;

        // Helper Functions
	    void makeEmptyHelper(Node *&);
        bool insertHelper(Node *&, NodeData *&);
	    void retrieveHelper(const NodeData &, NodeData *&, Node *) const;
}

#endif