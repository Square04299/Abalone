#include "square.h"

square::square():m_color(Color(NONE)){

}

square::square(position pos, Color color):
    m_isEmpty(true),
    m_pos(pos),
    m_color(color)
{

}

Color square::getColor() const{
    return m_color;
}

bool square::getIsEmpty(){
    return m_isEmpty;
}

position square::getPosition(){
    return m_pos;
}

void square::changePosition(int x, int y, int z){

}


