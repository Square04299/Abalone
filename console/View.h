#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits>


#include "Color.h"

class View
{
    std::string whiteChar = "@";
    std::string blackChar = "O";
    std::string noneChar = "+";
public:
    View();
    void title() const;
    void displayWinner(std::string, std::string, Color) const;
    void displayStr(std::string);
    void displayStrC(std::string, Color);
    std::string askCoord(std::string);
    void rules();
    bool alphabet(char);
    bool numberV(unsigned);
    char toUpperCase(char);
};

#endif // VIEW_H
