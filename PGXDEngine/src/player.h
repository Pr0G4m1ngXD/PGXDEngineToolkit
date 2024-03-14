#include "raylib.h"
#include "input.h"

typedef struct player {
    Vector3 position;
    Vector3 velocity;
    float speed;
    float smoothing;
} player_s;

player_s getDefaultPlayer();

void updatePlayer(player_s* player_p, input_s input, float angle);
