#include <iostream>
#include "PlayerBalance.h"
#include "PrintBalance.h"

void printBalance(PlayerBalance& balance) {
    char choice;
    std::cout << "\n--------------------------------------------------------------------------------\n";
    std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;
    std::cout << "Enter 'Q' to return to menu:\n";
    std::cin >> choice;
}