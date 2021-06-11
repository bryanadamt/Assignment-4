#include "Movie_Store/store.h"
#include "Movie_Store/store.cpp"

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream movieData("data4movies.txt");

    Store stores;
    stores.readMovieData(movieData);

    return 0;
}