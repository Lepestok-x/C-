
#include "PlayerSystem.h"

#include <iostream>

#include "raylib.h"
#include "../components/Components.h"
#include "../tags/Tags.h"
//
// Created by admin on 10/27/26.
//
void PlayerSystem::update(entt::registry& registry, const float deltaTime) {
    const auto view = registry.view<PlayerTag, TransformComponent, VelocityComponent, GravitateComponent>();
    for (const auto&& [entity, position, velocity, gravity] : view.each()) {
        if (IsKeyDown(KEY_W)) position.position.z -= velocity.velocity * deltaTime;
        if (IsKeyDown(KEY_S)) position.position.z += velocity.velocity * deltaTime;
        if (IsKeyDown(KEY_A)) position.position.x -= velocity.velocity * deltaTime;
        if (IsKeyDown(KEY_D)) position.position.x += velocity.velocity * deltaTime;
        if (IsKeyPressed(KEY_SPACE)) position.velocity.y = -gravity.gravity.y;
    }
}

