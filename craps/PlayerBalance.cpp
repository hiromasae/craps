#include "PlayerBalance.h"

PlayerBalance::PlayerBalance() {
    playerBalance = 100;
}

PlayerBalance::PlayerBalance(int newPlayerBalance) {
    playerBalance = newPlayerBalance;
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

