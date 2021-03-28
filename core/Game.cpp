#include "Game.h"

Game::Game():
    m_board(Board()),
    m_state(State::CONFIG),
    m_players(std::vector<Player>()),
    m_currentPlayer(0)
{
}


void Game::startGame(){
    if (m_state != CONFIG) {
        throw std::logic_error("The game don't be configured if the step isn't CONFIG.");
    }
    if(m_players.size()!=2) {
            throw std::logic_error("To start a game, you need at least two players");
        }
    if (!(m_board.isSetUp())) {
        throw std::logic_error("The Game configuration had a problem \n"
                               "Restart the Game");
    }
    m_state = MOVE;
}

const Player * Game::isGameOver(){
    const Player *winner = nullptr;
    for (Player & var : m_players) {
        if (var.getDeadMarble() == 0) {
            winner = &var;
            m_state = OVER;
        }
    }
    return winner;
}

const Player &Game::end(){
    if (m_state!=OVER) {
        throw std::logic_error("The game can't stop now !");
    }
    const Player *winner = isGameOver();
    if (winner == nullptr) {
        throw std::runtime_error("There is no winner for the moment");
    }
    return *winner;
}

void Game::nextPlayer(){
    if (m_state != NEXTPLAYER) {
        throw std::logic_error("You can't Change player you aren't in the right state");
    }
    m_currentPlayer++;
    if (m_currentPlayer >= m_players.size()) {
        m_currentPlayer = 0;
    }
    m_state = MOVE;
}

void Game::moveMarble(std::string iXY, std::string fXY, Color color){
    if (m_state != MOVE) {
        throw std::logic_error("The Game hasn't finished the previous task \n"
                               "Finish the previous request before moving a Marble");
    }
    Color marbleToRemove = m_board.slideOneMarble(iXY, fXY, color);
    for (Player var : m_players) {
        if (var.getColor() == marbleToRemove) {
            var.removeMarble();
        }
    }
    m_state = NEXTPLAYER;
}
