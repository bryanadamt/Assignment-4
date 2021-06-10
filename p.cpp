#include "Movies/classics.h"
#include "Movies/comedy.h"
#include "Movies/drama.h"
#include "Factories/movieFactory.h"
#include "Data_Structures/bstree.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
    cout << "a";
    ifstream movieData("data4movies.txt");
    if (!movieData) {
		cout << "File could not be opened." << endl;
		return -1;
	}

    MovieFactory m;
    string line;
    cout << "a";
    while (getline(movieData, line)) {
        stringstream ss(line);
        Movies *newMovie = NULL;
        newMovie = m.movieMaker(ss);
        if (newMovie != NULL) {
            newMovie->toString();
        }
    }

    return 0;
}