#include <iostream>
#include "Game.h"
#include "../linkedlist/LinkedList.h"
#include "../playerbalance/PlayerBalance.h"
#include "../playerbalancehistory/PlayerBalanceHistory.h"

int rollDice() {
    return (rand() % 6) + 1; 
}

void craps(PlayerBalance& balance, LinkedList<std::string>& balanceList) {
    char playAgain = 'y';
    char roll;
    int playerBalance;
    int playerBet;
    int botBet;

    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "Welcome to craps!\n";
    std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;

    while (playAgain == 'y' || playAgain == 'Y') {
        playerBalance = balance.getPlayerBalance();

        do {
            std::cout << "\nEnter your bet: $";
            std::cin >> playerBet;

            if (playerBet > playerBalance) {
                std::cout << "Insufficient balance to place bet. Please try a smaller amount." << std::endl;
            }
        } while (playerBet > playerBalance);

        std::cout << "The bot puts $" << playerBet << " into the pot.\n";
        std::cout << "Enter 'R' to roll: ";
        std::cin >> roll;
        std::cout << std::endl;

        int roll1 = rollDice();
        int roll2 = rollDice();
        int rollSum = roll1 + roll2;

        std::cout << "Player rolled: " << roll1 << " + " << roll2 << " = " << rollSum << std::endl;

        if (rollSum == 7 || rollSum == 11) {
            std::cout << "Player wins!\n\n";
            balance.increasePlayerBalance(playerBet);
            addAddToList(balanceList, std::to_string(playerBet));
        }
        else if (rollSum == 2 || rollSum == 3 || rollSum == 12) {
            std::cout << "Player loses!\n\n";
            balance.decreasePlayerBalance(playerBet);
            addMinusToList(balanceList, std::to_string(playerBet));
        }
        else {
            int point = rollSum;
            std::cout << "Point is: " << point << std::endl;

            while (true) {
                roll1 = rollDice();
                roll2 = rollDice();
                rollSum = roll1 + roll2;
                std::cout << "Player rolled: " << roll1 << " + " << roll2 << " = " << rollSum << std::endl;

                if (rollSum == point) {
                    std::cout << "Player wins!\n\n";
                    balance.increasePlayerBalance(playerBet);
                    addAddToList(balanceList, std::to_string(playerBet));
                    break;
                }
                else if (rollSum == 7) {
                    std::cout << "Player loses!\n\n";
                    balance.decreasePlayerBalance(playerBet);
                    addMinusToList(balanceList, std::to_string(playerBet));
                    break;
                }
            }
        }

        playerBalance = balance.getPlayerBalance();

        if (balance.getPlayerBalance() == 0) {
            std::cout << "You're broke!"; 
            break;
        }

        std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;
        std::cout << std::endl;

        // Bot's turn
        botBet = (rand() % balance.getPlayerBalance());
        std::cout << "The bot puts $" << botBet << " into the pot.\n";
        std::cout << "Enter 'R' to continue: ";
        std::cin >> roll;
        std::cout << std::endl;

        int botRoll1 = rollDice();
        int botRoll2 = rollDice();
        int botRollSum = botRoll1 + botRoll2;

        std::cout << "Bot rolled: " << botRoll1 << " + " << botRoll2 << " = " << botRollSum << std::endl;

        if (botRollSum == 7 || botRollSum == 11) {
            std::cout << "Bot wins!\n\n";
            balance.decreasePlayerBalance(botBet);
            addMinusToList(balanceList, std::to_string(botBet));
        }
        else if (botRollSum == 2 || botRollSum == 3 || botRollSum == 12) {
            std::cout << "Bot loses!\n\n";
            balance.increasePlayerBalance(botBet);
            addAddToList(balanceList, std::to_string(botBet));
        }
        else {
            int point = botRollSum;
            std::cout << "Bot's point is: " << point << std::endl;

            while (true) {
                botRoll1 = rollDice();
                botRoll2 = rollDice();
                botRollSum = botRoll1 + botRoll2;
                std::cout << "Bot rolled: " << botRoll1 << " + " << botRoll2 << " = " << botRollSum << std::endl;

                if (botRollSum == point) {
                    std::cout << "Bot wins!\n\n";
                    balance.decreasePlayerBalance(botBet);
                    addMinusToList(balanceList, std::to_string(botBet));
                    break;
                }
                else if (botRollSum == 7) {
                    std::cout << "Bot loses!\n\n";
                    balance.increasePlayerBalance(botBet);
                    addAddToList(balanceList, std::to_string(botBet));
                    break;
                }
            }
        }

        std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;
        std:: cout << "Another game? 'Y' or 'N':\n";
        std::cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }
}
