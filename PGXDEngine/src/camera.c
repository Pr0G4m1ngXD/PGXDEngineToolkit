#include "camera.h"
#include <math.h>

Camera3D getDefaultCamera() {
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type
    return camera;
}

cameraConf_s getDefaultCameraConfig() {
    cameraConf_s conf = { 0 };
    conf.isFirstPerson = false;
    conf.distance = 10.0F;
    conf.smoothing = 1.01F;
    conf.look = (Vector2){ .x = 0, .y = 0 };
    return conf;
}

void updateCameraView(Camera3D* camera, Vector3 campoint, cameraConf_s* camconf, input_s input) {
    if (camconf->isFirstPerson)
        return; //TODO: Implement first person camera

    camera->target = campoint;

    camconf->look.x += input.mouse.x;
    camconf->look.y += input.mouse.y;
    camconf->look.y = clamp(camconf->look.y, -0.5f, 1.5f);

    Vector3 cameraPos;
    cameraPos.x = camera->target.x - cos(-camconf->look.y) * sin(-camconf->look.x) * camconf->distance;
    cameraPos.y = camera->target.y - sin(-camconf->look.y) * camconf->distance;
    cameraPos.z = camera->target.z - cos(-camconf->look.y) * cos(-camconf->look.x) * camconf->distance;

    camera->position = cameraPos;
}