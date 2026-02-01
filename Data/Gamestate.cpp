//
// Created by klames on 30.01.26.
//

#include "Gamestate.h"

#include <cstring>
#include <iostream>
#include <vector>

Gamestate::Gamestate(std::pair<uint,uint> initialLives[], uint numberOfPairs) : currentGrid{}, nextGrid{}  {
    for (int i = 0; i < numberOfPairs; i++) {
        if (initialLives[i].first < outerMatrixSize && initialLives[i].second < innerMatrixSize) {
            currentGrid[initialLives[i].first][initialLives[i].second] = true;
        }
    }
}

Gamestate::Gamestate() {
    randomize();
}

bool Gamestate::updateGrid() {
    std::memcpy(currentGrid, nextGrid, sizeof(currentGrid));
    return true;
}

uint Gamestate::countNeighbors(uint outer, uint inner) {
    uint neighbourCount = 0;

    if (currentGrid[(outer-1+outerMatrixSize)%outerMatrixSize][(inner-1+innerMatrixSize)%innerMatrixSize]) neighbourCount++;
    if (currentGrid[(outer-1+outerMatrixSize)%outerMatrixSize][(inner)%innerMatrixSize]) neighbourCount++;
    if (currentGrid[(outer-1+outerMatrixSize)%outerMatrixSize][(inner+1)%innerMatrixSize]) neighbourCount++;

    if (currentGrid[(outer-0)%outerMatrixSize][(inner-1+innerMatrixSize)%innerMatrixSize]) neighbourCount++;
    if (currentGrid[(outer-0)%outerMatrixSize][(inner+1)%innerMatrixSize]) neighbourCount++;

    if (currentGrid[(outer+1)%outerMatrixSize][(inner-1+innerMatrixSize)%innerMatrixSize]) neighbourCount++;
    if (currentGrid[(outer+1)%outerMatrixSize][(inner)%innerMatrixSize]) neighbourCount++;
    if (currentGrid[(outer+1)%outerMatrixSize][(inner+1)%innerMatrixSize]) neighbourCount++;

    return neighbourCount;
}

bool Gamestate::calculatedNextGrid() {
    for (uint i = 0; i < outerMatrixSize; i++) {
        for (uint j= 0; j < innerMatrixSize; j++) {
            uint neighbourCount = countNeighbors(i,j);
            if (currentGrid[i][j]) {
                if ( neighbourCount == 2 || neighbourCount == 3) {
                    nextGrid[i][j] = true;
                } else {
                    nextGrid[i][j] = false;
                }
            } else {
                if (neighbourCount == 3) {
                    nextGrid[i][j] = true;
                } else {
                    nextGrid[i][j] = false;
                }
            }
        }
    }
    return true;
}

void Gamestate::printGamestate() {
    for (uint i = 0; i < outerMatrixSize; i++) {
        for (uint j= 0; j < innerMatrixSize; j++) {
            std::cout << currentGrid[i][j];
        }
        std::cout<<"\n";
    }
}

bool Gamestate::getCell(uint outer, uint inner) const {
    if ( outer >= outerMatrixSize || inner >= innerMatrixSize) {
        return false;
    } else {
        return currentGrid[outer][inner];
    }
}

void Gamestate::randomize() {
    for (uint i = 0; i < outerMatrixSize; i++) {
        for (uint j = 0; j < innerMatrixSize; j++) {
            bool alive = (std::rand() % 100) < 15;
            currentGrid[i][j] = alive;
        }
    }
}
