#include "controls.h"
#include "include/SDL2/SDL.h"

// Variables
SnakeGame::SnakeGame() {
    // Initialize game state
    dir = RIGHT;
    gameOver = false;

    // Initialize snake with one segment in the middle of the screen
    snake.push_back({SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2});

    // Initialize fruit location
    generateFruit();
}

void SnakeGame::moveSnake() {
    // Move the head of the snake based on the current direction
    int newX = snake[0].x;
    int newY = snake[0].y;
    switch (dir) {
        case UP:
            newY--;
            break;
        case DOWN:
            newY++;
            break;
        case LEFT:
            newX--;
            break;
        case RIGHT:
            newX++;
            break;
    }

    // Move the head to the new position
    Segment newHead = {newX, newY};
    snake.insert(snake.begin(), newHead);

    // Check if the snake has collided with itself
    for (size_t i = 1; i < snake.size(); ++i) {
        if (newX == snake[i].x && newY == snake[i].y) {
            gameOver = true;
            return;
        }
    }

    // If the snake did not eat the fruit, remove the tail segment
    if (newX != fruit.x || newY != fruit.y) {
        snake.pop_back();
    }
}

void SnakeGame::generateFruit() {
    // Generate a random location for the fruit within the game board
    fruit.x = rand() % (SCREEN_WIDTH / CELL_SIZE);
    fruit.y = rand() % (SCREEN_HEIGHT / CELL_SIZE);
}

bool SnakeGame::checkCollision() {
    // Check if the snake has collided with the walls
    int headX = snake[0].x;
    int headY = snake[0].y;
    if (headX < 0 || headY < 0 || headX >= SCREEN_WIDTH / CELL_SIZE || headY >= SCREEN_HEIGHT / CELL_SIZE) {
        gameOver = true;
        return true;
    }
    return false;
}

void SnakeGame::updateGame() {
    // Update game logic
    moveSnake();
    if (checkCollision()) {
        return;
    }

    // Check if the snake has eaten the fruit
    if (snake[0].x == fruit.x && snake[0].y == fruit.y) {
        generateFruit();
    }
}

bool SnakeGame::isGameOver() {
    return gameOver;
}

void SnakeGame::render() {
    // Clear the screen
    system("cls"); // For Windows
    // system("clear"); // For Unix/Linux

    // Draw the game board
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            // Check if the current position contains the snake's head or body
            bool isSnakeSegment = false;
            for (const Segment& segment : snake) {
                if (segment.x == x && segment.y == y) {
                    isSnakeSegment = true;
                    break;
                }
            }
            if (isSnakeSegment) {
                std::cout << "O"; // Draw snake segment
            } else if (x == fruit.x && y == fruit.y) {
                std::cout << "F"; // Draw fruit
            } else {
                std::cout << " "; // Empty space
            }
        }
        std::cout << std::endl;
    }
}