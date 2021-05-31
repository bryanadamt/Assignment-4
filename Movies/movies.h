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
        // Setter and Getter functions
        void setStock(int);
        void setDirector(string);
        void setYear(int);

        int getStock() const;
        string getDirector() const;
        int getYear() const;
    private:
        int stock;
        string director;
        int year;
}

#endif