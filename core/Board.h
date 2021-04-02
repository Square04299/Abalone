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
    static constexpr unsigned SIZE = 11;
    /*!
     * \brief 2D table where all the marble are.
     */
    Marble* m_board[SIZE][SIZE];
    /*!
     * \brief Convertion map MAJ letter to a number.
     */
    std::map<std::string,int> m_convertionMap;

    std::vector<bool> m_configConfirmation;

public:
      /*!
     * \brief Constructor of the Board class.
     */
    Board();
    /*!
   * \brief Destructor of the Board class.
   */
    void clear();
    /*!
     * \brief Methode Initialise all the marble on a board to the Color NONE.
     */
    bool initMarblePLace();
    /*!
     * \brief Methode Initialise the conversion map.
     */
    bool initMapConvertion();
    /*!
     * \brief Methode Initialise all the empty to NULL POINTER.
     */
    bool initNullMarble();
    /*!
     * \brief Methode Initialise all the black marble on a board to the correct position.
     */
    bool initPlaceBlackMarble();
    /*!
     * \brief Methode Initialise all the white marble on a board to the correct position.
     */
    bool initPlaceWhiteMarble();
    /*!
     * \brief isSetUp Will add in a vector each time a board operation for the set up
     * is completed
     * \return True if all the value in the vector is true;
     */
    bool isSetUp();
    /*!
     * \brief Methode While move a marble from the X position to the Y position
     * whith the color color.
     * \param String that will tell the initial position.
     * \param String that will tell the final position.
     * \param Color tell if the player can move the initial marble.
     */
    Color slideOneMarble(const std::string &, const std::string &, Color);
    /*!
     * \brief Methode While look if the two marble aren't to far from each other.
     * \param int Difference between initial X and final X.
     * \param int Difference between initial Y and final Y.
     */
    bool diffMarble(const int, const int);
    /*!
     * \brief Methode While be call if you need to move multiple marble.
     * \param Pair<int><int> that will tell the initial position.
     * \param Pair<int,int> that will tell the final position.
     */
    Color slideMultipleMarble(std::pair<int,int>, std::pair<int,int>, const int, const int);
    /*!
     * \brief Methode While use the map to conver the two value given in the string
     * to find the position of the marble in the board.
     * \param String announces the position.
     */
    std::pair<int,int> convertStringToHex(std::string);
    /*!
     * \brief  Methode that will tell us if the player can move that marble
     * meaning it must be the same color for the inital move.
     * \param Pair Whith the X and Y of the marble.
     * \param Color tell if the player can move the marble.
     */
    bool isPlayableMarble(std::vector<Color>);
    /*!
     * \brief getLineColor
     * \return Vectore return 1 line of the Board
     */
    std::vector<Color> getLineColor(int);

};

#endif // BOARD_H
