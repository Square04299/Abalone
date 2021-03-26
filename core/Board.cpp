#include "Board.h"

#include <memory>
#include <stdexcept>

Board::Board()
{
    //Creation of board 9x9
    initMarblePLace();
    //Creation of the convertion Map
    initMapConvertion();
    //Null Pointer where no marble should excist
    initNullMarble();
    //Place all black marble
    initPlaceBlackMarble();
    //Place all white marble
    initPlaceWhiteMarble();
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

void Board::slideOneMarble(std::string a, std::string b, Color color){
    auto const initial = convertStringToHex(a);
    auto const final = convertStringToHex(b);

    int iX = initial.first,
        iY = initial.second,
        fX = final.first,
        fY = final.second;
    int const diffX = fX - iX;
    int const diffY = fY - iY;

    if (m_board[iX][iY]->getColor() == color) {
        if (diffMarble(diffX,diffY)) {
            if (m_board[fX][fY]->getColor() != Color(NONE)) {
                slideMultipleMarble(initial,final,diffX,diffY);
            }else {
                m_board[iX][iY]->setColor(Color(NONE));
                m_board[fX][fY]->setColor(color);
            }
        }else {
            throw std::invalid_argument("The two marble are too far from each other");
        }
    }else{
        throw std::invalid_argument("The Marble you are trying to move isn't yours");
    }

}

bool Board::diffMarble(int const diffX, int const diffY){
    int validNB[3] = {-1,0,1};
    bool tempX,tempY;
    if (diffX != diffY) {
        for (int value : validNB) {
            if (diffX == value) {
                tempX = true;
            }
            if (diffY == value) {
                tempY = true;
            }
        }
        if (tempX && tempY) {
            return true;
        }
    }
    return false;
}

void Board::slideMultipleMarble(std::pair<int,int> x, std::pair<int,int>y
                                , int const diffX, const int diffY){
    //Liste of all marble in the path
    //Look for the Majority
    //Change all the marble according to the list

    int tempX = x.first;
    int tempY = x.second;
    int limitX = 0;
    int limitY = 0;
    std::vector<Color> listColor;

    while ((1 < tempX && tempX < 9) || (1 < tempY && tempY < 9)) {
        listColor.push_back(m_board[tempX+limitX][tempY+limitY]->getColor());
        tempX += diffX;
        tempY += diffY;
        limitX = diffX;
        limitY = diffY;
    }
    int temp2X = y.first;
    int temp2Y = y.second;
    limitX = 0;
    limitY = 0;
    if (isPlayableMarble(listColor)) {
        //Change initial to none
        //for vector size
        //set final to none color in vector
        m_board[tempX][tempY]->setColor(Color(NONE));
        for (Color var : listColor) {
            if (var != Color(NONE)) {
                m_board[temp2X+limitX][temp2Y+limitY]->setColor(var);
                temp2X += diffX;
                temp2Y += diffY;
                limitX = diffX;
                limitY = diffY;
            }
            break;
        }
    }

}

std::pair<int,int> Board::convertStringToHex(std::string a){
    std::string str1 = a.substr(0,1);
    std::string str2 = &a[1];
    int i1 = m_convertionMap.at(str1);
    int i2 = std::atoi(str2.c_str());
    return std::make_pair(i1,i2);
}

bool Board::isPlayableMarble(std::vector<Color> vectorColor){
    int countBlack = 0;
    int countWhite = 0;
    Color precedant = Color(NONE);
    bool change = false;
    bool alreadyChange = false;

    for (Color var : vectorColor) {
        if (var == Color(NONE)) {
            break;
        }
        if (var == Color(BLACK)) {
            if (!change && !alreadyChange) {
                if (var == precedant || var != Color(NONE)) {
                    precedant = Color(BLACK);
                    countBlack ++;
                }else {
                    if (change) {
                        alreadyChange = true;
                        return false;
                    }
                    precedant = Color(BLACK);
                    change = true;
                    countBlack ++;
                }

            }
        }
        if (var == Color(WHITE)) {
            if (!change && !alreadyChange) {
                if (var == precedant || var != Color(NONE)) {
                    precedant = Color(WHITE);
                    countWhite ++;
                }else {
                    if (change) {
                        alreadyChange = true;
                        return false;
                    }
                    precedant = Color(WHITE);
                    change = true;
                    countWhite ++;
                }

            }
        }
    }
    int res = 0;
    if (vectorColor[0] == Color(BLACK)) {
        res = countBlack - countWhite;
        if (res > 3) {
            return false;
        }
    }
    if (vectorColor[0] == Color(WHITE)) {
        res = countWhite - countBlack;
        if (res > 3) {
            return false;
        }
    }

    return (res = 1) ? true : false;
}

