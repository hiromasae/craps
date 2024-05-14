#include <iostream>

#include "PlayerAccount.h"

#include "../linkedlist/LinkedList.h"
#include "../returntomenu/ReturnToMenu.h"

PlayerAccount::PlayerAccount() {
    playerBalance = 100;
}

PlayerAccount::PlayerAccount(int newPlayerBalance) {
    this->playerBalance = newPlayerBalance;
}

int PlayerAccount::getPlayerBalance() const {
    return playerBalance;
} 

// Transaction methods

void PlayerAccount::playerBet(PlayerAccount& balance, int playerBet) {
    
}

void PlayerAccount::increasePlayerBalance(int increaseValue) {
    playerBalance += increaseValue;
}

void PlayerAccount::decreasePlayerBalance(int decreaseValue) {
    playerBalance -= decreaseValue;
}

void PlayerAccount::printPlayerBalance(PlayerAccount& balance) {
    std::cout << "\n--------------------------------------------------------------------------------\n";
    std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;
    returnToMenu();
}

// Transaction history

void PlayerAccount::addAddToList(LinkedList<std::string>& balanceList, std::string amount) {
    balanceList.append(" +$" + amount);
}

void PlayerAccount::addMinusToList(LinkedList<std::string>& balanceList, std::string amount){
    balanceList.append(" -$" + amount);
}

void PlayerAccount::printPlayerBalanceHistory(LinkedList<std::string>& balanceList, PlayerAccount& balance) {
    std::cout << "\n--------------------------------------------------------------------------------\n";
    std::cout << "Transaction history:" << std::endl;
    balanceList.display();
    std::cout << "Current: $" << balance.getPlayerBalance() << std::endl;
    returnToMenu();
}

// Roll history

void PlayerAccount::addRollToList(LinkedList<int>& rollList, int rollNum1, int rollNum2, int rollNumTotal) {
    rollList.append(rollNum1);
    rollList.append(rollNum2);
    rollList.append(rollNumTotal);
}

void PlayerAccount::printRollHistory(LinkedList<int>& rollList) {
    std::cout << "\n--------------------------------------------------------------------------------\n";
    rollList.displayRolls();
    returnToMenu();
}
