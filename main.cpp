#include "Movie_Store/store.h"
#include "Movie_Store/store.cpp"

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream movieData("data4movies.txt");
    ifstream customerData("data4Customers.txt");
    ifstream transactionsData("data4commands.txt");

    Store stores;
    stores.readMovieData(movieData);
    stores.readCustomerData(customerData);
    stores.readTransactionsData(transactionsData);

    stores.run();

    return 0;
}