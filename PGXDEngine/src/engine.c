#include "engine.h"

void drawSplash(resource_dir_s resd) {
    SetTargetFPS(48);
    Font fn = LoadFontEx(getResourceLocation(resd, "core/DEFAULT.TTF"), 64, NULL, 0);
    Vector2 fnhere = MeasureTextEx(fn, "PGXD/Engine", 64, 1);
    for (size_t i = 0; i < 128; i++)
    {
        BeginDrawing(); ClearBackground(BLACK);

        DrawRectangleGradientV(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK, PGXDPURPLE);

        DrawRectangle((0.5f * GetScreenWidth()) - (GetScreenHeight() * 0.25f), GetScreenHeight() * 0.25f, GetScreenHeight() * 0.5f, GetScreenHeight() * 0.5f, PGXDPURPLE);
        DrawRectanglePro(
            (Rectangle) {
            0.5f * GetScreenWidth(), GetScreenHeight() * 0.5f, GetScreenHeight() * 0.65f, GetScreenHeight() * 0.65f
        },
            (Vector2) {
            GetScreenHeight() * 0.325f, GetScreenHeight() * 0.325f
        },
            ParametricBlend(clamp(i, 0, 96) / 96.0f) * -5.0f,
            PGXDPURPLELO);

        DrawRectanglePro(
            (Rectangle) {
            0.5f * GetScreenWidth(), GetScreenHeight() * 0.5f, GetScreenHeight() * 0.8f, GetScreenHeight() * 0.8f
        },
            (Vector2) {
            GetScreenHeight() * 0.4f, GetScreenHeight() * 0.4f
        },
            ParametricBlend(clamp(i, 0, 96) / 96.0f) * -10.0f,
            PGXDPURPLELLO);

        DrawTextEx(fn, "PGXD/Engine", (Vector2) { GetScreenWidth() - fnhere.x, GetScreenHeight() - fnhere.y }, 64, 1, WHITE);

        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), (Color) { 0, 0, 0, clamp(i - 96, 0, 64) * 8.1 });

        if (i > 126)
            DrawText("Getting ready...", 0, GetScreenHeight() - 10, 10, WHITE);

        EndDrawing();

        if (IsKeyDown(KEY_ENTER))
            i = 128;

        if (WindowShouldClose() && !IsKeyDown(KEY_ESCAPE))
            exit(0);
    }

    UnloadFont(fn);
    SetTargetFPS(0);
}