//
// Created by admin on 11/9/26.
//

#include "InputListener.h"

#include "raymath.h"

void InputListener::input(Player& player, const Camera3D& camera, const float deltaTime) {
    Vector3 forward = Vector3Subtract(camera.target, camera.position);
    forward.y = .0f;
    forward = Vector3Normalize(forward);
    const Vector3 right = {.x = -forward.z, .y = .0f, .z = forward.x};
    Vector3 normalize = Vector3Zero();
    if (IsKeyDown(KEY_W)) normalize = Vector3Add(normalize, forward);
    if (IsKeyDown(KEY_S)) normalize = Vector3Subtract(normalize, forward);
    if (IsKeyDown(KEY_A)) normalize = Vector3Subtract(normalize, right);
    if (IsKeyDown(KEY_D)) normalize = Vector3Add(normalize, right);
    if (normalize != Vector3Zero()) player.move(normalize, deltaTime);
}