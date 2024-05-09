#include <iostream>
#include <cstdlib>
#include <ctime>

#include "game/Game.h"
#include "howtoplay/HowToPlay.h"
#include "menu/Menu.h"
#include "playerbalance/PlayerBalance.h"

int main() {
    int menuChoice;
    PlayerBalance balance;

    do {
        menuChoice = getMenuChoice();
        switch (menuChoice) {
            case 1: 
                craps(balance);
                break;
            case 2:
                howToPlayDoc();
                break;
            case 3:
                balance.printBalance(balance);
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }
    while (menuChoice != 0);
    return 0;
}