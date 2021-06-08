// ------------------------------------------------ movieFactory.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - class used to make different genres of movie
// --------------------------------------------------------------------------------------------------------------------

#include "movieFactory.h"
#include <fstream>
#include <string>
using namespace std;

//---------------------------- movieMaker(stringstream&) -------------------------------------
// Assign movie that was read from the file to one of the genres
Movies* MovieFactory::movieMaker(const stringstream& lineData) {
    Movies *newMovie = NULL;
    string genre, data;
    getline(lineData, genre, ',');

    if (genre == 'F' || genre == 'D' || genre == 'C') {
        cout << "invalid input detected" << endl;
        return NULL;
    }
    int stock, month, year;
    string director, title, actor;

    // Get stock
    getline(lineData, data, ',');
    stock = data;
    // Get director name
    getline(lineData, data, ',');
    director = data;
    // Get title
    getline(lineData, data, ',');
    title = data;

    // Get the last part of the string and put it into data
    getline(lineData, data, ',');

    if (genre == 'F') {
        // Get Year
        year = data;
        newMovie = new Comedy(stock, director, title, year);
    } else if (genre == 'D') {
        // Get Year
        year = data;
        newMovie = new Drama(stock, director, title, year);
    } else if (genre == 'C') {
        string[] temp = data.split(" ");        
        // Get Actor full name
        actor = temp[0] + temp [1];
        // Get Month
        month = temp[2];
        // Get Year
        year = temp[3];
    }

    return newMovie;
    // note deal with movie that has correct genre but incomplete data
}