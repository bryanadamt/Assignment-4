// ------------------------------------------------ classics.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a classic movie
// --------------------------------------------------------------------------------------------------------------------

#ifndef CLASSICS_H
#define CLASSICS_H

#include "../Movies/movies.h"

using namespace std;

class Classics {
    public:

        // Setter and Getter functions
        void setMonth(int);
        void setMActor(string);

        int getMonth();
        string getMActor();
    private:
        // month of release
        int month;
        // major actor full name
        string majorActor;
}

#endif