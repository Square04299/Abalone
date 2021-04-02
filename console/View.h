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
public:
    View();
    void title() const;
    void displayWinner(std::string const& , std::string const &, Color) const;
    void displayStr(std::string const &);
    void displayStrC(const std::string &, Color);
    std::string askCoord(const std::string &);
    void rules();
    bool alphabet(char);
    bool numberV(unsigned);
    char toUpperCase(char);
};

#endif // VIEW_H
