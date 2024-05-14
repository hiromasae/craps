#include <iostream>
#include <limits>

#include "Menu.h"

int max_menu_option = 5;

int getMenuChoice() {
    int menuChoice;
   
    do {
        std::cout << "\n--------------------------------------------------------------------------------\n";
        std::cout << "Craps menu: \n";
        std::cout << " (1) Start game\n";
        std::cout << " (2) How to play\n";
        std::cout << " (3) Check balance\n";
        std::cout << " (4) Transaction history\n";
        std::cout << " (5) Roll history\n";
        std::cout << "Enter a number from 1 to " << max_menu_option << " (0 to exit):\n";

        while(!(std::cin >> menuChoice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter an integer:\n";
        }

        while(menuChoice < 0 || menuChoice > max_menu_option) {
            std::cout << "Invalid input. Input must be a number between 1 and " << max_menu_option  << " (0 to exit).\n";
            std::cin >> menuChoice;
            if (menuChoice >= 1 && menuChoice < max_menu_option) {
                break;
            }
        }
    } while (menuChoice < 0 || menuChoice > max_menu_option);

    return menuChoice;
}