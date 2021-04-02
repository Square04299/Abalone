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

void Board::clear(){
    std::cout << "Deleting Board /!\\ " << std::endl;
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++) {
            delete m_board[i][j];
        }
        std::cout << "." << std::endl;
    }
}

bool Board::initMarblePLace(){
    bool validate = false;
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            m_board[i][j] = new Marble();
            validate = true;
        }
    }
    return validate;
}

bool Board::initMapConvertion(){
    m_convertionMap["A"] = 9;
    m_convertionMap["B"] = 8;
    m_convertionMap["C"] = 7;
    m_convertionMap["D"] = 6;
    m_convertionMap["E"] = 5;
    m_convertionMap["F"] = 4;
    m_convertionMap["G"] = 3;
    m_convertionMap["H"] = 2;
    m_convertionMap["I"] = 1;
    return true;
}

bool Board::initNullMarble(){
    for (int i=0;i<5 ;i++ ) {
        m_board[1][i]->setColor(Color::OUT);
    }
    for (int i=0;i<4 ;i++ ) {
        m_board[2][i]->setColor(Color::OUT);
    }
    for (int i=0;i<3 ;i++ ) {
        m_board[3][i]->setColor(Color::OUT);
    }
    m_board[4][1]->setColor(Color::OUT);
    m_board[6][9]->setColor(Color::OUT);
    for (int i=8;i<10 ;i++ ) {
        m_board[7][i]->setColor(Color::OUT);
    }
    for (int i=7;i<10 ;i++ ) {
        m_board[8][i]->setColor(Color::OUT);
    }
    for (int i=6;i<10 ;i++ ) {
        m_board[9][i]->setColor(Color::OUT);
    }
    for (int i = 0; i < 11; i++) {
        m_board[0][i]->setColor(Color::OUT);
        m_board[10][i]->setColor(Color::OUT);

        m_board[i][0]->setColor(Color::OUT);
        m_board[i][10]->setColor(Color::OUT);
    }
    return ((m_board[1][1]->getColor() == Color::OUT) && (m_board[8][8]->getColor() == Color::OUT))? true:false;
}

bool Board::initPlaceBlackMarble(){
    for (int i = 8; i < 10; i++){
        for (int j = 1; j < 10; j++){
            if (m_board[i][j]->getColor() != Color::OUT){
                m_board[i][j]->setColor(Color::BLACK);
            }
        }
    }
    for (int j = 3; j < 6; j++){
        m_board[7][j]->setColor(Color::BLACK);
    }
    return true;
}

bool Board::initPlaceWhiteMarble(){
    for (int i = 1; i < 3; i++){
        for (int j = 1; j < 10; j++){
            if (m_board[i][j]->getColor() != Color::OUT){
                m_board[i][j]->setColor(Color::WHITE);
            }
        }
    }
    for (int j = 5; j < 8; j++){
        m_board[3][j]->setColor(Color::WHITE);
    }
    return true;
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
    for (int i =0 ; i < 11; i++) {
        line.push_back(m_board[x][i]->getColor());
    }
    return line;
}

Color Board::slideOneMarble(std::string const &a, std::string const&b, Color color){
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
            throw std::logic_error("The two marble are too far from each other");
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

    while ((0 <= tempIX && tempIX < 11) && (0 <= tempIY && tempIY < 11)){
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
                listColor.push_back(NONE);
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
        for (Color var : listColor) {
           if ((0 <= tempFX && tempFX < 11) && (0 <= tempFY && tempFY < 11)){
               switch (var) {
               case WHITE:
                   if (m_board[tempFX][tempFY]->getColor() != OUT) {
                       m_board[tempFX][tempFY]->setColor(var);
                       tempFX += diffX;
                       tempFY += diffY;
                       ancien = WHITE;
                   }
                   break;
               case BLACK:
                   if (m_board[tempFX][tempFY]->getColor() != OUT) {
                       m_board[tempFX][tempFY]->setColor(var);
                       tempFX += diffX;
                       tempFY += diffY;
                       ancien = BLACK;
                   }
                   break;
               case NONE:
                   return NONE;
               case OUT:
                   //Never should enter because of if OUT condition
                   break;
               default:
                   return NONE;
               }
           }
        }
        return ancien;
    }
    std::cout << "Wasn't able to move this marble logic_error" << std::endl;
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
    bool foundNONE = false;
    int res;

    for (Color var : vectorColor){
        switch (var) {
        case WHITE:
            if (!foundNONE) {
                countWhite++;
            }
            break;
        case BLACK:
            if (!foundNONE) {
                countBlack++;
            }
            break;
        case NONE:
            if (!foundNONE) {
                foundNONE = true;
            }
            break;
        case OUT:
            break;
        default:
            break;
        }
    }
    if (vectorColor[0] == Color::BLACK){
        res = countBlack - countWhite;
        switch (res) {
            case 0:
                return false;
            case 1:
                return true;
            case 2:
                return true;
            case 3:
                if (foundNONE) {
                    return true;
                }
                return false;
            default:
                return false;
        }
    }
    if (vectorColor[0] == Color::WHITE){
        res = countWhite - countBlack;
        switch (res) {
            case 0:
                return false;
            case 1:
                return true;
            case 2:
                return true;
            case 3:
                if (foundNONE) {
                    return true;
                }
                return false;
            default:
                return false;
        }
    }
    return false;
}
