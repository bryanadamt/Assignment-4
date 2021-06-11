// ------------------------------------------------ transactions.cpp -----------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a transaction function
// --------------------------------------------------------------------------------------------------------------------

#include "transactions.h"
#include <iostream>

using namespace std;

int Transactions::getCustomersID() const {
    return customerID;
}

char Transactions::getTransationType() const {
    return transactionType;
}

char Transactions::getMediaType() const {
    return mediaType;
}

Movies* Transactions::getMovie() const {
    return movie;
}

char Transactions::getGenre() const {
    return genre;
}


void Transactions::setCustomersID(int customerID ) {
    this->customerID = customerID;
}

void Transactions::setTransactionType(char transactionType) {
    this->transactionType = transactionType;
}

void Transactions::setMediaType(char mediaType) {
    this->mediaType = mediaType;
}

void Transactions::setMovie(Movies* movie) {
    this->movie = movie; 
}

void Transactions::setGenre(char genre) {
    this->genre = genre;
}