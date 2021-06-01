// ------------------------------------------------ movies.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a movie
// --------------------------------------------------------------------------------------------------------------------

#include "movies.h"

#include <iostream>

using namespace std;

//---------------------------- setStock(int) -------------------------------------
// changes the stock number of a certain movie
void Movies::setStock(int newStock) {
    stock = newStock;
}

//---------------------------- setTitle(string) -------------------------------------
// changes the title of a movie
void Movies::setTitle(string newTitle) {
    title = newTitle;
}

//---------------------------- setDirector(string) -------------------------------------
// changes the director name of a certain movie
void Movies::setDirector(string newDirector) {
    director = newDirector;
}

//---------------------------- setYear(int) -------------------------------------
// changes the year of a certain movie
void Movies::setYear(int newYear) {
    year = newYear;
}

//---------------------------- getStock() -------------------------------------
// get the stock number of a certain movie
int Movies::getStock() const {
    return stock;
}

//---------------------------- getTitle() -------------------------------------
// get the title of a movie
string Movies::getTitle() const {
    return title;
}

//---------------------------- getDirector() -------------------------------------
// get the name of the director of a certain movie
string Movies::getDirector() const {
    return director;
}

//---------------------------- getYear() -------------------------------------
// get the year number of a certain movie
int Movies::getYear() const {
    return year;
}