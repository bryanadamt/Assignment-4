// ------------------------------------------------ inventory.cpp -----------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a inventory function
// --------------------------------------------------------------------------------------------------------------------

#include "inventory.h"
#include <iostream>

using namespace std;

const int GENRES = 3; // number of genres

// Contructor for inventroy,
// for now the class is just to perform one
// specific function.
// In the future, if more functions is to be added
// to inventory, the class can be modified.
Inventory::Inventory() {}

void Inventory::readFullInventory(BSTree moviesArray[] ) {
    for (int i = 0; i < GENRES; i++) {
        BSTree temp;
        temp = moviesArray[i];
        temp.displayInOrder();
    }
}