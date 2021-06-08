
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

    string line;
    while (getline(movieData, line)) {
        stringstream ss(line);
        string data;
        char genre;
        getline(ss, data, ',');
        genre = data[0];
        string temp[4];

        if (genre != 'F' && genre != 'D' && genre != 'C') {
            cout << "invalid input detected" << endl;
            continue;
        }
            int stock, month, year;
            string director, title, actor;
            getline(ss, data, ',');
            stock = stoi(data);
            getline(ss, director, ',');
            getline(ss, title, ',');

            getline(ss, data, ',');
        if (genre == 'F') {
            year = stoi(data);
        } else if (genre == 'D') {
            year = stoi(data);
        } else if (genre == 'C') {
            stringstream ss(data);
            ss >> actor >> actor >> month >> year;
        }

        cout << stock << " " << director<< " " << title << " " 
        << actor << month << " " << year << " " << endl;
    }
    return 0;
}