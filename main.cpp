#include <iostream>

#include <raylib.h>
#include <raymath.h>
#include "engine/EnginePhysics.h"
static int width = 1000;
static int height = 650;
static const char* title = "raylib";
static entt::registry registry;
int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(width, height, title);
    SetTargetFPS(60);
    Camera3D camera = {
        .position = {.x = .0f, .y = 25.0f, .z = 25.0f},
        .target = Vector3Zero(),
        .up =  Vector3UnitY,
        .fovy = 60.f,
        .projection = CAMERA_PERSPECTIVE
    };

    EnginePhysics::init(registry);
    while (!WindowShouldClose()) {
        const float deltaTime = GetFrameTime();
        EnginePhysics::update(registry, camera, deltaTime);
        EnginePhysics::render(registry, camera);
    }
    EnginePhysics::unload(registry);
    CloseWindow();
    return 0;

}
