#include <stdlib.h>

#include "GameMember.h"

int GameMember::rollDice() {
    return (rand() % 6) + 1; 
}