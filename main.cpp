#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "service_code/Ground.h"
#include "service_code/Listener.h"
#include "service_code/Player.h"
static int screen_width = 1000;
static int screen_height = 650;
static const char* title = "Raylib";
static Player* player = new Player({.x = .0f, .y = .0f, .z = .0f}, {.x = 2.f, .y = 2.f, .z = 2.f}, RED);
static Listener listener_focus;
static std::vector<Ground*> grounds(8); // фиксируем размер, максимум 8 грунтов.
int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screen_width, screen_height, title);
    SetTargetFPS(60);

    float cameraAngleX = 0.f;
    float cameraAngleY = 0.5f;
    const float distance = 25.f;
    Camera3D camera = {
        .position = {.x = .0f, .y = 25.f, .z = 25.f},
        .target = {.x = .0f, .y = .0f, .z = .0f},
        .up = {.x = .0f, .y = 1.f, .z = .0f},
        .fovy = 60.f,
        .projection = CAMERA_PERSPECTIVE
    };
    for (int i = 0; i < 12; i++) {
        const float angle = 90;
        const float degreesZ = (sinf(angle) * -40.f);
        const float degreesX = (cosf(angle) * -35.f);
        const float z = (-35 + (degreesZ));
        grounds.push_back(new Ground({.x = degreesX, .y = -35 + (-15.0f * static_cast<float>(i)), .z = z},{.x = 50.f, .y = .5f, .z = 50.f}, WHITE));
    }
    DisableCursor();
    while (!WindowShouldClose()) {
        Vector2 mouse = GetMouseDelta();
        cameraAngleX += mouse.x * .005f;
        cameraAngleY += mouse.y * .005f;
        if (cameraAngleY > 1.4f) cameraAngleY = 1.4f;
        if (cameraAngleY < .2f) cameraAngleY = .2f;
        camera.position.x = camera.target.x + -sinf(cameraAngleX) * cosf(cameraAngleY) * distance;
        camera.position.y = camera.target.y + sinf(cameraAngleY) * distance;
        camera.position.z = camera.target.z + cosf(cameraAngleX) * cosf(cameraAngleY) * distance;
        BeginDrawing();
           BeginMode3D(camera);
              ClearBackground(BLACK);

              player->drawPlayer();
              for (const auto* ground : grounds) {
                  if (ground != nullptr) {
                      ground->drawGround();
                  }
              }
            listener_focus.listener(*player, camera);
            player->rotateCameraWithPlayer(camera, distance);
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
