
#include "Movies/movies.cpp"
#include "Movies/classics.cpp"
#include "Movies/comedy.cpp"
#include "Movies/drama.cpp"
#include "Factories/movieFactory.cpp"

int main() {
    ifstream movieData("data4moviess.txt");
    if (!movieData) {
		cout << "File could not be opened." << endl;
		return -1;
	}
    return 0;
}