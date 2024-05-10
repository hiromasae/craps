#include <string>
#include "PlayerBalanceHistory.h"
#include "../linkedlist/LinkedList.h"
#include "../player/Player.h"

void addAddToList(LinkedList<std::string>& balanceList, std::string amount) {
    balanceList.append("+$" + amount);
}

void addMinusToList(LinkedList<std::string>& balanceList, std::string amount){
    balanceList.append("-$" + amount);
}

void printPlayerBalanceHistory(LinkedList<std::string>& balanceList, Player& balance) {
    char choice;
    std::cout << "\n--------------------------------------------------------------------------------\n";
    std::cout << " $100" << std::endl;
    balanceList.display();
    std::cout << "Current balance: $" << balance.getPlayerBalance() << std::endl;
    std::cout << "Enter 'Q' to return to menu:\n";
    std::cin >> choice;
}