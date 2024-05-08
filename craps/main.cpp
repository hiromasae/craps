#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int max_menu_option = 5;

int getMenuChoice() {
    int menuChoice;
   
    do {
        std::cout << std::endl;
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "Craps menu: \n";
        std::cout << " (1) Start game\n";
        std::cout << " (2) How to play\n";
        std::cout << " (3) Check balance\n";
        std::cout << " (4) Transaction history\n";
        std::cout << " (5) Roll history\n";
        std::cout << "Enter a number from 1 to " << max_menu_option << "(0 to exit):\n";
        std::cin >> menuChoice;
      
        if (menuChoice < 0 || menuChoice > max_menu_option) {
            std::cout << "Error! Input must be a number between 1 and 5 (0 to exit).\n";
        }
    } 
    while (menuChoice < 0 || menuChoice > max_menu_option);
    return menuChoice;
}

int playerBalance = 100;
int botBalance = playerBalance;

int rollDice() {
    return (rand() % 6) + 1; 
}

void craps() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    char playAgain = 'y';
    char roll;
    int playerBet;
    int botBet;

    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "Welcome to craps!\n";
    std::cout << "Your current balance is: $" << playerBalance << std::endl;
    std:: cout << std::endl;

    while (playAgain == 'y' || playAgain == 'Y') {
        do {
            std::cout << "Enter your bet: $";
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
            playerBalance += playerBet;
        }
        else if (rollSum == 2 || rollSum == 3 || rollSum == 12) {
            std::cout << "Player loses!\n\n";
            playerBalance -= playerBet;
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
                    playerBalance += playerBet;
                    break;
                }
                else if (rollSum == 7) {
                    std::cout << "Player loses!\n\n";
                    playerBalance -= playerBet;
                    break;
                }
            }
        }   

        if (playerBalance == 0) {
            std::cout << "You're broke!"; 
            break;
        }

        std::cout << "Your current balance is: $" << playerBalance << std::endl;
        std:: cout << std::endl;

        // Bot's turn
        botBet = (rand() % playerBalance);
        std::cout << "The bot puts $" << botBet << " into the pot.\n";
        roll1 = rollDice();
        roll2 = rollDice();
        rollSum = roll1 + roll2;

        std::cout << "Bot rolled: " << roll1 << " + " << roll2 << " = " << rollSum << std::endl;

        if (rollSum == 7 || rollSum == 11) {
            std::cout << "Bot wins!\n\n";
            playerBalance -= botBet;
        }
        else if (rollSum == 2 || rollSum == 3 || rollSum == 12) {
            std::cout << "Bot loses!\n\n";
            playerBalance += botBet;
        }
        else {
            int point = rollSum;
            std::cout << "Bot's point is: " << point << std::endl;

            while (true) {
                roll1 = rollDice();
                roll2 = rollDice();
                rollSum = roll1 + roll2;
                std::cout << "Bot rolled: " << roll1 << " + " << roll2 << " = " << rollSum << std::endl;

                if (rollSum == point) {
                    std::cout << "Bot wins!\n\n";
                    playerBalance -= botBet;
                    break;
                }
                else if (rollSum == 7) {
                    std::cout << "Bot loses!\n\n";
                    playerBalance += botBet;
                    break;
                }
            }
        }

        std::cout << "Your current balance is: $" << playerBalance << std::endl;
        std:: cout << "Another game? 'Y' or 'N':\n";
        std::cin >> playAgain;
        std:: cout << std::endl;

        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }
}

void howToPlayDoc() {
    char choice;

    std::cout << "--------------------------------------------------------------------------------\n";
    std::cout << "How to play craps:\n";
    std::cout << "Enter 'P' to play craps ('Q' to return to menu): ";
    std::cin >> choice;

    while (choice == 'p' || choice == 'P') {
        craps();
        if (choice != 'p' || choice != 'P') {
        break;
        }
    }
}

int main() {
    int menuChoice;
    do {
        menuChoice = getMenuChoice();
        switch (menuChoice) {
            case 1: 
                craps();
                break;
            case 2:
                howToPlayDoc();
                break;
        }
    }
    while (menuChoice != 0);
    return 0;
}
