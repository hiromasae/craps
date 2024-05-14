#ifndef BOT_H
#define BOT_H

#include "../gamemember/GameMember.h"
#include "../playeraccount/PlayerAccount.h"

class Bot : public GameMember {
    public:
        void botBet(); 
        void botRollOutcome(PlayerAccount& balance, LinkedList<std::string>& balanceList, LinkedList<int>& rollList, int botBet);
};

#endif