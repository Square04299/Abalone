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
    View::displayStr("Placing Marble on Board ...\n");

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
  D + + + + + + + + 8
   C + + @ @ @ + + 7
    B @ @ @ @ @ @ 6
     A @ @ @ @ @ 5
        0 1 2 3 4
        G4 F3
        I5 I4

*/
/* Must do
 * i 5 i 4 a 1 a 0 h 4 h 3 b 4 b 5 h 7 h 8 //BLACK WIN
 * i 8 h 7 a 0 b 1 h 7 g 6 b 1 c 2 //Breaks
*/
void Observer::displayBoard(){
    View::displayStr("Board incoming ...");
}


void Observer::move(){
    View::displayStr("===== Moving Marble =====");
    View::displayStr("What position would you like to move your marble too ?");
    std::string m1 = askCoord("for your first Marble");
    std::string m2 = askCoord("to where your marble needs to go");
            std::cout << "Start : " << m1 << std::endl;
            std::cout << "Finish : " << m2 << std::endl;
    m_model.moveMarble(m1,m2);
}
void Observer::end(){
    const Player &winner = m_model.end();
    Color win = winner.getColor();
    View::title();
    View::displayWinner("Congratulation ", " player you won the game",win);
}
