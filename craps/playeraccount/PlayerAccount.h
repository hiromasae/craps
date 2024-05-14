#ifndef PLAYERACCOUNT_H
#define PLAYERACCOUNT_H

#include <string>

#include "../linkedlist/LinkedList.h"

class PlayerAccount {
    private:
        int playerBalance;
    public: 
        PlayerAccount();
        PlayerAccount(int newPlayerBalance);
        int getPlayerBalance() const;
        // Transaction methods
        void playerBet(PlayerAccount& balance, int playerBet);
        void increasePlayerBalance(int increaseValue);
        void decreasePlayerBalance(int decreaseValue);
        void printPlayerBalance(PlayerAccount& balance);
        // Transaction history
        void addAddToList(LinkedList<std::string>& balanceList, std::string amount);
        void addMinusToList(LinkedList<std::string>& balanceList, std::string amount);
        void printPlayerBalanceHistory(LinkedList<std::string>& balanceList, PlayerAccount& balance);
        // Roll history
        void addRollToList(LinkedList<int>& rollList, int rollNum1, int rollNum2, int rollNumTotal);
        void printRollHistory(LinkedList<int>& rollList);
};

#endif