#include <iostream>

#include "Player.h"

#include "../linkedlist/LinkedList.h"
#include "../playeraccount/PlayerAccount.h"

void Player::playerRollOutcome(LinkedList<std::string>& balanceList, LinkedList<int>& rollList, PlayerAccount& account, int playerBet) {
    int roll1 = rollDice();
    int roll2 = rollDice();
    int rollSum = roll1 + roll2;

    std::cout << "\nPlayer rolled: " << roll1 << " + " << roll2 << " = " << rollSum << std::endl;
    account.addRollToList(rollList, roll1, roll2, rollSum);

    if (rollSum == 7 || rollSum == 11) {
        std::cout << "\nPlayer wins!\n";
        account.increasePlayerBalance(playerBet);
        account.addAddToList(balanceList, std::to_string(playerBet));
    }
    else if (rollSum == 2 || rollSum == 3 || rollSum == 12) {
        std::cout << "\nPlayer loses!\n";
        account.decreasePlayerBalance(playerBet);
        account.addMinusToList(balanceList, std::to_string(playerBet));
    }
    else {
        int point = rollSum;
        std::cout << "Point is: " << point << std::endl;

        while (true) {
            roll1 = rollDice();
            roll2 = rollDice();
            rollSum = roll1 + roll2;
            std::cout << "Player rolled: " << roll1 << " + " << roll2 << " = " << rollSum << std::endl;
            account.addRollToList(rollList, roll1, roll2, rollSum);

            if (rollSum == point) {
                std::cout << "\nPlayer wins!\n";
                account.increasePlayerBalance(playerBet);
                account.addAddToList(balanceList, std::to_string(playerBet));
                break;
            }
            else if (rollSum == 7) {
                std::cout << "\nPlayer loses!\n";
                account.decreasePlayerBalance(playerBet);
                account.addMinusToList(balanceList, std::to_string(playerBet));
                break;
            }
        }
    }
}

