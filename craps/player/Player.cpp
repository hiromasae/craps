#include <iostream>
#include "Player.h"

Player::Player() {
    playerBalance = 100;
}

Player::Player(int newPlayerBalance) {
    this->playerBalance = newPlayerBalance;
}

int Player::getPlayerBalance() const {
    return playerBalance;
} 

void Player::increasePlayerBalance(int increaseValue) {
    playerBalance += increaseValue;
}

void Player::decreasePlayerBalance(int decreaseValue) {
    playerBalance -= decreaseValue;
}

void Player::printPlayerBalance(Player& balance) {
    char choice;
    std::cout << "\n--------------------------------------------------------------------------------\n";
    std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;
    std::cout << "Enter 'Q' to return to menu:\n";
    std::cin >> choice;
}

