#include "controls.h"
#include "gui.h" // Assuming it contains the necessary functions for GUI
#include "score.h" // Assuming it contains the necessary functions for scoring

int main(int argc, char* argv[]) {
    // Initialize SDL and create window/renderer
    if (!initializeSDL()) {
        return 1;
    }

    SnakeGame game;

    // Run the game loop
    while (!game.isGameOver()) {
        game.updateGame();
        game.render();
    }

    // Cleanup SDL
    cleanup();
    return 0;
}