#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "State.h"
#include "Player.h"

#include <vector>

class Game
{
private:
    /*!
     * \brief Attribute representing the status of the game
     */
    board m_board;
    /*!
     * \brief Attribute representing the stat of the game.
     */
    State m_state;
    /*!
     * \brief Attribute representing the Player 1 and 2.
     */
    std::vector<player*> m_player;
     /*!
     * \brief Attribute representing the current Player of the game.
     */
    player* m_currentPlayer;


public:

     /*!
     * \brief Constructor of the game class.
     */
    game();

     /*!
     * \brief method that announces the start of the game.
     */
    void startGame();

    /*!
     * \brief method that innitialise the game.
     */
    void intGame();

    /*!
     * \brief method that announces the end of the game.
     */
    void endGame();

    /*!
     * \brief method that announces the end of the game.
     * \return the winner of the game therefore the status of the game.
     */
    void isOver();

    /*!
     * \brief method representing the next Player of the game.
     */

    void nextPlayer();
    /*!
     * \brief method that moves the marble.
     * \param m_posInitial the position initiale of the board.
     * \param m_posFinal the position final of the board.
     */
    void moveMarble(std::string m_posInitial, std::string m_posFinal);

};

#endif // GAME_H
