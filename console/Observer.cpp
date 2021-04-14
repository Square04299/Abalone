#include "Observer.h"

Observer::Observer(Observable& model) :
    View(),
    m_model(model)
{}

void Observer::updateObserver(const State &state){
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
        m_model.clearPlayer();
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
    if (p.getColor() == WHITE) {
        View::displayStrC(" turn, white has the O character",p.getColor());
    }else {
        View::displayStrC(" turn, black has the @ character",p.getColor());
    }
}

void Observer::displayNextPlayer(){
    View::displayStr("Turn ended ... Next Player\n");
    m_model.nextPlayer();
}

std::string Observer::convCtoC(Color c){
    switch (c) {
    case WHITE:
        return " O";
        break;
    case BLACK:
        return " @";
        break;
    case NONE:
        return " +";
        break;
    default:
        return "";
        break;
    }
}

/*
     I O O + O +
    H O O + O + O
   G + + O O O + +
  F + + O + O + + +
 E + + O @ O + + + +
  D + + + @ + @ + + 9
   C + + @ @ @ + + 8
    B @ @ @ + @ + 7
     A @ @ @ + @ 6
        1 2 3 4 5
        G4 F3
        I5 I4

*/
/* Must do
 * i 6 i 5 a 2 a 1 h 5 h 4 b 5 b 6 h 8 h 9 //BLACK WIN
 * i 9 h 8 a 1 b 2 h 8 g 7 b 2 c 3 //Breaks
 * i 7 h 6 a 4 b 4 h 6 g 5 b 4 c 4 i 9 h 8 b 6 c 6 h 8 g 7 c 6 d 6 e 3 e 5 //Logic error
*/
void Observer::displayBoard(){
    View::displayStr("Board incoming ...");
    std::vector<Color> b1,b2,b3,b4,b5,b6,b7,b8,b9;
    b1 = m_model.getBoardLine(1);
    b2 = m_model.getBoardLine(2);
    b3 = m_model.getBoardLine(3);
    b4 = m_model.getBoardLine(4);
    b5 = m_model.getBoardLine(5);
    b6 = m_model.getBoardLine(6);
    b7 = m_model.getBoardLine(7);
    b8 = m_model.getBoardLine(8);
    b9 = m_model.getBoardLine(9);


    std::cout << "     I";
    for (Color var : b1) {
       std::cout << convCtoC(var);
    }
    std::cout << std::endl;


    std::cout << "    H";
    for (Color var : b2) {
       std::cout << convCtoC(var);
    }
    std::cout << std::endl;


    std::cout << "   G";
    for (Color var : b3) {
       std::cout << convCtoC(var);
    }
    std::cout << std::endl;


    std::cout << "  F";
    for (Color var : b4) {
       std::cout << convCtoC(var);
    }
    std::cout << std::endl;


    std::cout << " E";
    for (Color var : b5) {
       std::cout << convCtoC(var);
    }
    std::cout << std::endl;


    std::cout << "  D";
    for (Color var : b6) {
       std::cout << convCtoC(var);
    }
    std::cout <<" 9" <<std::endl;


    std::cout << "   C";
    for (Color var : b7) {
       std::cout << convCtoC(var);
    }
    std::cout <<" 8" <<std::endl;


    std::cout << "    B";
    for (Color var : b8) {
       std::cout << convCtoC(var);
    }
    std::cout <<" 7" <<std::endl;


    std::cout << "     A";
    for (Color var : b9) {
       std::cout << convCtoC(var);
    }
    std::cout <<" 6" <<std::endl;


    std::cout << "        1";
    for (int i = 2; i < 6; i++) {
        std::cout << " " << i;
    }
    std::cout << std::endl;

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
