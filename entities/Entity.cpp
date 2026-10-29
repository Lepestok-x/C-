//
// Created by admin on 10/29/26.
//

#include "Entity.h"
#include "raymath.h"
void Entity::player(entt::registry& registry, const Vector3 size, const Color color) {
    const entt::entity player = registry.create();
    registry.emplace_or_replace<PlayerTag>(player);
    registry.emplace_or_replace<CameraTag>(player);
    registry.emplace_or_replace<GravityTag>(player);
    registry.emplace_or_replace<PhysicsTag>(player);
    registry.emplace_or_replace<ModelComponent>(player, GenMeshCube(size.x, size.y, size.z));
    registry.emplace_or_replace<TransformComponent>(player, Vector3Zero());
    registry.emplace_or_replace<VelocityComponent>(player, 50.f);
    registry.emplace_or_replace<SizeComponent>(player, 2.f);
    registry.emplace_or_replace<ColorComponent>(player, color);
    registry.emplace_or_replace<PhysicsComponent>(player);
    registry.emplace_or_replace<GravitateComponent>(player, Vector3{.x = -18.9f, .y = -18.9f, .z = -18.9f});
}
void Entity::glass(entt::registry& registry, const Vector3 size, const Color color) {
    const entt::entity glass = registry.create();
    registry.emplace_or_replace<GlassTag>(glass);
    registry.emplace_or_replace<PhysicsTag>(glass);
    registry.emplace_or_replace<ModelComponent>(glass, GenMeshCube(size.x, size.y, size.z));
    registry.emplace_or_replace<TransformComponent>(glass, Vector3{.x = .0f, .y = -35.0f, .z = -35.0f});
    registry.emplace_or_replace<SizeComponent>(glass, 2.f);
    registry.emplace_or_replace<PhysicsComponent>(glass);
    registry.emplace_or_replace<ColorComponent>(glass, color);
}
void Entity::lamp(entt::registry& registry, const Vector3 size, const Color color) {
    const entt::entity lamp = registry.create();
    registry.emplace_or_replace<LampTag>(lamp);
    registry.emplace_or_replace<PhysicsTag>(lamp);
    registry.emplace_or_replace<ModelComponent>(lamp, GenMeshCube(size.x, size.y, size.z));
    registry.emplace_or_replace<TransformComponent>(lamp, Vector3{.x = .0f, .y = -25.0f, .z = .0f});
    registry.emplace_or_replace<SizeComponent>(lamp, 2.f);
    registry.emplace_or_replace<ColorComponent>(lamp, color);
    registry.emplace_or_replace<PhysicsComponent>(lamp);
}
