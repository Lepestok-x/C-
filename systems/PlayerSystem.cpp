
#include "PlayerSystem.h"

#include <iostream>

#include "raylib.h"
#include "../components/Components.h"
#include "../tags/Tags.h"
#include <raymath.h>
//
// Created by admin on 10/27/26.
//
void PlayerSystem::update(entt::registry& registry, const Camera3D& camera) {
    const auto view = registry.view<PlayerTag, TransformComponent, VelocityComponent, GravitateComponent, NormalizeComponent>();
    for (const auto&& [entity, position, velocity, gravity, normalize] : view.each()) {
        Vector3 forward = Vector3Subtract(camera.target, camera.position);
        forward.y = .0f;
        forward = Vector3Normalize(forward);
        const Vector3 right = {.x = -forward.z, .y = .0f, .z = forward.x};
        normalize.normalize = Vector3Zero();
        if (IsKeyDown(KEY_W)) normalize.normalize = Vector3Add(normalize.normalize, forward);
        if (IsKeyDown(KEY_S)) normalize.normalize = Vector3Subtract(normalize.normalize, forward);
        if (IsKeyDown(KEY_A)) normalize.normalize = Vector3Subtract(normalize.normalize, right);
        if (IsKeyDown(KEY_D)) normalize.normalize = Vector3Add(normalize.normalize, right);
        if (IsKeyPressed(KEY_SPACE)) position.velocity.y = -gravity.gravity.y;
    }
}

