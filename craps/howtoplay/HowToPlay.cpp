#include <iostream>
#include <fstream> 
#include <string>
#include <cstring>

#include "HowToPlay.h"

#include "../returntomenu/ReturnToMenu.h"

void howToPlayDoc() {
    std::ifstream fileIn;
    std::string line;
    char choice;

    std::cout << "\n--------------------------------------------------------------------------------\n";

    fileIn.open("craps/howtoplay/howtoplaycraps.txt");

    if (!fileIn) {
        std::cerr << "Error!: " << strerror(errno);
    }

    while (getline(fileIn, line)) {
        std::cout << line << std::endl;
    }

    fileIn.close();
    
    returnToMenu();
}