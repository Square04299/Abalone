#ifndef PLAYER_H
#define PLAYER_H

#include "color.h"


class player
{
private:
    /*!
     * \brief Attribute representing the color of the square.
     */
    const Color m_marbleColor;

    /*!
     * \brief Attribute will say how many marble are down.
     * \result Interger that if is = to 0 will end the game.
     */
    int m_nbDeadMarble;
public:
    player();
    /*!
     * \brief Constructor of player class
     *
     * \param color the color of the support.
     * \param x is the initial nomber is dead marble needed to win.
     */
    player(Color color, int x);
    /*!
     * \brief Getter of the value of the nbDeadMarble attribute.
     * \return Interger is equal to 0 will end the game.
     */
    int getDeadMarble();
    /*!
     * \brief Getter of the color attribute.
     * \return color, black or white can't be NONE.
     */
    Color getColor();
};

#endif // PLAYER_H
