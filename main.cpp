#include <iostream>
#include <raylib.h>
#include <entt.hpp>
#include <raymath.h>

#include "engine/Engine.h"
#include "tags/Tags.h"
static int screenWidth = 1000;
static int screenHeight = 650;
static const char *title = "Raylib";

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);
    Camera3D camera = {
        .position = {.x = .0f, .y = 35.f, .z = 35.f},
        .target = Vector3Zero(),
        .up = {.x = .0f, .y = 1.f, .z = .0f},
        .fovy = 60.f,
        .projection = CAMERA_PERSPECTIVE
    };
    Engine::init();
    while (!WindowShouldClose()) {
        const float deltaTime = GetFrameTime();
        Engine::update(camera, deltaTime);
        Engine::render(camera);
    }
    CloseWindow();
    return 0;
}
