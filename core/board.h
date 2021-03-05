#ifndef BOARD_H
#define BOARD_H

#include "position.h"
#include "square.h"

#include <string>
#include <map>
#include <vector>

class board
{
private:

    /*!
     * \ .
     */
     std::map<std::string, square> Board;

    /*!
     * \brief Attribute representing the new position.
     */
    position newPosition;

    /*!
     * \ .
     */
    std::map<std::string, int> calCoordonnée;
    /*!
     * \ .
     */
    std::vector<square> nextMove;


public:
      /*!
     * \brief Constructor of the board class.
     */
    board();

    /*!
     * \brief method  announces the position the marble on the board.
     * \param String announces the position.
     */
    void calculePosition(std::string);

    /*!
     * \brief method that add the marble in the board
     */
    void addMarble();

    /*!
     * \brief method that remove the marble in the board
     */
    void removeMarble();

    /*!
     * \brief method that tells if the move is allowed or not.
     */
    void legalMove();

};

#endif // BOARD_H
