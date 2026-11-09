#include "raylib.h"
#include "engine/Engine.h"
static int screenWith = 1000;
static int screenHeight = 650;
static const char* title = "Raylib";
int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screenWith, screenHeight, title);
    DisableCursor();
    {
        Engine engine{};
        engine.init();
        while (!WindowShouldClose()) {
            const float deltaTime = GetFrameTime();
            engine.update(deltaTime);
            engine.render();
        }
    }
    CloseWindow();
    return 0;
}
