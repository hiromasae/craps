#include <iostream>
#include <fstream> 
#include <string>
#include "HowToPlay.h"

void howToPlayDoc() {
    std::ifstream file;
    char choice;
    std::string line;

    std::cout << "--------------------------------------------------------------------------------\n";

    file.open("crapsrules.txt");

    if (!file.is_open()) {
        std::cout << "Error! Could not open file crapsrules.txt.";
    }

    while (getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
    
    std::cout << "\n'Q' to return to menu:\n";
    std::cin >> choice;
}