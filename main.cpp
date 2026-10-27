#include <iostream>
#include <raylib.h>
#include <entt.hpp>
#include <raymath.h>

#include "systems/PlayerSystem.h"
#include "systems/RenderSystem.h"
#include "tags/Tags.h"
static int screenWidth = 1000;
static int screenHeight = 650;
static const char *title = "Raylib";

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60);
    entt::registry registry;
    const Camera3D camera = {
        .position = {.x = .0f, .y = 25.f, .z = 25.f},
        .target = Vector3Zero(),
        .up = {.x = .0f, .y = 1.f, .z = .0f},
        .fovy = 60.f,
        .projection = CAMERA_PERSPECTIVE
    };

    const auto &player = registry.create();
    registry.emplace<PlayerTag>(player);
    registry.emplace<ModelComponent>(player, GenMeshCube(5.f, 5.f, 5.f));
    registry.emplace<PositionComponent>(player, Vector3{.x = .0f, .y = .0f, .z = .0f});
    registry.emplace<SizeComponent>(player, 1.f);
    registry.emplace<VelocityComponent>(player, 50.f);
    registry.emplace<ColorComponent>(player, WHITE);
    while (!WindowShouldClose()) {
        const float deltaTime = GetFrameTime();
        RenderSystem::update(registry, camera);
        PlayerSystem::update(registry, deltaTime);
    }
    RenderSystem::unloadResources(registry, player);
    CloseWindow();
    return 0;
}
