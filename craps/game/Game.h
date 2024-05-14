#ifndef GAME_H
#define GAME_H

#include "../linkedlist/LinkedList.h"
#include "../playeraccount/PlayerAccount.h"
#include "../player/Player.h"

void craps(PlayerAccount& balance, LinkedList<std::string>& balanceList, LinkedList<int>& rollList);

#endif