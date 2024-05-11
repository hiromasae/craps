#include <iostream>

#include "Game.h"
#include "../craps/Craps.h"
#include "../linkedlist/LinkedList.h"
#include "../player/Player.h"
#include "../playerbalancehistory/PlayerBalanceHistory.h"
#include "../rollhistory/RollHistory.h"

void craps(Player& balance, LinkedList<std::string>& balanceList, LinkedList<int>& rollList) {
    char playAgain = 'y';
    char roll;
    int playerBalance;
    int playerBet;
    int botBet;

    std::cout << "\n--------------------------------------------------------------------------------\n";
    std::cout << "Welcome to craps!\n";
    std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;

    while (playAgain == 'y' || playAgain == 'Y') {
        playerBalance = balance.getPlayerBalance();

        //Player's bet
        do {
            std::cout << "\nEnter your bet: $";
            std::cin >> playerBet;

            if (playerBet > playerBalance) {
                std::cout << "Insufficient balance to place bet. Please try a smaller amount." << std::endl;
            }
        } 
        while (playerBet > playerBalance);

        std::cout << "The bot puts $" << playerBet << " into the pot.\n";
        std::cout << "Enter 'R' to roll: ";
        std::cin >> roll;
        std::cout << std::endl;

        //Player's roll turn (true)
        crapsGame(balance, balanceList, rollList, playerBet, true);

        playerBalance = balance.getPlayerBalance();

        if (balance.getPlayerBalance() == 0) {
            std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;
            std::cout << "You're broke!\n";
            break;
        }

        std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;
        std::cout << std::endl;

        // Bot's bet
        botBet = (rand() % balance.getPlayerBalance()) + 1;
        std::cout << "The bot puts $" << botBet << " into the pot.\n";
        std::cout << "Enter 'R' to continue: ";
        std::cin >> roll;
        std::cout << std::endl;

        //Bot's roll turn
        crapsGame(balance, balanceList, rollList, botBet, false);

        std::cout << "Your current balance is: $" << balance.getPlayerBalance() << std::endl;
        std:: cout << "Another game? 'Y' or 'N':\n";
        std::cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }
}