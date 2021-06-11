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

//---------------------------- getTransationType() --------------------------------
char Transactions::getTransationType() const{
    return transactionType;
}

        
//---------------------------- getCustomersID() --------------------------------
int Transactions::getCustomersID() const{
    return customerID;
}

//---------------------------- getMediaType() --------------------------------
char Transactions::getMediaType() const{
    return mediaType;
}

// ---------------------------- getMovie() --------------------------------
Movies* Transactions::getMovie() const{
    return movie;
}


//---------------------------- setTransactionType(char transactionType) --------------------------------
void Transactions::setTransactionType(char transactionType){
    this->transactionType = transactionType;
}


//---------------------------- setCusomersID(int customerID) --------------------------------
void Transactions::setCusomersID(int customerID){
    this->customerID = customerID;
}

//---------------------------- setMediaType(char MediaType) --------------------------------
void Transactions::setMediaType(char mediaType){
    this->mediaType = mediaType;
}

//---------------------------- setMovie(Movies* movie) --------------------------------
void Transactions::setMovie(Movies* movie){
    this->movie = movie; 
}