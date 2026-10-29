//
// Created by admin on 10/29/26.
//

#include "CameraSystem.h"

#include "../components/Components.h"
#include "../tags/Tags.h"

void CameraSystem::update(entt::registry& registry, Camera& camera, float deltaTime) {
    const entt::basic_view view = registry.view<CameraTag, TransformComponent>();
    for (const auto&& [entity, transform] : view.each()) {

        camera.position.x = transform.position.x;
        camera.position.y = transform.position.y + 30.f;
        camera.position.z = transform.position.z + 30.f;
        camera.target = transform.position;
    }
}
