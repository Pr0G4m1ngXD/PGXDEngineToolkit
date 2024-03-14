#include "input.h"
#include <math.h>

void updateInput(input_s* input) {
    bool keyA = IsKeyDown(KEY_A);
    bool keyD = IsKeyDown(KEY_D);
    bool keyW = IsKeyDown(KEY_W);
    bool keyS = IsKeyDown(KEY_S);


    input->motion = (Vector2){
        .x = (keyA && !keyD) ? -1.0F : ((!keyA && keyD) ? 1.0F : 0),
        .y = (keyS && !keyW) ? -1.0F : ((!keyS && keyW) ? 1.0F : 0)
    };

    float magnitude = sqrtf(input->motion.x * input->motion.x + input->motion.y * input->motion.y);

    // Normalize if magnitude is not zero
    if (magnitude != 0) {
        input->motion.x /= magnitude;
        input->motion.y /= magnitude;
    }

    input->mouse.x = GetMouseDelta().x * 0.005f;
    input->mouse.y = GetMouseDelta().y * 0.005f;
}