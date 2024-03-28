#include "score.h"
#include <iostream>

int score = 0;

void increaseScore() {
    score += 10;
}

int getScore() {
    return score;
}