//
// Created by klames on 01.02.26.
//

#include "../Display/Display.h"

#include <iterator>

Display::Display(int width, int height, int _cellSize) {
    screenWidth = width;
    screenHeight = height;
    cellSize = _cellSize;
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if ( window == NULL) {
            printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
        } else {
            renderer = SDL_CreateRenderer(window, -1, 0);
        }
    }
}

void Display::renderFrame(const Gamestate &gamestate) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_Rect rectangle = {-1,-1,cellSize,cellSize};

    for (int i = 0; i < outerMatrixSize; i++) {
        for (int j = 0; j < innerMatrixSize; j++) {
            if (gamestate.getCell(i,j)) {
                rectangle.x = i * cellSize;
                rectangle.y = j * cellSize;
                SDL_RenderFillRect(renderer, &rectangle);
            }
        }
    }
    SDL_RenderPresent(renderer);
}