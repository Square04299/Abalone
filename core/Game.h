#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "State.h"
#include "Player.h"

#include <vector>
#include <memory>

class Game
{
private:
    /*!
     * \brief Attribute representing the status of the game
     */
    Board m_board;
    /*!
     * \brief Attribute representing the stat of the game.
     */
    State m_state;
    /*!
     * \brief Attribute representing the Player 1 and 2.
     */
    std::vector<Player> m_players;
     /*!
     * \brief Attribute representing the current Player of the game.
     */
    unsigned m_currentPlayer;


public:

     /*!
     * \brief Constructor of the game class.
     */
    Game();
     /*!
     * \brief method that announces the start of the game.
     * Verify if all the condition are met to start playing the game.
     */
    void startGame();
    /*!
    * \brief method that will annouces if the game is ready to start.
    * \return true, if everyting is ready.
    */
    bool isReady();
    /*!
     * \brief brief isGameOver check if all conditions are completed to end game.
     * the game is over if a player losses 3 marble.
     * \return the winner if game is over, nullptr else.
     */
    const Player * isGameOver();
    /*!
     * \brief end finish the game.
     * \return the winner player.
     * \throw logic_error if the game isn't end step.
     * \throw runtime_error if there is no winner.
     */
    const Player &end();
    /*!
     * \brief method representing the next Player of the game.
     */
    void nextPlayer();
    /*!
     * \brief method representing the next Player of the game.
     */
    void moveMarble(std::string, std::string);
    /*!
     * \brief getBoard
     * \return the board of the game
     */
    Board& getBoard();
    /*!
     * \brief getBoardLine
     * \return Vector return 1 line of the board
     */
    std::vector<Color> getBoardLine(int);
    /*!
     * \brief getState
     * \return the game state in progress
     */
    State getState();
    /*!
     * \brief getPlayers
     * \return the list of players
     */
    std::vector<Player> getPlayers();
    /*!
     * \brief getCurrent
     * \return the current player playing
     */
    Player getCurrent();

};

#endif // GAME_H
