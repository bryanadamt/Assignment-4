// ------------------------------------------------ movieFactory.cpp -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - class used to make different genres of movie
// --------------------------------------------------------------------------------------------------------------------

#include "movieFactory.h"
#include <fstream>
#include <string>
using namespace std;

//---------------------------- movieMaker(stringstream&) -------------------------------------
// Assign movie that was read from the file to one of the genres
bool MovieFactory::movieMaker(stringstream& lineData) {
    string t;
    while (lineData.good()) {
        getline(lineData, t, ',');
        cout << t;
    }    
    // if (genre == 'F') {

    // } else if (genre == 'D') {

    // } else if (genre == 'C') {

    // } else {
    //     cout << "invalid input detected" << endl;
    //     return false;
    // }
    return true;
    // note deal with movie that has correct genre but incomplete data
}