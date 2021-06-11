// ------------------------------------------------ borrow.cpp -----------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a borrow function
// --------------------------------------------------------------------------------------------------------------------

#include "borrow.h"
#include <iostream>

using namespace std;

//---------------------------- Borrow(int, char, char, Movie*) --------------------------------
Borrow::Borrow(int ID, char mediaType, char genre, Movie* movie) {
    setCustomersID(customerID);
    setMediaType(mediaType);
    setGenre(genre);
}
