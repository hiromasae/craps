#ifndef CRAPS_H
#define CRAPS_H
#include "../player/Player.h"
#include "../playerbalancehistory/PlayerBalanceHistory.h"

void crapsGame(Player& balance, LinkedList<std::string>& balanceList, LinkedList<int>& rollList, 
                int playerBet, bool isPlayerTurn);

#endif