
#include "Movies/movies.h"
#include "Movies/classics.h"
#include "Movies/comedy.h"
#include "Movies/drama.h"
#include "Factories/movieFactory.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
    ifstream movieData("data4movies.txt");
    if (!movieData) {
		cout << "File could not be opened." << endl;
		return -1;
	}

    // std::string input = "C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942";
    // std::istringstream ss(input);
    // std::string token;


    
    // while(std::getline(ss, token, ',')) {
    //     std::cout << token << '\n';
    // }

    MovieFactory m;
    string line;
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