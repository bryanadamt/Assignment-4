// ------------------------------------------------ classics.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a classic movie
// --------------------------------------------------------------------------------------------------------------------

#include "classics.h"

using namespace std;

//---------------------------- Classics(int, string, string, string, int, int) -------------------------------------
// Constructor
Classics::Classics(int stock, string director, string title, string mactor, int month, int year) {
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMActor(mactor);
    setMonth(month);
    setYear(year);
}

//---------------------------- ~Classics() -------------------------------------
// Destructor
Classics::~Classics() {

}
