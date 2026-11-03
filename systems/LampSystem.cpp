//
// Created by admin on 10/27/26.
//

#include "LampSystem.h"
#include "../components/Components.h"
#include "../tags/Tags.h"

void LampSystem::update(entt::registry &registry, float deltaTime) {
    const auto glass = registry.view<GlassTag, TransformComponent>();
    const auto view = registry.view<LampTag, TransformComponent, VelocityComponent>();
    for (const auto&& [entity, transform, velocity] : view.each()) {
    }
}
