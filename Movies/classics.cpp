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
Classics::Classics(char genre, int stock, string director, string title, 
                    string mActor, int month, int year) {
    setGenre(genre);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMActor(mActor);
    setMonth(month);
    setYear(year);
}

// Partial Class
Classics::Classics(int month, int year, string mActor) {
    setMonth(month);
    setYear(year);
    setMActor(mActor);
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

//---------------------------- operator== -------------------------------------
// Overload equality operator
// Preconditions: There has to be 2 Classics objects
// Checks of the title and director and release date is the same
// The assignment asks to sort by mactor, but to combine in classics,
// it might be the same movie but have multiple major actors,
// so it's best to compare using the said comparison attribute.
// Postconditions: Classics is unchanged
bool Classics::operator==(const Movies &toCompare) const {
        return (month == toCompare.getMonth() &&
                year == toCompare.getYear() &&
                mActor == toCompare.getMActor());
}

//---------------------------- operator> -------------------------------------
// Overload more than operator
// Preconditions: There has to be 2 Classics objects
// Postconditions: Classics is unchanged
bool Classics::operator>(const Movies &toCompare) const {
    if (year != toCompare.getYear()) {
        return year > toCompare.getYear();
    } else if (month != toCompare.getMonth()) {
        return month > toCompare.getMonth();
    }
    return mActor > toCompare.getMActor();
}

//---------------------------- operator< -------------------------------------
// Overload less than operator
// Preconditions: There has to be 2 Classics objects
// Postconditions: Classics is unchanged
bool Classics::operator<(const Movies &toCompare) const {
    if (year != toCompare.getYear()) {
        return year < toCompare.getYear();
    } else if (month != toCompare.getMonth()) {
        return month < toCompare.getMonth();
    }
    return mActor < toCompare.getMActor();
}

//---------------------------- toString() -------------------------------------
// Prints the object
void Classics::toString() const {
    cout << getStock() << " " << getDirector() << " " << getTitle() << " ";
    cout << getMActor() << " " << getMonth() << " " << getYear() << endl;
}
