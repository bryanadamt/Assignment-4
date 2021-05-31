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
    this.stock = stock;
    this.director = director;
    this.title = title;
    this.mActor = actor;
    this.month = month;
    this.year = year;
}

//---------------------------- ~Classics() -------------------------------------
// Destructor
Classics::~Classics() {

}

//---------------------------- setMonth(int) -------------------------------------
// Sets the month of a classic movie
void Classics::setMonth(int newMonth) {
    month = newMonth;
}

//---------------------------- setMActor(string) -------------------------------------
// Sets the major Actor of a classic movie
void Classics::setMonth(string newMActor) {
    mActor = newMActor;
}

//---------------------------- getMonth() -------------------------------------
// Gets the month of a classic movie
int Classics::getMonth() {
    return month;
}

//---------------------------- getMActor() -------------------------------------
// Gets the full name of the major actor
int Classics::getMActor() {
    return mActor;
}