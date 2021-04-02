#ifndef PLAYER_H
#define PLAYER_H

#include "Color.h"


class Player
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
    /*!
     * \brief Constructor of player class
     *
     * \param color the color of the support.
     * \param x is the initial nomber is dead marble needed to win.
     */
    Player(Color color, int x);
    /*!
     * \brief Getter of the value of the nbDeadMarble attribute.
     * \return Interger is equal to 0 will end the game.
     */
    int getDeadMarble();
    /*!
     * \brief Getter of the color attribute.
     * \return color, black or white can't be NONE.
     */
    Color getColor() const;
    /*!
     * \brief Chech what value has m_nbDeadMarble.
     * \return True if the value of m_nbDeadMarble is equal to 0.
     */
    bool isPlayerDead();
    /*!
     * \brief If a marble is outOfBound will remove 1 to the score of the player.
     */
    void removeMarble();
};

#endif // PLAYER_H
