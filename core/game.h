#ifndef GAME_H
#define GAME_H


class game
{
private:
    /*!
     * \brief Attribute representing the status of the game
     */
    Board board;
    /*!
     * \brief Attribute representing the stat of the game.
     */
    State state;
    /*!
     * \brief Attribute representing the Player 1 and 2.
     */
    Player(m_player1, m_player2);
     /*!
     * \brief Attribute representing the current Player of the game.
     */
    Player(currentPlayer);


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
    moveMarble(String m_posInitial, Sting m_posFinal);

};

#endif // GAME_H
