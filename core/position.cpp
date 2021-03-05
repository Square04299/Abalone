#include "position.h"

position::position(){
    m_x = 0;
    m_y = 0;
    m_z = 0;
}

position::position(int x,int y,int z):
    m_x(x),
    m_y(y),
    m_z(z){
}

int position::getX(){
    return m_x;
}

int position::getY(){
    return m_y;
}

int position::getZ(){
    return m_z;
}

void position::setX(int x){
    m_x = x;
}

void position::setY(int y){
    m_y = y;
}

void position::setZ(int z){
    m_y = z;
}
