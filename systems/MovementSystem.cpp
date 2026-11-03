//
// Created by admin on 11/3/26.
//

#include "MovementSystem.h"

#include "../components/Components.h"
#include "../tags/Tags.h"
#include "raymath.h"
void MovementSystem::update(entt::registry &registry, float deltaTime) {
    const entt::basic_view view = registry.view<PlayerTag, TransformComponent, VelocityComponent, NormalizeComponent, GravitateComponent>();
    for (const auto&& [entity, transform, velocity, normalize, gravitate] : view.each()) {

        if (normalize.normalize != Vector3Zero()) {
            transform.position.z += (normalize.normalize.z * velocity.velocity) * deltaTime;
            transform.position.x += (normalize.normalize.x * velocity.velocity) * deltaTime;
        }
        transform.vel_position = transform.position;
        transform.velocity.y += gravitate.gravity.y * deltaTime;
        transform.position.y += transform.velocity.y * deltaTime;
    }
}
