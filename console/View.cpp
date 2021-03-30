#include "View.h"

View::View()
{

}

void View::title() const{

std::cout<<"    $$$$$$\\  $$\\                 $$\\                               "<<std::endl;
std::cout<<"   $$  __$$\\ $$ |                $$ |                              "<<std::endl;
std::cout<<"   $$ /  $$ |$$$$$$$\\   $$$$$$\\  $$ | $$$$$$\\  $$$$$$$\\   $$$$$$\\  "<<std::endl;
std::cout<<"   $$$$$$$$ |$$  __$$\\  \\____$$\\ $$ |$$  __$$\\ $$  __$$\\ $$  __$$\\ "<<std::endl;
std::cout<<"   $$  __$$ |$$ |  $$ | $$$$$$$ |$$ |$$ /  $$ |$$ |  $$ |$$$$$$$$ |"<<std::endl;
std::cout<<"   $$ |  $$ |$$ |  $$ |$$  __$$ |$$ |$$ |  $$ |$$ |  $$ |$$   ____|"<<std::endl;
std::cout<<"   $$ |  $$ |$$$$$$$  |\\$$$$$$$ |$$ |\\$$$$$$  |$$ |  $$ |\\$$$$$$$\\ "<<std::endl;
std::cout<<"   \\__|  \\__|\\_______/  \\_______|\\__| \\______/ \\__|  \\__| \\_______|"<<std::endl;
std::cout<<std::endl;
}



void View::displayWinner(std::string t1, std::string t2, Color color) const{
    std::cout << t1 << color << t2 << std::endl;
}

void View::displayStr(std::string s){
    std::cout << s << std::endl;
}

void View::displayStrC(std::string p, Color c){
    std::cout<< c << p <<std::endl;
}

std::string View::askCoord(std:: string x){
    std::cout << "Veillez entre une lettre de " << x << std::endl;
    char letter;
    while (!(std::cin >> letter || alphabet(letter))) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Lettre invalide. Veuillez entre une nouvelle lettre"<< std::endl;
    }
    std::cout << "Veillez entre une nombre de " << x << std::endl;
    unsigned number;
    while (!(std::cin >> number || numberV(number))) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Numero invalide. Veuillez entre une nouvelle lettre"<< std::endl;
    }
    return (std::to_string(putchar(std::toupper(letter))) + std::to_string(number));
}

bool View::alphabet(char letter){
    putchar(std::toupper(letter));
    if (isalpha(letter)) {
        switch (letter) {
        case 'A':
            return true;
            break;
        case 'B':
            return true;
            break;
        case 'C':
            return true;
            break;
        case 'D':
            return true;
            break;
        case 'E':
            return true;
            break;
        case 'F':
            return true;
            break;
        case 'G':
            return true;
            break;
        case 'H':
            return true;
            break;
        case 'I':
            return true;
            break;
        default:
            return false;
            break;
        }
    };
    return false;
}

bool View::numberV(unsigned number){
    if (0<= number || number >= 8) {
        return true;
    }
    return false;
}
