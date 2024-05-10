#include <stdlib.h>
#include "DiceRoll.h"

int rollDice() {
    return (rand() % 6) + 1; 
}