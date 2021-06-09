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
// Assign movie to one of the genres and fill it with the data
Movies* MovieFactory::movieMaker(stringstream& lineData) {
    Movies *newMovie = NULL;
    // Temporary variable to store individual data
    string data;
    
    // Get Genre
    getline(lineData, data, ',');
    char genre;
    genre = data[0];

    if (genre != 'F' && genre != 'D' && genre != 'C') {
        cout << "invalid input detected " << genre;
        cout << " is not a valid genre."<< endl;
        return NULL;
    }

    int stock, month, year;
    string director, title, actor;

    // Get Stock
    getline(lineData, data, ',');
    stock = stoi(data);
    // Get Director Name
    getline(lineData, director, ',');
    // Get Title
    getline(lineData, title, ',');
    // Get the rest of the data
    getline(lineData, data, ',');

    if (genre == 'F') {
        year = stoi(data);
        newMovie = new Comedy(genre, stock, director, title, year);
    } 
    else if (genre == 'D') {
        year = stoi(data);
        newMovie = new Drama(genre, stock, director, title, year);
    } 
    else if (genre == 'C') {
        stringstream ss(data);
        string fname, lname;
        ss >> fname >> lname >> month >> year;
        actor = fname + " " + lname;
        newMovie = new Classics(genre, stock, director, title, actor, month, year);
    }

    return newMovie;
}