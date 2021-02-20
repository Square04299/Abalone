#ifndef COLOR_H
#define COLOR_H

#include <iostream>

/*!
 * \brief Énumeration who represents a color that can have a support (white or dark)
 */
enum Color{
    WHITE, BLACK, NONE
};

/*!
 * \brief Method which will print the color in letter
 */
std::ostream& operator<<(std::ostream &os, const Color &color);

#endif // COLOR_H
