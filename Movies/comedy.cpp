// ------------------------------------------------ comedy.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a comedy movie
// --------------------------------------------------------------------------------------------------------------------

#include "comedy.h"

using namespace std;

//---------------------------- Comedy(int, string, string, int) -------------------------------------
// Constructor
Comedy::Comedy(int stock, string director, string title, int year) {
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYear(year);
}

//---------------------------- ~Comedy() -------------------------------------
// Destructor
Comedy::~Comedy() {

}

//---------------------------- toString() -------------------------------------
// Prints the object
void Comedy::toString() const {
    cout << getStock() << " " << getDirector() << " " << getTitle() << " " << getYear() << endl;
}