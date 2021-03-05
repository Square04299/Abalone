#include "color.h"

std::ostream& operator<<(std::ostream &os, const Color &color){
        switch(color)
        {
            case WHITE: os << "white"; break;
            case BLACK: os << "black"; break;
            case NONE:   os << ""     ; break;
        }
        return os;
}
