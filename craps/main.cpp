#include <iostream>
#include <cstdlib>
#include <ctime>

#include "game/Game.h"
#include "howtoplay/HowToPlay.h"
#include "linkedlist/LinkedList.h"
#include "menu/Menu.h"
#include "playerbalance/PlayerBalance.h"
#include "playerbalancehistory/PlayerBalanceHistory.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int menuChoice;
    PlayerBalance balance;
    LinkedList<std::string> balanceList;

    do {
        menuChoice = getMenuChoice();
        switch (menuChoice) {
            case 1: 
                craps(balance, balanceList);
                break;
            case 2:
                howToPlayDoc();
                break;
            case 3:
                balance.printBalance(balance);
                break;
            case 4:
                printPlayerBalanceHistory(balanceList, balance);
                break;
            case 5:
                break;
        }
    }
    while (menuChoice != 0);
    return 0;
}