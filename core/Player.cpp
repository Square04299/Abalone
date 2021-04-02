#include "Player.h"

Player::Player(Color color, int x):
    m_marbleColor(color),
    m_nbDeadMarble(x)
{}

int Player::getDeadMarble(){
    return m_nbDeadMarble;
}

Color Player::getColor() const{
    return m_marbleColor;
}

bool Player::isPlayerDead(){
    return m_nbDeadMarble == 0;
}

void Player::removeMarble(){
    m_nbDeadMarble--;
}
