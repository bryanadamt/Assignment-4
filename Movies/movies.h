// ------------------------------------------------ movies.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a movie
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>

using namespace std;

#ifndef MOVIES_H
#define MOVIES_H

class Movies {
    public:


    protected:
        // The constructor is protected so it can't be declared
        Movies();

        int stock;
        string title;
        string director;
        int year;
};

#endif