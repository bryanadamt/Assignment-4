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
Comedy::Comedy(char genre,int stock, string director, string title, int year) {
    setGenre(genre);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYear(year);
}

//---------------------------- ~Comedy() -------------------------------------
// Destructor
Comedy::~Comedy() {

}

//---------------------------- operator== -------------------------------------
// Overload equality operator
// Preconditions: There has to be 2 Comedy objects
// Postconditions: Comedy is unchanged
bool Comedy::operator==(const Movies &toCompare) const {
	return (title == toCompare.getTitle() && year == toCompare.getYear());
}

//---------------------------- operator> -------------------------------------
// Overload more than operator
// Preconditions: There has to be 2 Comedy objects
// Postconditions: Comedy is unchanged
bool Comedy::operator>(const Movies &toCompare) const {
    if (title != toCompare.getTitle()) {
        return title > toCompare.getTitle();
    }
	return year > toCompare.getYear();
}

//---------------------------- operator< -------------------------------------
// Overload less than operator
// Preconditions: There has to be 2 Comedy objects
// Postconditions: Comedy is unchanged
bool Comedy::operator<(const Movies &toCompare) const {
    if (title != toCompare.getTitle()) {
        return title < toCompare.getTitle();
    }
	return year < toCompare.getYear();
}

//---------------------------- toString() -------------------------------------
// Prints the object
void Comedy::toString() const {
    cout << getStock() << " " << getDirector() << " " << getTitle() << " " << getYear() << endl;
}