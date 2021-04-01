#include "Board.h"

#include <memory>
#include <stdexcept>

Board::Board():
    m_configConfirmation(std::vector<bool>())
{
    //Creation of board 9x9
    m_configConfirmation.push_back(initMarblePLace());
    //Creation of the convertion Map
    m_configConfirmation.push_back(initMapConvertion());
    //Null Pointer where no marble should excist
    m_configConfirmation.push_back(initNullMarble());
    //Place all black marble
    m_configConfirmation.push_back(initPlaceBlackMarble());
    //Place all white marble
    m_configConfirmation.push_back(initPlaceWhiteMarble());
}

Board::~Board(){
    for (int i = 0; i < 9; i++){
        delete[] & m_board[i];
    }
    std::cout << "Deleting Board /!\\ " << std::endl;
    delete[] & m_board;
}

bool Board::initMarblePLace(){
    bool validate = false;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            m_board[i][j] = new Marble();
            validate = true;
        }
    }
    return validate;
}

bool Board::initMapConvertion(){
    m_convertionMap["A"] = 8;
    m_convertionMap["B"] = 7;
    m_convertionMap["C"] = 6;
    m_convertionMap["D"] = 5;
    m_convertionMap["E"] = 4;
    m_convertionMap["F"] = 3;
    m_convertionMap["G"] = 2;
    m_convertionMap["H"] = 1;
    m_convertionMap["I"] = 0;
    return true;
}

bool Board::initNullMarble(){
    for (int i=0;i<4 ;i++ ) {
        m_board[0][i]->setColor(Color::OUT);
    }
    for (int i=0;i<3 ;i++ ) {
        m_board[1][i]->setColor(Color::OUT);
    }
    for (int i=0;i<2 ;i++ ) {
        m_board[2][i]->setColor(Color::OUT);
    }
    m_board[3][0]->setColor(Color::OUT);
    m_board[5][8]->setColor(Color::OUT);
    for (int i=7;i<9 ;i++ ) {
        m_board[6][i]->setColor(Color::OUT);
    }
    for (int i=6;i<9 ;i++ ) {
        m_board[7][i]->setColor(Color::OUT);
    }
    for (int i=5;i<9 ;i++ ) {
        m_board[8][i]->setColor(Color::OUT);
    }
    return ((m_board[1][2]->getColor() == Color::OUT) && (m_board[8][6]->getColor() == Color::OUT))? true:false;
}

bool Board::initPlaceBlackMarble(){
    bool v1 = false;
    bool v2 = false;
    for (int i = 7; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (m_board[i][j]->getColor() != Color::OUT){
                m_board[i][j]->setColor(Color::BLACK);
                v1= true;
            }
        }
    }
    for (int j = 2; j < 5; j++){
        m_board[6][j]->setColor(Color::BLACK);
        v2 = true;
    }
    return v1 = (v2 == true);
}

bool Board::initPlaceWhiteMarble(){
    bool v1 = false;
    bool v2 = false;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 9; j++){
            if (m_board[i][j]->getColor() != Color::OUT){
                m_board[i][j]->setColor(Color::WHITE);
                v1= true;
            }
        }
    }
    for (int j = 4; j < 7; j++){
        m_board[2][j]->setColor(Color::WHITE);
        v2 = true;
    }
    return v1 = (v2 == true);
}

bool Board::isSetUp(){
    int i = 0;
    for (bool var : m_configConfirmation) {
        if (var == true) {
            i++;
        }
    }
    return (i = m_configConfirmation.size()) ? true:false;
}

std::vector<Color> Board::getLineColor(int x){
    std::vector<Color> line;
    for (int i =0 ; i < 9; i++) {
        line.push_back(m_board[x][i]->getColor());
    }
    return line;
}

Color Board::slideOneMarble(std::string a, std::string b, Color color){
    auto const initial = convertStringToHex(a);
    auto const final = convertStringToHex(b);

    Color losingMarble = Color::NONE;

    int iX = initial.first,
        iY = initial.second,
        fX = final.first,
        fY = final.second;
    int const diffX = fX - iX;
    int const diffY = fY - iY;

    if (m_board[iX][iY]->getColor() == color){
        if (diffMarble(diffX, diffY)){
            if (m_board[fX][fY]->getColor() != Color::NONE) {
                losingMarble = slideMultipleMarble(initial, final, diffX, diffY);
            }else{
                m_board[iX][iY]->setColor(Color::NONE);
                m_board[fX][fY]->setColor(color);
            }
        }else{
            throw std::invalid_argument("The two marble are too far from each other");
        }
    }else{
        throw std::invalid_argument("The Marble you are trying to move isn't yours");
    }
    return losingMarble;
}

