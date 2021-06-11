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
Borrow::Borrow(int ID, char mediaType, char genre, Movies* movie, HashTable* database) {
    setCustomersID(ID);
    setMediaType(mediaType);
    setGenre(genre);
    setMovie(movie);
    database->retrieveCustomer(getCustomersID(), this->customer);
}

void Borrow::doBorrow(BSTree movieDatabase[]) {
    if (!validChecker(movieDatabase)) {
        return;
    }

    customer->borrow(getMovie());
    getMovie()->setStock(getMovie()->getStock() - 1);
    // then insert to customer history.
}

bool Borrow::validChecker(BSTree movieDatabase[]) {
    // Check Valid Customer
    if (customer == NULL) {
        cout << "Fail to retrieve customer account" << endl;
        cout << getCustomersID() << " does not exist." << endl;
        return false;
    }

    // Check Valid Movie
    Movies* tempMovie;
    if (getGenre() == 'F') {
        movieDatabase[0].retrieve(getMovie(), tempMovie);
    } else if (getGenre() == 'D') {
        movieDatabase[1].retrieve(getMovie(), tempMovie);
    } else if (getGenre() == 'C') {
        movieDatabase[2].retrieve(getMovie(), tempMovie);
    }

    if (tempMovie == NULL) {
        cout << "Fail to retrieve Movie" << endl;
        cout << getMovie() << " does not exist." << endl;
        return false;
    } else {
        // To change the movie that is already in the BSTree
        setMovie(tempMovie);
    }

    // Check if there is still copy in stock
    if (getMovie()->getStock() <= 0) {
        cout << getMovie() << " is out of Stock." << endl;
        return false;
    }

    return true;
}