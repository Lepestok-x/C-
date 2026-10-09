#include <cmath>
#include <raylib.h>
#include "configurations/Collision.h"
#include "configurations/Box.h"
#include "configurations/Floor.h"
#include "configurations/SettingsCamera.h"
static auto box = Box{Vector3{.x = .0f, .y = .0f, .z = .0f}, 5, 5, 5, RED};
static auto floor_f = Floor{Vector3{.x = .0f, .y = -35.9f, .z = -25.0f}, Vector3{.x = 100, .y = 1, .z = 100}, WHITE};
static Collision collision_;
static SettingsCamera camera;
static constexpr int screedWidth = 1000;
static constexpr int screedHeight = 650;
int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screedWidth, screedHeight, "Chasing Twilight - (C++)");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {

        const float time = GetFrameTime();
        BeginDrawing();
           ClearBackground(BLACK);
           BeginMode3D(camera);
           box.drawBox();
           floor_f.drawFloor();
           box.update(camera, time);
           EndMode3D();
           DrawFPS(10, 10);
        EndDrawing();
        floor_f.update_color((collision_.collision(box, floor_f)) ? GRAY : WHITE);
        if (collision_.collision(box, floor_f)) {
            box.rollback();
        }
    }
    CloseWindow();
    return 0;
}
