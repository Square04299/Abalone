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



void View::displayWinner(std::string const &t1, std::string const &t2, Color color) const{
    std::cout << t1 << color << t2 << std::endl;
}

void View::displayStr(std::string const &s){
    std::cout << s << std::endl;
}

void View::displayStrC(std::string const &p, Color c){
    std::cout<< c << p <<std::endl;
}

std::string View::askCoord(std:: string const &x){
    std::cout << "Enter a letter between (A - I) " << x << std::endl;
    char letter;
    std::cin >> letter;
   while (alphabet(letter)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalide Letter. Enter a new Letter between (A - I)"<< std::endl;
        std::cin >> letter;
    }
   if (std::islower(letter)) {
       letter = toUpperCase(letter);//Budget lowerCase to upperCase
   }
    std::cout << "Enter a number between (1 - 9)" << x << std::endl;
    unsigned number;
    std::cin >> number;
    while (!(numberV(number))) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalide Number. Enter a new Letter between (1 - 9)"<< std::endl;
        std::cin >> number;
    }
    std::string result;
    result.push_back(letter);
    result += std::to_string(number);
    return result;
}

bool View::alphabet(char letter){
    if (std::islower(letter)) {
        letter = toUpperCase(letter);//Budget lowerCase to upperCase
    }
    if (isalpha(letter)) {
        switch (letter) {
        case 'A':
            return false;
            break;
        case 'B':
            return false;
            break;
        case 'C':
            return false;
            break;
        case 'D':
            return false;
            break;
        case 'E':
            return false;
            break;
        case 'F':
            return false;
            break;
        case 'G':
            return false;
            break;
        case 'H':
            return false;
            break;
        case 'I':
            return false;
            break;
        default:
            return true;
            break;
        }
    };
    return false;
}

bool View::numberV(unsigned number){
    if (number < 10) {
        return true;
    }
    return false;
}

char View::toUpperCase(char x){
    return (x = x - 32);
}
