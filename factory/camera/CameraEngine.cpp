//
// Created by admin on 11/9/26.
//

#include "CameraEngine.h"

#include <algorithm>

#include "raymath.h"
#include "../player/Player.h"

void CameraEngine::init() {
    camera= {
        .position = {.x = .0f, .y = 25.f, .z = 25.f},
        .target =  Vector3Zero(),
        .up = Vector3UnitY,
        .fovy = 60.f,
        .projection = CAMERA_PERSPECTIVE
      };
}

void CameraEngine::update(const Player& player, const float deltaTime) {

    const auto [x, y] = GetMouseDelta();
    angleX += -x * intensity * deltaTime;
    angleY += y * intensity * deltaTime;

    const float wheel = GetMouseWheelMove();
    wheelDistance -= wheel * distance;
    const Vector3 position = player.getPosition();
    angleY = std::clamp(angleY, .0f, 1.5f);

    camera.target = player.getPosition();
    camera.position.x = position.x + sinf(angleX) * cosf(angleY) * wheelDistance;
    camera.position.y = position.y + sinf(angleY) * wheelDistance;
    camera.position.z = position.z + cosf(angleX) * cosf(angleY) * wheelDistance;
}
