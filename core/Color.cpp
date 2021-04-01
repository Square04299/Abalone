#include "Color.h"

std::ostream& operator<<(std::ostream &os, const Color &color){
        switch(color)
        {
            case WHITE: os << "white"; break;
            case BLACK: os << "black"; break;
            case NONE:   os << ""     ; break;
            case OUT:   os << "Not on the Board"     ; break;
        }
        return os;
}
