// ------------------------------------------------ borrow.cpp -----------------------------------------------------
// Bryan Adam Tjendra, Ayumi Oishi, CSS 343B
// Created: 8/6/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - The class is a representation of a borrow function
// --------------------------------------------------------------------------------------------------------------------

#include "borrow.h"
#include <iostream>

using namespace std;

//---------------------------- getString() --------------------------------
string Borrow::getString() const {

    return "Borrowed " + movieTitle + ".";

}
