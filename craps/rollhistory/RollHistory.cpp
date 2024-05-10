#include "RollHistory.h"

void addRollToList(LinkedList<int>& rollList, int rollNum1, int rollNum2, int rollNumTotal) {
    rollList.append(rollNum1);
    rollList.append(rollNum2);
    rollList.append(rollNumTotal);
}

void printRollHistory(LinkedList<int>& rollList) {
    char choice;
    std::cout << "\n--------------------------------------------------------------------------------\n";
    rollList.displayRolls();
    std::cout << std::endl;
    std::cout << "Enter 'Q' to return to menu:\n";
    std::cin >> choice;
}
