#ifndef GAME_H
#define GAME_H
#include "../player/Player.h"
#include "../playerbalancehistory/PlayerBalanceHistory.h"
#include "../rollhistory/RollHistory.h"

void craps(Player& balance, LinkedList<std::string>& balanceList, LinkedList<int>& rollList);

#endif