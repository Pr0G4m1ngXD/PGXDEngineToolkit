#ifndef INPUT_H
#define INPUT_H

#include "raylib.h"

typedef struct input {
    Vector2 motion;
    Vector2 mouse;
} input_s;

void updateInput(input_s* input);
#endif