//
// Created by admin on 10/29/26.
//
#include "GravitySystem.h"

#include "../components/Components.h"
#include "../tags/Tags.h"
void GravitySystem::update(entt::registry &registry, float deltaTime) {
    const entt::basic_view view = registry.view<GravityTag, GravitateComponent, TransformComponent>();
    for (const auto&& [entity, gravity, transform] : view.each()) {
        transform.vel_position = transform.position;
        transform.velocity.y += gravity.gravity.y * deltaTime;
        transform.position.y += transform.velocity.y * deltaTime;
    }
}
