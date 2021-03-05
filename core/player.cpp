#include "player.h"

player::player(): m_marbleColor(Color(NONE)){
    throw "Player can't be the color NONE";
}

player::player(Color color, int x):
    m_marbleColor(color),
    m_nbDeadMarble(x)
{

}

int player::getDeadMarble(){
    return m_nbDeadMarble;
}

Color player::getColor(){
    return m_marbleColor;
}