bool Board::diffMarble(int const diffX, int const diffY){
    int validNB[3] = {-1, 0, 1};
    bool tempX, tempY;
    if (diffX != diffY){
        for (int value : validNB){
            if (diffX == value){
                tempX = true;
            }
            if (diffY == value){
                tempY = true;
            }
        }
        if (tempX && tempY){
            return true;
        }
    }
    return false;
}

Color Board::slideMultipleMarble(std::pair<int, int> x, std::pair<int, int> y, int const diffX, const int diffY){
    //Liste of all marble in the path
    //Look for the Majority
    //Change all the marble according to the list

    int tempIX = x.first;
    int tempIY = x.second;
    int tempFX = y.first;
    int tempFY = y.second;

    std::vector<Color> listColor;

    while ((0 <= tempIX && tempIX <= 8) && (0 <= tempIY && tempIY <= 8)){
        Color validationC = m_board[tempIX][tempIY]->getColor();
        switch (validationC) {
        case WHITE:
            listColor.push_back(WHITE);
            break;
        case BLACK:
            listColor.push_back(BLACK);
            break;
        case NONE:
            listColor.push_back(NONE);
            break;
        case OUT:
            listColor.push_back(OUT);
            break;
        default:
            break;
        }
        tempIX += diffX;
        tempIY += diffY;
    }
    tempIX = x.first;
    tempIY = x.second;
    Color ancien = Color::NONE;
    if (isPlayableMarble(listColor)){
        m_board[tempIX][tempIY]->setColor(Color::NONE);
        for (Color var : listColor){
            if (var != OUT) {
                if ((0 <= tempFX && tempFX <= 8) && (0 <= tempFY && tempFY <= 8)){
                    if (var != Color::NONE){
                        m_board[tempFX][tempFY]->setColor(var);
                        tempFX += diffX;
                        tempFY += diffY;
                        ancien = var;
                    }
                }else{
                    std::cout << "Color to remove point :" << ancien << std::endl;
                    return ancien;
                }
            }
            std::cout << "Color to remove point :" << ancien << std::endl;
            return ancien;
        }
    }
    std::cout << "Color to remove point :" << Color::NONE << std::endl;
    return Color::NONE;
}

std::pair<int, int> Board::convertStringToHex(std::string a){
    std::string str1 = a.substr(0, 1);//&a[0];//a.substr(0, 1);
    std::string str2 = &a[1];
    int i1 = m_convertionMap.at(str1);
    int i2 = std::atoi(str2.c_str());
    return std::make_pair(i1, i2);
}

bool Board::isPlayableMarble(std::vector<Color> vectorColor){
    int countBlack = 0;
    int countWhite = 0;
    Color precedant = Color::NONE;
    bool change = false;
    bool alreadyChange = false;

    for (Color var : vectorColor){
        if ((var == Color::NONE) || (var == Color::OUT)){
            break;
        }
        if (var == Color::BLACK){
            if (!change && !alreadyChange){
                if (var == precedant || var != Color::NONE){
                    precedant = Color::BLACK;
                    countBlack++;
                }else{
                    if (change){
                        alreadyChange = true;
                        return false;
                    }
                    precedant = Color::BLACK;
                    change = true;
                    countBlack++;
                }
            }
        }
        if (var == Color::WHITE){
            if (!change && !alreadyChange){
                if (var == precedant || var != Color::NONE){
                    precedant = Color::WHITE;
                    countWhite++;
                }else{
                    if (change){
                        alreadyChange = true;
                        return false;
                    }
                    precedant = Color::WHITE;
                    change = true;
                    countWhite++;
                }
            }
        }
    }
    int res = 0;
    if (vectorColor[0] == Color::BLACK){
        res = countBlack - countWhite;
        if (res > 3){
            return false;
        }
    }
    if (vectorColor[0] == Color::WHITE){
        res = countWhite - countBlack;
        if (res > 3){
            return false;
        }
    }

    return (res = 1) ? true : false;
}
