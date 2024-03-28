#ifndef CONTROLS_H
#define CONTROLS_H

#include "include/SDL2/SDL.h"

#include <vector>
#include <cstdlib> // For rand()
#include <iostream>

// Define the Direction enumeration
enum Direction { UP, DOWN, LEFT, RIGHT };

// Define the structure for the snake segment
struct Segment {
    int x, y;
};

class SnakeGame {
private:
    std::vector<Segment> snake;
    Segment fruit;
    Direction dir;
    bool gameOver;
    // Constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int CELL_SIZE = 20;

public:
    // Constructor
    SnakeGame();

    // Function prototypes
    void moveSnake();
    void generateFruit();
    bool checkCollision();
    void updateGame();
    bool isGameOver();
    void render();

};

#endif // CONTROLS_H