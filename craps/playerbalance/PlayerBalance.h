#ifndef PLAYERBALANCE_H
#define PLAYERBALANCE_H

class PlayerBalance {
    private:
        int playerBalance;
    public:
        PlayerBalance();
        PlayerBalance(int newPlayerBalance);
        int getPlayerBalance() const;
        void increasePlayerBalance(int increaseValue);
        void decreasePlayerBalance(int decreaseValue);
        void printBalance(PlayerBalance& balance);
};

#endif