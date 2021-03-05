#include "state.h"


std::ostream& operator<<(std::ostream &os, const State &state){
        switch(state)
        {
            case CONFIG: os << "CONFIG"; break;
            case TURNBLACK: os << "TURNBLACK"; break;
            case TURNWHITE:   os << "TURNWHITE"; break;
            case OVER:   os << "OVER"; break;
        }
        return os;
}
