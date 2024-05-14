#include <iostream>

#include "Bot.h"

#include "../playeraccount/PlayerAccount.h"

void Bot::botRollOutcome(PlayerAccount& account, LinkedList<std::string>& balanceList, LinkedList<int>& rollList, int botBet) {
    int roll1 = rollDice();
    int roll2 = rollDice();
    int rollSum = roll1 + roll2;

    std::cout << "\nBot rolled: " << roll1 << " + " << roll2 << " = " << rollSum << std::endl;

    if (rollSum == 7 || rollSum == 11) {
        std::cout << "\nBot wins!\n";
        account.decreasePlayerBalance(botBet);
        account.addMinusToList(balanceList, std::to_string(botBet));
    }
    else if (rollSum == 2 || rollSum == 3 || rollSum == 12) {
        std::cout << "\nBot loses!\n";
        account.increasePlayerBalance(botBet);
        account.addAddToList(balanceList, std::to_string(botBet));
    }
    else {
        int point = rollSum;
        std::cout << "Point is: " << point << std::endl;

        while (true) {
            roll1 = rollDice();
            roll2 = rollDice();
            rollSum = roll1 + roll2;
            std::cout << "Bot rolled: " << roll1 << " + " << roll2 << " = " << rollSum << std::endl;

            if (rollSum == point) {
                std::cout << "\nBot wins!\n";
                account.decreasePlayerBalance(botBet);
                account.addMinusToList(balanceList, std::to_string(botBet));
                break;
            }
            else if (rollSum == 7) {
                std::cout << "\nBot loses!\n";
                account.increasePlayerBalance(botBet);
                account.addAddToList(balanceList, std::to_string(botBet));
                break;
            }
        }
    }
}