#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Game.h"
#include <vector>

class Observer;

class Observable : public Game
{
    /**
    * @brief m_observer his observers
    */
    std::vector<Observer*> m_observers;

public:
    /**
     * @brief Observable constructor
     */
    Observable();
    /**
    * @brief attachObserver Attaches an observer to the model.
    * @param view The observer to attach.
    */
    void attachObserver(Observer &view);
    /**
    * @brief notifyObservers Notifies each observer of the model of a card change.
    * @param step The new state of the game.
    */
    void notifyObservers(State state);
    /**
    * @brief run notify all observers when an action occurs in the model, ends when the game step is end
    */
    void run();
};

#endif // OBSERVABLE_H
