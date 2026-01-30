#ifndef GAME_OF_LIFE_GAMESTATE_H
#define GAME_OF_LIFE_GAMESTATE_H
#include <utility>
#include <sys/types.h>

const uint outerMatrixSize = 10;
const uint innerMatrixSize = 10;


class Gamestate {
    private:
        bool currentGrid[outerMatrixSize][innerMatrixSize];
        bool nextGrid[outerMatrixSize][innerMatrixSize];

    public:
        Gamestate(std::pair<uint,uint>[], uint);
        bool updateGrid();
        uint countNeighbors(uint outer, uint inner);
        bool calculatedNextGrid();
        void printGamestate();
};


#endif //GAME_OF_LIFE_GAMESTATE_H