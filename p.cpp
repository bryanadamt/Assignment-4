
#include "Movies/movies.cpp"
#include "Movies/classics.cpp"
#include "Movies/comedy.cpp"
#include "Movies/drama.cpp"
#include "Factories/movieFactory.cpp"

int main() {
    ifstream moviesFile("data4movies.txt");
    string a;
    while (getline(moviesFile, a)) {
        stringstream s(a);
        string t;
        while (s.good()) {
            getline(s, t, ',');
            cout << t;
        }
        cout << endl;
    }
    return 0;
}