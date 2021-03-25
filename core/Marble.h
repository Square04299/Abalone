#ifndef SQUARE_H
#define SQUARE_H

#include "Color.h"

class Marble
{
private:
    /*!
     * \brief Attribute representing the color of the marble.
     */
    Color m_color;

public:
    /*!
     * \brief Constructor of the square class.
     */
    Marble();
    /*!
     * \brief Getter of the attribute Color.
     */
    Color getColor() const;
    /*!
     * \brief Setter of the attribute Color.
     */
    void setColor(Color color);

};

#endif // SQUARE_H
