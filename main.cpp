#include "Data/Gamestate.h"
#include "Display/Display.h"


int main(int argc, char* args[]) {
    Uint32 lastUpdate = 0;
    const Uint32 simulationSpeed = 10;

    int sizeFactor = 10;

    Gamestate gamestate = Gamestate();

    Display display = Display(outerMatrixSize*sizeFactor,innerMatrixSize*sizeFactor,sizeFactor);


    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while ( SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        Uint32 currentTick = SDL_GetTicks();

        if (currentTick - lastUpdate >= simulationSpeed) {
            gamestate.calculatedNextGrid();
            gamestate.updateGrid();
            display.renderFrame(gamestate);

            lastUpdate = currentTick;
        }
        SDL_Delay(1);
    }
}