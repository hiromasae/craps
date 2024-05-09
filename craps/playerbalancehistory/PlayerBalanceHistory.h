#ifndef PLAYERBALANCEHISTORY_H
#define PLAYERBALANCEHISTORY_H

#include <string>
#include "../linkedlist/LinkedList.h"
#include "../playerbalance/PlayerBalance.h"

void addAddToList(LinkedList<std::string>& balanceList, std::string amount);
void addMinusToList(LinkedList<std::string>& balanceList, std::string amount);
void printPlayerBalanceHistory(LinkedList<std::string>& balanceList, PlayerBalance& balance);

#endif