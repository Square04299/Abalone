#include "State.h"


std::ostream& operator<<(std::ostream &os, const State &state){
        switch(state)
        {
            case CONFIG: os << "CONFIG"; break;
            case MOVE: os << "MOVE"; break;
            case NEXTPLAYER: os << "NEXTPLAYER"; break;
            case OVER:   os << "OVER"; break;
        }
        return os;
}
