// ------------------------------------------------ BSTree.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 6/9/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is for a binary search tree to store the movies
// and to store them in order
// --------------------------------------------------------------------------------------------------------------------

#include "bstree.h"

using namespace std;

// //---------------------------- ~BSTree() -------------------------------------
// // Destructor
// // Preconditions: There has to be a BSTree object
// // Postconditions: BSTree object is deleted completely
// BSTree::~BSTree() {
// 	makeEmpty();
// }

// //---------------------------- makeEmpty() -------------------------------------
// // Completely deletes current BSTree object
// // Preconditions: There has to be a BSTree object
// // Postconditions: BSTree object is deleted completely
// void BSTree::makeEmpty() {
// 	makeEmptyHelper(root);
// }

// //---------------------------- makeEmptyHelper(Node*&) -------------------------------------
// // Helper function to makeEmpty
// // Preconditions: There has to be a BSTree
// // Postconditions: BSTree deleted
// void BSTree::makeEmptyHelper(Node*& curNode) {
// 	if (curNode != NULL) {
// 		makeEmptyHelper(curNode->left);
// 		makeEmptyHelper(curNode->right);

// 		delete curNode->movie;
// 		curNode->movie = NULL;
// 		delete curNode;
// 		curNode = NULL;
// 	}
// }

//---------------------------- insert(Movies*) -------------------------------------
// Inserts a new Node to the BSTree
// Preconditions: There has to be a Movies object
// Postconditions: BSTree is changed if a new Node is inserted
// 				   stays the same if it doesn't
bool BSTree::insert(Movies* toInsert) {
	return insertHelper(root, toInsert);
}

//---------------------------- insertHelper(Node*&, Movies*&) -------------------------------------
// Helper function to insert
// Preconditions: There has to be a Movies object
// Postconditions: BSTree is changed if a new Node is inserted
// 				   stays the same if it doesn't
bool BSTree::insertHelper(Node*& curr, Movies*& toInsert) {
	if (curr == NULL) {
		curr = new Node;
		curr->movie = toInsert;
		curr->left = NULL;
		curr->right = NULL;
	} else if (*curr->movie == *toInsert) {
		int newStock = curr->movie->getStock() + toInsert->getStock();
		curr->movie->setStock(newStock);
		return false;
	} else if (*curr->movie > *toInsert) {
		insertHelper(curr->left, toInsert);
	} else if (*curr->movie < *toInsert) {
		insertHelper(curr->right, toInsert);
	}
	return true;
}

//---------------------------- retrieve(Movies*, Movies*&) -------------------------------------
// Retrieve the Movie* of a given object in the tree (via pass-by-reference parameter)
// and to report whether the object is found (true or false).
// Preconditions: There has to be a Movies object
// Postconditions: address is updated with the address of the 
//  			   Movies if it's found.
bool BSTree::retrieve(const Movies *toFind, Movies *&address) const {
	retrieveHelper(toFind, address, root);
	return (address != NULL);
}

//---------------------------- retrieveHelperMovies*, Movies*&, Node*) -------------------------------------
// Helper Fucntion to retrieve function
// Preconditions: There has to be a Movie object
// Postconditions: address is updated with the address of the 
//  			   Movie if it's found.
void BSTree::retrieveHelper(const Movies *toFind, Movies *&address, Node *curr) const {
	if (curr != NULL) {
		if (*curr->movie == *toFind) {
			address = curr->movie;
		} else if (*curr->movie < *toFind) {
			retrieveHelper(toFind, address, curr->right);
		} else {
			retrieveHelper(toFind, address, curr->left);
		}
	} else {
		address = NULL;
	}
}

//---------------------------- displayInOrder() -------------------------------------
// Display the Tree in Order
// Preconditions: None
// Postconditions: Bstree is unchanged and pritned in order traversal
void BSTree::displayInOrder() const {
	displayHelper(root);
}

//---------------------------- displayHelper(Node*) -------------------------------------
// Display the Tree in Order
// Preconditions: None
// Postconditions: Bstree is unchanged and pritned in order traversal
void BSTree::displayHelper(Node* curr) const {
	if (curr != NULL) {
		displayHelper(curr->left);
		curr->movie->toString();
		displayHelper(curr->right);
	} 
}