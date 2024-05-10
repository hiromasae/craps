#include <iostream>

#include "Craps.h"
#include "../diceroll/DiceRoll.h"
#include "../player/Player.h"
#include "../playerbalancehistory/PlayerBalanceHistory.h"
#include "../linkedlist/LinkedList.h"

void crapsGame(Player& balance, LinkedList<std::string>& balanceList, int playerBet, bool isPlayerTurn) {
    std::string currentPlayer = isPlayerTurn ? "Player" : "Bot";
    int roll1 = rollDice();
    int roll2 = rollDice();
    int rollSum = roll1 + roll2;

    std::cout << currentPlayer << " rolled: " << roll1 << " + " << roll2 << " = " << rollSum << std::endl;

    if (rollSum == 7 || rollSum == 11) {
        std::cout << currentPlayer << " wins!\n\n";
        if (isPlayerTurn) { 
            balance.increasePlayerBalance(playerBet);
            addAddToList(balanceList, std::to_string(playerBet));
        }
        else {
            balance.decreasePlayerBalance(playerBet);
            addMinusToList(balanceList, std::to_string(playerBet));
        }
    }
    else if (rollSum == 2 || rollSum == 3 || rollSum == 12) {
        std::cout << currentPlayer << " loses!\n\n";
        if (isPlayerTurn) {
            balance.decreasePlayerBalance(playerBet);
            addMinusToList(balanceList, std::to_string(playerBet));
        }
        else {
            balance.increasePlayerBalance(playerBet);
            addAddToList(balanceList, std::to_string(playerBet));
        }
    }
    else {
        int point = rollSum;
        std::cout << "Point is: " << point << std::endl;

        while (true) {
            roll1 = rollDice();
            roll2 = rollDice();
            rollSum = roll1 + roll2;
            std::cout << currentPlayer << " rolled: " << roll1 << " + " << roll2 << " = " << rollSum << std::endl;

            if (rollSum == point) {
                std::cout << currentPlayer << " wins!\n\n";
                if (isPlayerTurn) {
                    balance.increasePlayerBalance(playerBet);
                    addAddToList(balanceList, std::to_string(playerBet));
                }
                else {
                    balance.decreasePlayerBalance(playerBet);
                    addMinusToList(balanceList, std::to_string(playerBet));
                }
                break;
            }
            else if (rollSum == 7) {
                std::cout << currentPlayer << " loses!\n\n";
                if (isPlayerTurn) {
                    balance.decreasePlayerBalance(playerBet);
                    addMinusToList(balanceList, std::to_string(playerBet));
                }
                else {
                    balance.increasePlayerBalance(playerBet);
                    addAddToList(balanceList, std::to_string(playerBet));
                }
                break;
            }
        }
    }
}