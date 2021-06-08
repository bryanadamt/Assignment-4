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
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
}

//---------------------------- ~Drama() -------------------------------------
// Destructor
Drama::~Drama() {

}