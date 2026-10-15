#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "service_code/Ground.h"
#include "service_code/Player.h"
static int screen_width = 1000;
static int screen_height = 650;
static const char* title = "Raylib";
static Player* player = new Player({.x = .0f, .y = .0f, .z = .0f}, {.x = 2.f, .y = 2.f, .z = 2.f}, RED);
static std::vector<Ground*> grounds(8); // фиксируем размер, максимум 8 грунтов.
int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screen_width, screen_height, title);
    SetTargetFPS(60);


    Camera3D camera = {
        .position = {.x = .0f, .y = 25.f, .z = 25.f},
        .target = {.x = .0f, .y = .0f, .z = .0f},
        .up = {.x = .0f, .y = 1.f, .z = .0f},
        .fovy = 67.f,
        .projection = CAMERA_PERSPECTIVE
    };
    for (int i = 0; i < 8; i++) {
        grounds.push_back(new Ground({.x = .0f, .y = -35 + (-10.0f * static_cast<float>(i)), .z = -35.0f},
                          {.x = 50.f, .y = .1f, .z = 50.f}, 45 + (90 * static_cast<float>(i)), 5 * static_cast<float>(i), WHITE));
    }
    while (!WindowShouldClose()) {
        BeginDrawing();
           BeginMode3D(camera);
              ClearBackground(BLACK);
              player->rotateCube(128);
              player->drawPlayer();
              for (int i = 0; i < grounds.size(); i++) {
                  if (grounds[i] != nullptr) {
                      grounds[i]->drawGround();
                  }
              }
           EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    delete player;
    for(const Ground* ground : grounds) {
        delete ground;
    }
    grounds.clear();
    return 0;
}
