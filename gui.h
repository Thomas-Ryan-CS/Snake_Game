#ifndef GUI_H
#define GUI_H

#include "include/SDL2/SDL.h"
#include <iostream>

// Constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Function prototypes
bool initializeSDL();
void cleanup();

#endif // GUI_H