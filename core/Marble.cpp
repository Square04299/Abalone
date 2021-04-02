#include "Marble.h"
#include <stdbool.h>


Marble::Marble():m_color(Color(NONE)){

}

Color Marble::getColor() const{
    return m_color;
}

void Marble::setColor(Color x){
    m_color = x;
}



