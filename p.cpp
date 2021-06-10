#include "Movie_Store/store.h"

#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream movieData("data4movies.txt");

    Store store;
    store.readMovieData(movieData);

    store.comedy.displayInOrder();

    // MovieFactory m;
    // string line;
    // while (getline(movieData, line)) {
    //     stringstream ss(line);
    //     Movies *newMovie = NULL;
    //     newMovie = m.movieMaker(ss);
    //     if (newMovie != NULL) {
    //         newMovie->toString();
    //     }
    // }

    return 0;
}