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
Borrow::Borrow(int ID, char mediaType, char genre, Movie* movie, HashTable* database) {
    setCustomersID(customerID);
    setMediaType(mediaType);
    setGenre(genre);
    setMovie(movie);
    retrieveCustomer(customerID, this->customer);
    database.retrieveCustomer(customerID, this->customer);
}

void Borrow::doBorrow(Movies*[BSTree*] movieDatabase) {
    if (customer == NULL) {
        cout << "Fail to retrieve customer account" << endl;
        cout << getCustomerID() << " does not exist." << endl;
    }

    Movies* tempMovie;
    if (genre == 'F') {
        movieDatabase[0].retrieve(getMovie(), tempMovie);
    } else if (genre == 'D') {
        movieDatabase[1].retrieve(getMovie(), tempMovie);
    } else if (genre == 'C') {
        movieDatabase[2].retrieve(getMovie(), tempMovie);
    }
} 