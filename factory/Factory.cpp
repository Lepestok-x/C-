//
// Created by admin on 11/5/26.
//

#include "Factory.h"
#include "../component/Component.h"
#include "../tag/Tags.h"
void Factory::player(entt::registry& registry, const Vector3 position, const Vector3 size, const float scale, const Color color) {
    const entt::entity player = registry.create();
    registry.emplace<PlayerTag>(player);
    registry.emplace<ModelComponent>(player, GenMeshCube(size.x, size.y, size.z), scale, color);
    registry.emplace<TransformComponent>(player, position, 50.f);
}
void Factory::glass(entt::registry& registry, const Vector3 position, const Vector3 size, const float scale, const Color color) {
    const entt::entity glass = registry.create();
    registry.emplace<GlassTag>(glass);
    registry.emplace<ModelComponent>(glass, GenMeshCube(size.x, size.y, size.z), scale, color);
    registry.emplace<TransformComponent>(glass, position, 50.f);
}
