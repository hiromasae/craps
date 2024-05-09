#include <iostream>
#include "PlayerBalance.h"

PlayerBalance::PlayerBalance() {
    playerBalance = 100;
}

PlayerBalance::PlayerBalance(int newPlayerBalance) {
    this->playerBalance = newPlayerBalance;
}

int PlayerBalance::getPlayerBalance() const {
    return playerBalance;
} 

void PlayerBalance::increasePlayerBalance(int increaseValue) {
    playerBalance += increaseValue;
}

void PlayerBalance::decreasePlayerBalance(int decreaseValue) {
    playerBalance -= decreaseValue;
}

void PlayerBalance::printBalance(PlayerBalance& balance) {
    char choice;
    std::cout << "\n--------------------------------------------------------------------------------\n";
    std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;
    std::cout << "Enter 'Q' to return to menu:\n";
    std::cin >> choice;
}

