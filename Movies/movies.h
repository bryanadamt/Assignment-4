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

// Check for movies that are the same, like same title but different actor
// etc. and then connect them both so if one of them is searched,
// both of them will change. They both point to the same thing.

class Movies {
    public:
    // Setter and Getter functions
    void setGenre(char);
    void setStock(int);
    void setDirector(string);
    void setTitle(string);
    void setYear(int);

    char getGenre() const;
    int getStock() const;
    string getDirector() const;
    string getTitle() const;
    int getYear() const;

    // Operators
    virtual bool operator==(const Movies&) const = 0;
    virtual bool operator>(const Movies&) const = 0;
    virtual bool operator<(const Movies&) const = 0;

    virtual void toString() const = 0;
    protected:
        // The constructor is protected so it can't be declared
        Movies();

        char genre;
        int stock;
        string title;
        string director;
        int year;
};

#endif