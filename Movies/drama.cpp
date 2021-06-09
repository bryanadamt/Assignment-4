// ------------------------------------------------ drama.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a drama movie
// --------------------------------------------------------------------------------------------------------------------

#include "drama.h"

using namespace std;

//---------------------------- Drama(int, string, string, int) -------------------------------------
// Constructor
Drama::Drama(int stock, string director, string title, int year) {
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYear(year);
}

//---------------------------- ~Drama() -------------------------------------
// Destructor
Drama::~Drama() {

}

//---------------------------- toString() -------------------------------------
// Prints the object
void Drama::toString(ostream& stream) const {
    stream << getStock() << " " << getDirector() << " " << getTitle() << " " << getYear();
}