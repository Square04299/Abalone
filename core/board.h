#ifndef BOARD_H
#define BOARD_H


class board
{
private:

/   *!
     * \ .
     */
    ;

    /*!
     * \brief Attribute representing the new position.
     */
    Position newPosition;

    /*!
     * \ .
     */
    ;
    /*!
     * \ .
     */
    ;


public:
      /*!
     * \brief Constructor of the board class.
     */
    board();

    /*!
     * \brief method  announces the position the marble on the board.
     * \param String announces the position.
     */
    void calculePosition(String);

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
