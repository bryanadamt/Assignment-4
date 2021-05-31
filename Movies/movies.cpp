// ------------------------------------------------ movies.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a movie
// --------------------------------------------------------------------------------------------------------------------

#include "../Movies/movies.h"

#include <iostream>

using namespace std;

//---------------------------- setStock(int) -------------------------------------
// changes the stock number of a certain movie
void Movie::setStock(int newStock) {
    stock = newStock;
}

//---------------------------- setTitle(string) -------------------------------------
// changes the title of a movie
void Movie::setStock(string newTitle) {
    title = newTitle;
}

//---------------------------- setDirector(string) -------------------------------------
// changes the director name of a certain movie
void Movie::setDirector(string newDirector) {
    director = newDirector;
}

//---------------------------- setYear(int) -------------------------------------
// changes the year of a certain movie
void Movie::setStock(int newYear) {
    year = newYear;
}

//---------------------------- getStock() -------------------------------------
// get the stock number of a certain movie
int Movie::getStock() {
    return stock;
}

//---------------------------- getTitle() -------------------------------------
// get the title of a movie
string Movie::getTitle() {
    return title;
}

//---------------------------- getDirector() -------------------------------------
// get the name of the director of a certain movie
string Movie::getDirector() {
    return director;
}

//---------------------------- getYear() -------------------------------------
// get the year number of a certain movie
int Movie::getYear() {
    return year;
}