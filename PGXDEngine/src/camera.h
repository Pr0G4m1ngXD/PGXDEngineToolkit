#include "raylib.h"
#include "util.h"
#include "input.h"

typedef struct cameraConf {
    bool isFirstPerson;
    float distance;
    float smoothing;
    Vector2 look;
} cameraConf_s;

Camera3D getDefaultCamera();

cameraConf_s getDefaultCameraConfig();

void updateCameraView(Camera3D* camera, Vector3 campoint, cameraConf_s* camconf, input_s input);