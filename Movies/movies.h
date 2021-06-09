// ------------------------------------------------ movies.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is a representation of a movie
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>

using namespace std;

#ifndef MOVIES_H
#define MOVIES_H

class Movies {
    public:
    // Setter and Getter functions
    void setStock(int);
    void setDirector(string);
    void setTitle(string);
    void setYear(int);

    int getStock() const;
    string getDirector() const;
    string getTitle() const;
    int getYear() const;

    virtual void toString() const = 0;
    protected:
        // The constructor is protected so it can't be declared
        Movies();

        int stock;
        string title;
        string director;
        int year;
};

#endif