#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        int playerBalance;
    public:
        Player();
        Player(int newPlayerBalance);
        int getPlayerBalance() const;
        void increasePlayerBalance(int increaseValue);
        void decreasePlayerBalance(int decreaseValue);
        void printPlayerBalance(Player& balance);
};

#endif