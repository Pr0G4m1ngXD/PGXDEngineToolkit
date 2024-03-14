#include "player.h"
#include "util.h"
#include <math.h>

player_s getDefaultPlayer() {
    player_s player = { 0 };
    player.position = (Vector3){ 0,0,0 };
    player.velocity = (Vector3){ 0,0,0 };
    player.speed = 0.10F;
    player.smoothing = 1.01F;
    return player;
}

void updatePlayer(player_s* player_p, input_s input, float angle) {
    float speed = player_p->speed;
    float smoothing = player_p->smoothing;

    float inputX = input.motion.x * cos(angle) + input.motion.y * sin(angle);
    float inputY = input.motion.x * sin(angle) - input.motion.y * cos(angle);

    player_p->velocity.x -= inputX * GetFrameTime() * speed;
    player_p->velocity.z -= inputY * GetFrameTime() * speed;

    player_p->velocity.x /= smoothing;
    player_p->velocity.z /= smoothing;

    player_p->position = addVector3(player_p->position, player_p->velocity);
}
