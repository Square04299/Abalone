#ifndef SQUARE_H
#define SQUARE_H

#include "color.h"
#include "position.h"

class square
{
private:
    /*!
     * \brief Attribute that tell is the square are a marble or not.
     */
    bool m_isEmpty;
    /*!
     * \brief Attribute representing the position (x,y,z) for the square.
     */
    position m_pos;
    /*!
     * \brief Attribute representing the color of the marble.
     */
    const Color m_color;

public:
    /*!
     * \brief Constructor of the square class.
     */
    square();
    /*!
     * \brief Constructor of the square class with attribute (true for the isEmpty).
     * \param m_pos the position of the square
     * \param m_color the color of the square
     */
    square(position m_pos, Color m_color);
    /*!
     * \brief Getter of the attribute Color.
     */
    Color getColor() const;
    /*!
     * \brief Getter of the attribute isEmpty.
     * \return is the square is empty or not.
     */
    bool getIsEmpty();

    /*!
     * \brief Getter of the attribute isEmpty.
     * \return Class Position.
     */
    position getPosition();
    /*!
     * \brief Change the position of the square if a marble is moved.
     */
    void changePosition(int x, int y, int z);
};

#endif // SQUARE_H
