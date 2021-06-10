// ------------------------------------------------ store.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is to represent the movie rental store 
// It combines all other classes together
// --------------------------------------------------------------------------------------------------------------------

#include "store.h"
#include <fstream>
#include <string>

using namespace std;

//---------------------------- readMovieData(ifstream&) -------------------------------------
// Read the entire movie file
void Store::readMovieData(ifstream& movieData) {
    if (!movieData) {
		cout << "File could not be opened." << endl;
		return;
	}

    string line;
    while (getline(movieData, line)) {
        Movies *newMovie = NULL;
        stringstream ss(line);
        newMovie = mFactory.movieMaker(ss);

        if (newMovie == NULL) {
            continue;
        }
        // cout << newMovie->getGenre(); //found it
        // newMovie->toString();

        if (newMovie->getGenre() == 'F') {
            comedy.insert(newMovie);
        } else if (newMovie->getGenre() == 'D') {
            drama.insert(newMovie);
        } else if (newMovie->getGenre() == 'C'){
            classics.insert(newMovie);
        }
    }
}