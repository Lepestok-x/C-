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
    entt::registry container;
    Engine::init();
    while (!WindowShouldClose()) {
        const float deltaTime = GetFrameTime();
        Engine::update(deltaTime);
        Engine::render();
    }
    CloseWindow();
    Engine::unload(); // Выгружаем ресурсы
    return 0;
}
