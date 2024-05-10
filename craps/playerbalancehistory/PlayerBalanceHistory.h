#ifndef PLAYERBALANCEHISTORY_H
#define PLAYERBALANCEHISTORY_H

#include <string>
#include "../linkedlist/LinkedList.h"
#include "../player/Player.h"

void addAddToList(LinkedList<std::string>& balanceList, std::string amount);
void addMinusToList(LinkedList<std::string>& balanceList, std::string amount);
void printPlayerBalanceHistory(LinkedList<std::string>& balanceList, Player& balance);

#endif