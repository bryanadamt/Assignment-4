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
// Takes a line from the file and create a movie object based on the data
Movies* MovieFactory::movieMaker(stringstream& lineData) {
    Movies *newMovie = NULL;
    // Temporary variable to store individual data
    string data;
    
    // Get Genre
    getline(lineData, data, ',');
    char genre;
    genre = data[0];

    if (genre != 'F' && genre != 'D' && genre != 'C') {
        cout << "Invalid input detected " << genre;
        cout << " is not a valid genre. Line is deleted."<< endl;
        return NULL;
    }

    int stock, month, year;
    string director, title, actor;

    // Get Stock
    getline(lineData, data, ',');
    stock = stoi(data);
    // Get Director Name
    getline(lineData, director, ',');
    director.erase(0, 1); // To erase the first space
    // Get Title
    getline(lineData, title, ',');
    title.erase(0,1); // To erase the first space
    // Get the rest of the data
    getline(lineData, data, ',');

    if (genre == 'F') {
        year = stoi(data);
        newMovie = new Comedy(genre, stock, director, title, year);
    } else if (genre == 'D') {
        year = stoi(data);
        newMovie = new Drama(genre, stock, director, title, year);
    } else if (genre == 'C') {
        stringstream ss(data);
        string fname, lname;
        ss >> fname >> lname >> month >> year;
        newMovie = new Classics(genre, stock, director, title, actor, month, year);
    }
    return newMovie;
}

//---------------------------- movieMaker(bool, stringstream&) -------------------------------------
// partial Moviemaker
Movies* movieMaker(char genre, stringstream& data) {
    Movies* newMovie;
    string temp, title, director, actor;
    int month, year;

    if (genre == 'F') {
        getline(data, title, ',');
        getline(data, temp, ',');
        year = stoi(temp);
        newMovie = new Comedy(title, year);
    } else if (genre == 'D') {
        getline(data, director, ',');
        getline(data, title, ',');
        newMovie = new Drama(director, title);
    } else if (genre == 'C') {
        data >> month >> year;
        data >> actor;
        newMovie = new Classics(month, year, actor);
    }

    return newMovie;
}