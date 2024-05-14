#ifndef PLAYER_H
#define PLAYER_H

#include "../gamemember/GameMember.h"
#include "../linkedlist/LinkedList.h"
#include "../playeraccount/PlayerAccount.h"

class Player : public GameMember {
    public:
        void playerBet(int playerBet);
        void playerRollOutcome(LinkedList<std::string>& balanceList, LinkedList<int>& rollList, PlayerAccount& account, int playerBet);
};

#endif