//
// Created by admin on 11/5/26.
//

#include "MovementSystem.h"

#include "../../component/Component.h"
#include "raymath.h"
void MovementSystem::update(entt::registry& registry, const float deltaTime) {
    const auto view = registry.view<TransformComponent>();
    for (const auto&& [entity, transform] : view.each()) {

    }
}
