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
Classics::Classics(int stock, string director, string title, string mActor, int month, int year) {
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMActor(mActor);
    setMonth(month);
    setYear(year);
}

//---------------------------- ~Classics() -------------------------------------
// Destructor
Classics::~Classics() {
////////////////////////////// need destructor
}

//---------------------------- setMActor(string) -------------------------------------
// Sets the major Actor of a classic movie
void Classics::setMActor(string newMActor) {
    mActor = newMActor;
}

//---------------------------- setMonth(int) -------------------------------------
// Sets the month of a classic movie
void Classics::setMonth(int newMonth) {
    month = newMonth;
}

//---------------------------- getMonth() -------------------------------------
// Gets the month of a classic movie
int Classics::getMonth() const {
    return month;
}

//---------------------------- getMActor() -------------------------------------
// Gets the full name of the major actor
string Classics::getMActor() const {
    return mActor;
}

//---------------------------- toString() -------------------------------------
// Prints the object
void Classics::toString() const {
    cout << getStock() << " " << getDirector() << " " << getTitle() << " ";
    cout << getMActor() << " " << getMonth() << " " << getYear() << endl;
}
