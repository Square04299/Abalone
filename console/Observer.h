#ifndef OBSERVER_H
#define OBSERVER_H

#include "Observable.h"
#include "View.h"


class Observer : public View
{
    /**
     * @brief m_model what is observed
     */
    Observable& m_model;

public:
    /**
     * @brief Constructor of Observer
     * \param model Logical part of the Game
     */
    Observer(Observable& model);

    /**
     * @brief updateObserver catch the notification of observable, performs an action based on the received parameter
     * @param state A state of the game, depending on the state performs an action
     */
    void updateObserver(State &state);

private:
    void configGame();
    void healthPlayer(std::vector<Player>);
    void displayPlaying(Player);
    std::string convCtoC(Color);
    Color getColor(int,int);
    void displayBoard();
    void displayNextPlayer();
    void move();
    void end();

};

#endif // OBSERVER_H
