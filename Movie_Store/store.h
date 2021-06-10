// ------------------------------------------------ store.h -------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 30/5/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This class is to represent the movie rental store 
// It combines all other classes together
// --------------------------------------------------------------------------------------------------------------------

#include "../Movies/classics.h"
#include "../Movies/comedy.h"
#include "../Movies/drama.h"
#include "../Factories/movieFactory.h"
#include "../Data_Structures/bstree.h"

#ifndef STORE_H
#define STORE_H

class Store {
    public:
        // Read the entire movie file
        void readMovieData(ifstream&);
    private:
        // Queue transactions;
        BSTree classics;
        BSTree comedy;
        BSTree drama;
        MovieFactory mFactory;
};
#endif