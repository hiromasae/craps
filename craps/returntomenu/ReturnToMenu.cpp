#include <iostream>

#include "ReturnToMenu.h"

void returnToMenu() {
    char choice;
    do {
        std::cout << "\n'Q' to return to menu:\n";
        std::cin >> choice;
        while (choice != 'q' && choice != 'Q') {
            std::cout << "Invalid input. Please enter 'Q' to return to menu: ";
            std::cin >> choice;
        }
    } while (choice != 'q' && choice != 'Q');
}