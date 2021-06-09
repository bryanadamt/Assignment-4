// ------------------------------------------------ BSTree.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 6/9/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is for a binary search tree to store the movies
// and to store them in order
// --------------------------------------------------------------------------------------------------------------------

#include "../Data Structures/bstree.h"

using namespace std;

//---------------------------- ~BSTree() -------------------------------------
// Destructor
// Preconditions: There has to be a BSTree object
// Postconditions: BSTree object is deleted completely
BSTree::~BSTree() {
	makeEmpty();
}

//---------------------------- makeEmpty() -------------------------------------
// Completely deletes current BSTree object
// Preconditions: There has to be a BSTree object
// Postconditions: BSTree object is deleted completely
void BSTree::makeEmpty() {
	makeEmptyHelper(root);
}

//---------------------------- makeEmptyHelper() -------------------------------------
// Helper function to makeEmpty
// Preconditions: There has to be a BSTree
// Postconditions: BSTree deleted
void BSTree::makeEmptyHelper(Node*& curNode) {
	if (curNode != NULL)
	{
		makeEmptyHelper(curNode->left);
		makeEmptyHelper(curNode->right);

		delete curNode->movie;
		curNode->data = NULL;
		delete curNode;
		curNode = NULL;
	}
}

//---------------------------- insert() -------------------------------------
// Inserts a new Node to the BSTree
// Preconditions: There has to be a Node object
// Postconditions: BSTree is changed if a new Node is inserted
// 				   stays the same if it doesn't
bool BSTree::insert(Movie* toInsert) 
{
	return insertHelper(root, toInsert);
}

//---------------------------- insertHelper() -------------------------------------
// Helper function to insert
// Preconditions: There has to be a Movie object
// Postconditions: BSTree is changed if a new Node is inserted
// 				   stays the same if it doesn't
bool BSTree::insertHelper(Node*& curr, Movie*& toInsert) 
{
	if (curr == NULL)
	{
		curr = new Node;
		curr->movie = toInsert;
		curr->left = NULL;
		curr->right = NULL;
		return true;
	}
	else if (*curr->movie == *toInsert)
	{
		return false;
	}
	else if (*curr->movie > *toInsert) 
	{
		insertHelper(curr->left, toInsert);
	}
	else if (*curr->movie < *toInsert)
	{
		insertHelper(curr->right, toInsert);
	}
	return true;
}

//---------------------------- retrieve() -------------------------------------
// Retrieve the Movie* of a given object in the tree (via pass-by-reference parameter)
// and to report whether the object is found (true or false).
// Preconditions: There has to be a Movie object
// Postconditions: address is updated with the address of the 
//  			   Movie if it's found.
bool BinTree::retrieve(const Movie &toFind, Movie *&address) const
{
	retrieveHelper(toFind, address, root);
	return (address != NULL);
}

//---------------------------- retrieveHelper() -------------------------------------
// Helper Fucntion to retrieve function
// Preconditions: There has to be a Movie object
// Postconditions: address is updated with the address of the 
//  			   Movie if it's found.
void BinTree::retrieveHelper(const Movie &toFind, Movie *&address, Node *curr) const
{
	// if (curr != NULL) {
	// 	if (*curr->data == toFind)
	// 	{
	// 		address = curr->data;
	// 	}
	// 	else if (*curr->data < toFind)
	// 	{
	// 		retrieveHelper(toFind, address, curr->right);
	// 	}
	// 	else 
	// 	{
	// 		retrieveHelper(toFind, address, curr->left);
	// 	}
	// } 
	// else 
	// {
	// 	address = NULL;
	// }
}