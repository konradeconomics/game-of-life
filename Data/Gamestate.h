#ifndef GAME_OF_LIFE_GAMESTATE_H
#define GAME_OF_LIFE_GAMESTATE_H
#include <utility>
#include <sys/types.h>

const uint outerMatrixSize = 192;
const uint innerMatrixSize = 108;


class Gamestate {
    private:
        bool currentGrid[outerMatrixSize][innerMatrixSize];
        bool nextGrid[outerMatrixSize][innerMatrixSize];

    public:
        Gamestate(std::pair<uint,uint>[], uint);
        Gamestate(bool random);
        bool updateGrid();
        uint countNeighbors(uint outer, uint inner);
        bool calculatedNextGrid();
        void fillCell(uint outer, uint inner);
        void emptyCell(uint outer, uint inner);
        void printGamestate();
        bool getCell(uint outer, uint inner) const;
        void randomize();
};


#endif //GAME_OF_LIFE_GAMESTATE_H