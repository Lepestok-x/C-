//
// Created by admin on 10/19/26.
//
#ifndef MY_CLEAN_GAME_LISTENERFOCUS_H
#define MY_CLEAN_GAME_LISTENERFOCUS_H
#include "Player.h"

class Listener {
    float normalSpeed{50.f};
public:
    void listener(Player &player, const Camera3D& camera) const {
        Vector3 forward = Vector3Subtract(camera.target, camera.position);
        const float dt = GetFrameTime();
        forward.y = .0f;
        const Vector3 right = {.x = -forward.z, .y = .0f, .z = forward.x};
        forward = Vector3Normalize(forward);
        Vector3 position = {.x = .0f, .y = .0f, .z = .0f};
        if (IsKeyDown(KEY_W)) position = Vector3Add(position, forward);
        if (IsKeyDown(KEY_S)) position = Vector3Subtract(position, forward);
        if (IsKeyDown(KEY_A)) position = Vector3Subtract(position, right);
        if (IsKeyDown(KEY_D)) position = Vector3Add(position, right);
        if (position.x != .0f || position.z != .0f) {
            position = Vector3Normalize(position);
            const Vector3 velocity = Vector3Scale(position, normalSpeed * dt);
            player.movePlayer(Vector3Add(player.v_position(), velocity));
        }
    }
};
#endif //MY_CLEAN_GAME_LISTENERFOCUS_H
