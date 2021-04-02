#ifndef STATE_H
#define STATE_H
#include <iostream>


/*!
 * \brief Énumeration who represents the state of the game
 * \arg config, time foe the game to set up the board and the marble.
 * \arg turnwhite, only white piece can be moved by the white player
 * (exept the one moved but pushing the opponent color).
 * \arg turnblack, only black piece can be moved by the black player
 * (exept the one moved but pushing the opponent color).
 * \arg over, will stop any move after this state has been activated and the winner screen
 * will show up.
 */
enum State{
    CONFIG, MOVE, NEXTPLAYER ,OVER
};

/*!
 * \brief Method which will print the color in letter
 */
std::ostream& operator<<(std::ostream &os, const State &state);

#endif // STATE_H
