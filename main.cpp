#include <iostream>
#include <ostream>
#include <unistd.h>

#include "Data/Gamestate.h"

int main() {
    std::pair<uint,uint> initialLives[5];
    initialLives[0] = {1, 0};
    initialLives[1] = {2, 1};
    initialLives[2] = {0, 2};
    initialLives[3] = {1, 2};
    initialLives[4] = {2, 2};

    Gamestate gamestate = Gamestate(initialLives, 5);

    for (int i = 0; i < 100; i++) {
        gamestate.printGamestate();
        gamestate.calculatedNextGrid();
        gamestate.updateGrid();
        std::cin.get();
    }
}
