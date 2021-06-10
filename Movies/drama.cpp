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
Drama::Drama(char genre, int stock, string director, string title, int year) {
    setGenre(genre);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYear(year);
}

//---------------------------- ~Drama() -------------------------------------
// Destructor
Drama::~Drama() {

}

//---------------------------- operator== -------------------------------------
// Overload equality operator
// Preconditions: There has to be 2 Drama objects
// Postconditions: Drama is unchanged
bool Drama::operator==(const Movies &toCompare) const {
	return (director == toCompare.getDirector() && title == toCompare.getTitle());
}

//---------------------------- operator> -------------------------------------
// Overload more than operator
// Preconditions: There has to be 2 Drama objects
// Postconditions: Drama is unchanged
bool Drama::operator>(const Movies &toCompare) const {
    if (director != toCompare.getDirector()) {
        return director > toCompare.getDirector();
    }
	return title > toCompare.getTitle();
}

//---------------------------- operator< -------------------------------------
// Overload less than operator
// Preconditions: There has to be 2 Drama objects
// Postconditions: Drama is unchanged
bool Drama::operator<(const Movies &toCompare) const {
    if (director != toCompare.getDirector()) {
        return director < toCompare.getDirector();
    }
	return title < toCompare.getTitle();
}

//---------------------------- toString() -------------------------------------
// Prints the object
void Drama::toString() const {
    cout << getStock() << " " << getDirector() << " " << getTitle() << " " << getYear() << endl;
}