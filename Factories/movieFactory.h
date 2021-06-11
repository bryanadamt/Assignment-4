// ------------------------------------------------ movieFactory.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - class used to make different genres of movie
// --------------------------------------------------------------------------------------------------------------------

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "../Movies/classics.h"
#include "../Movies/comedy.h"
#include "../Movies/drama.h"
#include <iostream>
#include <sstream>

using namespace std;

class MovieFactory {
    public:
        // Assign movie that was read from the file to one of the genres
        Movies* movieMaker(stringstream&);
        Movies* movieMaker(char, stringstream&);
};

#endif