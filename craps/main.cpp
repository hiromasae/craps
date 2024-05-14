#include <string>
#include <cstdlib>
#include <ctime>

#include "game/Game.h"
#include "howtoplay/HowToPlay.h"
#include "linkedlist/LinkedList.h"
#include "menu/Menu.h"
#include "playeraccount/PlayerAccount.h"
#include "truncatefile/TruncateFile.h"

int main() {
    int menuChoice;
    PlayerAccount playerAccount;
    LinkedList<std::string> balanceList;
    LinkedList<int> rollList;

    //Delete txt files contents when program starts
    truncateFile("craps/transactionhistory.txt");
    truncateFile("craps/rollhistory.txt");
    
    srand(static_cast<unsigned int>(time(0)));

    do {
        menuChoice = getMenuChoice();
        switch (menuChoice) {
            case 1: 
                craps(playerAccount, balanceList, rollList);
                break;
            case 2:
                howToPlayDoc();
                break;
            case 3:
                playerAccount.printPlayerBalance(playerAccount);
                break;
            case 4:
                playerAccount.printPlayerBalanceHistory(balanceList, playerAccount);
                break;
            case 5:
                playerAccount.printRollHistory(rollList);
                break;
        }
        if (playerAccount.getPlayerBalance() == 0) {
            break;
        }
    }    
    while (menuChoice != 0);

    // Output transaction history and roll history into
    // respective txt files right before program ends
    balanceList.outputTHToFile();
    rollList.outputRHToFile();

    return 0;
}