#include "square.h"
#include <stdbool.h>

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

void square::setIsEmpty(bool x){
    m_isEmpty = x;
}

void square::setColor(Color x){
    m_color = x;
}

void square::changePosition(int x, int y, int z){
    m_pos.setX(x);
    m_pos.setY(y);
    m_pos.setZ(z);
}


