#include <iostream>
#include <limits>

#include "Game.h"

#include "../bot/Bot.h"
#include "../linkedlist/LinkedList.h"
#include "../player/Player.h"
#include "../playeraccount/PlayerAccount.h"

void craps(PlayerAccount& account, LinkedList<std::string>& balanceList, LinkedList<int>& rollList) {
    Player playerTurn;
    Bot botTurn;
    char playAgain = 'y';
    char roll;
    int playerBalance;
    int playerBet;
    int botBet;

    std::cout << "\n--------------------------------------------------------------------------------\n";
    std::cout << "Welcome to craps!\n";
    std::cout << "Your current balance is: $" << account.getPlayerBalance() << std::endl;

    while (playAgain == 'y' || playAgain == 'Y') {
        playerBalance = account.getPlayerBalance();

        //Player's bet
        do {
            std::cout << "\nEnter your bet: $";
            while(!(std::cin >> playerBet)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cout << "Invalid input. Please enter an integer: $";
            }

            while(playerBet > account.getPlayerBalance()) {
                std::cout << "Insufficient balance to place bet. Please try a smaller amount: $";
                std::cin >> playerBet;
                if (playerBet <= account.getPlayerBalance()) {
                    break;
                }
            }
        } while(playerBet > account.getPlayerBalance());
    
        std::cout << "The bot puts $" << playerBet << " into the pot.\n";
        
        do {
            std::cout << "\nEnter 'R' to roll: ";
            std::cin >> roll;
            while (roll != 'r' && roll != 'R') {
                std::cout << "Invalid input. Please enter 'R' to roll: ";
                std::cin >> roll;
            }
        } while (roll != 'r' && roll != 'R');
        
        //Player's roll turn (true)
        playerTurn.playerRollOutcome(balanceList, rollList, account, playerBet);

        playerBalance = account.getPlayerBalance();

        if (account.getPlayerBalance() == 0) {
            std::cout << "Your current balance is: $" << account.getPlayerBalance() << std::endl;
            std::cout << "You're broke!\n";
            break;
        }

        std::cout << "Your current balance is: $" << account.getPlayerBalance() << std::endl;
        std::cout << std::endl;

        // Bot's bet
        botBet = (rand() % account.getPlayerBalance()) + 1;
        std::cout << "The bot puts $" << botBet << " into the pot.\n";
        
        do {
            std::cout << "\nEnter 'R' to continue: ";
            std::cin >> roll;
            while (roll != 'r' && roll != 'R') {
                std::cout << "Invalid input. Please enter 'R' to continue: ";
                std::cin >> roll;
            }
        } while (roll != 'r' && roll != 'R');

        //Bot's roll turn
        botTurn.botRollOutcome(account, balanceList, rollList, botBet);

        std::cout << "Your current balance is: $" << account.getPlayerBalance() << std::endl;

        do {
            std:: cout << "\nAnother game? 'Y' or 'N':\n";
            std::cin >> playAgain;
            while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
                std::cout << "Invalid input. Please enter 'Y' or 'N': ";
                std::cin >> playAgain;
            }
        } while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N');

        if (playAgain == 'n' && playAgain == 'N') {
            break;
        }
    }
}