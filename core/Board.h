#ifndef BOARD_H
#define BOARD_H

#include "Marble.h"

#include <string>
#include <map>
#include <vector>

class Board
{
private:
    /*!
     * \brief Size of the table.
     */
    static constexpr unsigned SIZE = 9;
    /*!
     * \brief 2D table where all the marble are.
     */
    Marble* m_position[SIZE][SIZE];
    /*!
     * \brief Total amount of marble that can be put on a table.
     */
    unsigned m_nbMarble;
    /*!
     * \brief Convertion map letter to a number.
     */
    std::map<std::string,int> m_convertionMap;

public:
      /*!
     * \brief Constructor of the Board class.
     */
    Board();
    /*!
     * \brief Methode Initialise all the marble on a board to the Color NONE.
     */
    void initMarblePLace();
    /*!
     * \brief Methode Initialise all the black marble on a board to the correct position.
     */
    void initPlaceBlackMarble();
    /*!
     * \brief Methode Initialise all the white marble on a board to the correct position.
     */
    void initPlaceWhiteMarble();
    /*!
     * \brief Methode While move a marble from the X position to the Y position
     * whith the color color.
     * \param String that will tell the initial position.
     * \param String that will tell the final position.
     * \param Color tell if the player can move the initial marble.
     */
    void slideMarble(std::string,std::string,Color);
    /*!
     * \brief Methode While use the map to conver the two value given in the string
     * to find the position of the marble in the board.
     * \param String announces the position.
     */
    void convertStringToHex(std::string);
    /*!
     * \brief  Methode that will tell us if the player can move that marble
     * meaning it must be the same color for the inital move.
     * \param Pair Whith the X and Y of the marble.
     * \param Color tell if the player can move the marble.
     */
    bool isPlayableMarble(std::pair<int,int>,Color);

};

#endif // BOARD_H
