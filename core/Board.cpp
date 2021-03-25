#include "Board.h"
#include <memory>

Board::Board()
{
    //Creation of board 9x9
    initMarblePLace();
    //Creation of the convertion Map
    initMapConvertion();
    //Null Pointer where no marble should excist
    initNullMarble();
}

Board::~Board(){
    for (int i = 0; i< 9 ;i++ ) {
        delete [] &m_board[i];
    }
    delete [] &m_board;
}

void Board::initMarblePLace(){
    for (int i = 1; i < 9 ; i++ ) {
        for (int j = 1;j < 9 ;j++ ) {
            m_board[i][j] = new Marble();
        }
    }
}

void Board::initMapConvertion(){
    m_convertionMap["A"] = 9;
    m_convertionMap["B"] = 8;
    m_convertionMap["C"] = 7;
    m_convertionMap["D"] = 6;
    m_convertionMap["E"] = 5;
    m_convertionMap["F"] = 4;
    m_convertionMap["G"] = 3;
    m_convertionMap["H"] = 2;
    m_convertionMap["I"] = 1;
}

void Board::initNullMarble(){
    int i = 1;
    int j = 4;
    while (i < 4) {
        while (j < 1) {
            m_board[i][j] = nullptr;
            j--;
        }
        j = 4;
        j -= i;
        i++;
    }
    i = 9;
    j = 6;
    int k = 0;
    while (i < 6) {
        while (j < 9) {
            m_board[i][j] = nullptr;
            j++;
        }
        j = 6;
        k++;
        j += k;
        i--;
    }
}

void Board::initPlaceBlackMarble(){
    for (int i = 8; i < 9; i++ ) {
        for (int j = 1; j < 9; j++ ) {
            if (m_board[i][j] != nullptr) {
                m_board[i][j]->setColor(Color(BLACK));
            }
        }
    }
    for (int j = 3; j < 5; j++ ) {
        m_board[7][j]->setColor(Color(BLACK));
    }
}

void Board::initPlaceWhiteMarble(){
    for (int i = 1; i < 2; i++ ) {
        for (int j = 1; j < 9; j++ ) {
            if (m_board[i][j] != nullptr) {
                m_board[i][j]->setColor(Color(WHITE));
            }
        }
    }
    for (int j = 5; j < 7; j++ ) {
        m_board[3][j]->setColor(Color(WHITE));
    }
}

void Board::slideMarble(std::string, std::string, Color){

}

void Board::convertStringToHex(std::string){

}

bool Board::isPlayableMarble(std::pair<int, int>, Color){
    return true;
}
