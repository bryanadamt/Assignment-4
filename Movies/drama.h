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
        Drama(int, string, string, int);
        // Destructor
        ~Drama();

        // Print out
        void toString(ostream& stream) const;
};

#endif