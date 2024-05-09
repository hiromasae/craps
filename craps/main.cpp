#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"
#include "HowToPlay.h"
#include "Menu.h"
#include "PlayerBalance.h"
#include "PrintBalance.h"

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
                printBalance(balance);
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