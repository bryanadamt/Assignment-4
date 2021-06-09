// ------------------------------------------------ classics.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a classic movie
// --------------------------------------------------------------------------------------------------------------------

#ifndef CLASSICS_H
#define CLASSICS_H

#include "movies.h"

using namespace std;

class Classics : public Movies {
    public:
        // Constructor
        Classics(int, string, string, string, int, int);

        // Destructor
        ~Classics();

        // Setter and Getter
        void setMonth(int);
        void setMActor(string);

        int getMonth() const;
        string getMActor() const;

        // Print out
        void toString() const;
    private:
        // month of release
        int month;
        // major actor full name
        string mActor;
};

#endif