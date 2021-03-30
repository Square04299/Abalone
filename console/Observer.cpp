#include "Observer.h"

Observer::Observer(Observable& model) :
    View(),
    m_model(model)
{}

void Observer::updateObserver(State &state){
    switch (state) {
    case CONFIG:
        configGame();
        displayBoard();
        break;
    case MOVE:
        healthPlayer(m_model.getPlayers());
        displayPlaying(m_model.getCurrent());
        move();
        break;
    case NEXTPLAYER:
        displayBoard();
        displayNextPlayer();
        break;
    case OVER:
        end();
        break;
    }
}

void Observer::configGame(){
    View::title();
    View::displayStr("Placement des billes ...\n");

}

void Observer::healthPlayer(std::vector<Player> players){
    View::displayStr(std::to_string(players[0].getDeadMarble()) +" Marble left for WHITE before Losing");
    View::displayStr(std::to_string(players[1].getDeadMarble()) +" Marble left for BLACK before Losing");
}

void Observer::displayPlaying(Player p){
    View::displayStrC(" : isplayer",p.getColor());
}

void Observer::displayNextPlayer(){
    View::displayStr("Turn ended ... Next Player\n");
    m_model.nextPlayer();
}

char Observer::convCtoC(Color c){
    switch (c) {
    case WHITE:
        return 'O';
        break;
    case BLACK:
        return '@';
        break;
    case NONE:
        return '+';
        break;
    default:
        return ' ';
        break;
    }
}

/*
     I O O O O O
    H O O O O O O
   G + + O O O + +
  F + + + + + + + +
 E + + + + + + + + +
  D + + + + + + + + 9
   C + + @ @ @ + + 8
    B @ @ @ @ @ @ 7
     A @ @ @ @ @ 6
        1 2 3 4 5
*/

void Observer::displayBoard(){
View::displayStr("Board incoming ...");
}


void Observer::move(){
    View::displayStr("===== Moving Marble =====");
    View::displayStr("What position would you like to move your marble too ?");
    std::string m1 = askCoord("depart");
    std::string m2 = askCoord("arrivee");
    m_model.moveMarble(m1,m2);
}
void Observer::end(){
    const Player &winner = m_model.end();
    View::title();
    View::displayWinner("Congratulation ", " player you won the game",winner.getColor());
}
