#include "Movie_Store/store.h"
#include "Movie_Store/store.cpp"

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream movieData("data4movies.txt");

    Store stores;
    stores.readMovieData(movieData);

    // stores.comedy.displayInOrder();
    // cout << endl;
    // stores.classics.displayInOrder();
    // cout << endl;
    // stores.drama.displayInOrder();

    return 0;
}