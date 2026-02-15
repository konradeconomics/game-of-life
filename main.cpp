#include "Data/Gamestate.h"
#include "Display/Display.h"


int main(int argc, char* args[]) {
    Uint32 lastUpdate = 0;
    const Uint32 simulationSpeed = 100;

    int sizeFactor = 10;

    Gamestate gamestate = Gamestate(false);

    Display display = Display(outerMatrixSize*sizeFactor,innerMatrixSize*sizeFactor,sizeFactor);


    bool quit = false;
    bool paused = false;
    bool isLeftMouseButtonDown = false;
    bool isRightMouseButtonDown = false;
    SDL_Event event;

    while (!quit) {
        while ( SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_SPACE:
                            paused = !paused;
                            break;
                        case SDLK_r:
                            if (paused) gamestate.randomize();
                            break;
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        isLeftMouseButtonDown = true;
                    } else if (event.button.button == SDL_BUTTON_RIGHT) {
                        isRightMouseButtonDown = true;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if ( event.button.button == SDL_BUTTON_LEFT) {
                        isLeftMouseButtonDown = false;
                    } else if (event.button.button == SDL_BUTTON_RIGHT) {
                        isRightMouseButtonDown = false;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    if (isLeftMouseButtonDown && !isRightMouseButtonDown && paused) {
                        uint calculatedOuter = round((event.button.x / sizeFactor));
                        uint calculatedInner = round(event.button.y / sizeFactor);
                        gamestate.fillCell(calculatedOuter, calculatedInner);
                    } else if (!isLeftMouseButtonDown && isRightMouseButtonDown && paused) {
                        uint calculatedOuter = round((event.button.x / sizeFactor));
                        uint calculatedInner = round(event.button.y / sizeFactor);
                        gamestate.emptyCell(calculatedOuter, calculatedInner);
                    }
                    break;
            }
        }
        Uint32 currentTick = SDL_GetTicks();

        if (currentTick - lastUpdate >= simulationSpeed) {
            if (!paused) {
                gamestate.calculatedNextGrid();
                gamestate.updateGrid();
            }
            display.renderFrame(gamestate);

            lastUpdate = currentTick;
        }
        SDL_Delay(1);
    }
}