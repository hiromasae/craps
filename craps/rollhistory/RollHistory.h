#ifndef ROLLHISTORY_H
#define ROLLHISTORY_H

#include "../linkedlist/LinkedList.h"

void addRollToList(LinkedList<int>& rollList, int rollNum1, int rollNum2, int rollNumTotal);
void printRollHistory(LinkedList<int>& rollList);

#endif