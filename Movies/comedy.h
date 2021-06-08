// ------------------------------------------------ comedy.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a comedy movie
// --------------------------------------------------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include "movies.h"

using namespace std;

class Comedy : public Movies {
    public:
        // Constructor
        Comedy(int, string, string, int);
        // Destructor
        ~Comedy();
};

#endif