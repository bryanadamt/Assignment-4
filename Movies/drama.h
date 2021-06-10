// ------------------------------------------------ drama.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a drama movie
// --------------------------------------------------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H

#include "movies.h"

using namespace std;

class Drama : public Movies {
    public:
        // Constructor
        Drama(char, int, string, string, int);
        // Destructor
        ~Drama();

        // Operators
        bool operator==(const Movies&);
        bool operator>(const Movies&);
        bool operator<(const Movies&);

        // Print out
        void toString() const;
};

#endif