#include "PGXDEngine/src/engine.h"

int main() {
    resource_dir_s resd = { 0 };
    if (tryLoadResource(&resd)) {
        exit(1);
    }

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1280, 720, "PGXD/Runtime");  // TODO: impl gameinfo system
    SetWindowState(FLAG_WINDOW_UNDECORATED); // Borderless Fullscreen
    SetWindowSize(1920, 1080);
    SetWindowPosition(0, 0);
    drawSplash(resd);

    Camera3D mainCamera = getDefaultCamera();
    cameraConf_s cameraConfig = getDefaultCameraConfig();
    player_s mainPlayer = getDefaultPlayer();
    input_s input = { 0 };

    DisableCursor();


    while (!WindowShouldClose() || IsKeyDown(KEY_ESCAPE)) // Detect window close button and not ESC key
    {

        updateInput(&input);
        updatePlayer(&mainPlayer, input, cameraConfig.look.x);
        updateCameraView(&mainCamera, addVector3(mainPlayer.position, (Vector3) { 0, 2, 0 }), &cameraConfig, input);

        BeginDrawing(); ClearBackground(BLACK); BeginMode3D(mainCamera);

        DrawCube(mainPlayer.position, 1.0f, 1.0f, 1.0f, RED);
        DrawGrid(10, 1.0f);

        DrawLine3D((Vector3) { 0, 0, 0 }, (Vector3) { 1, 1, 1 }, BLUE);

        EndMode3D();
        DrawFPS(16, 16);
        DrawText("PROTOTYPE BUILD: FAR FROM FINISHED", GetScreenWidth() / 2 - MeasureText("PROTOTYPE BUILD: FAR FROM FINISHED", 20) / 2, GetScreenHeight() - 20, 20, (Color) { 255, 255, 255, 127 }); // TODO: repl with gui system
        EndDrawing();
    }

    CloseWindow();
    return 69;
}