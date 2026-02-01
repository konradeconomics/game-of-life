#ifndef GAME_OF_LIFE_DISPLAY_H
#define GAME_OF_LIFE_DISPLAY_H

#include <SDL.h>
#include <stdio.h>

#include "Gamestate.h"

class Display {
    private:
        SDL_Window* window = NULL;

        SDL_Renderer* renderer = NULL;
        int screenWidth;
        int screenHeight;
        int cellSize;

    public:
        Display(int width, int height, int cellSize);

        //~Display();

        void renderFrame(const Gamestate &gamestate);
};


#endif //GAME_OF_LIFE_DISPLAY_H