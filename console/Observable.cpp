#include "Observable.h"
#include "Observer.h"

Observable::Observable():
    Game()
{
}

void Observable::attachObserver(Observer &view){
    m_observers.push_back(&view);
}

void Observable::notifyObservers(State state){
    for (auto var : m_observers) {
       var->updateObserver(state);
    }
}

void Observable::run(){
    notifyObservers(Game::getState());
    Game::startGame();
    while (Game::getState() != OVER) {
        notifyObservers(Game::getState());
    }
    notifyObservers(Game::getState());
}
