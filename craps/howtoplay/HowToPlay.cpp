#include <iostream>
#include <fstream> 
#include <string>
#include <cstring>

#include "HowToPlay.h"

void howToPlayDoc() {
    std::ifstream file;
    std::string line;
    char choice;

    std::cout << "\n--------------------------------------------------------------------------------\n";

    file.open("howtoplaycraps.txt");

    if (!file) {
        std::cerr << "Error!!!!!!: " << strerror(errno);
    }

    while (getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
    
    std::cout << "\n'Q' to return to menu:\n";
    std::cin >> choice;
}