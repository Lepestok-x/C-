//
// Created by admin on 10/29/26.
//

#include "CameraSystem.h"

#include <iostream>

#include "../components/Components.h"
#include "../tags/Tags.h"
static float angleX = 0.0f;
static float angleY = 0.0f;
static float intensity = 0.5f;
static float distance = 50.f;
static float wheelDistance = 10.f;
void CameraSystem::update(entt::registry& registry, Camera& camera, float deltaTime) {
    const entt::basic_view view = registry.view<CameraTag, TransformComponent>();
    for (const auto&& [entity, transform] : view.each()) {

        const auto [x, y] = GetMouseDelta();
        const auto wheel = GetMouseWheelMove();
        angleX += -x * intensity * deltaTime;
        angleY += y * intensity * deltaTime;
        angleY = std::clamp(angleY, .1f, 1.5f);

        wheelDistance -= wheel * distance;
        wheelDistance = std::clamp(wheelDistance, 50.0f, 300.0f);
        const float offsetX = sinf(angleX) * cosf(angleY) * wheelDistance;
        const float offsetY = sinf(angleY) * wheelDistance;
        const float offsetZ = cosf(angleX) * cosf(angleY) * wheelDistance;

        camera.target = transform.position;
        camera.position.x = transform.position.x + offsetX;
        camera.position.y = transform.position.y + offsetY;
        camera.position.z = transform.position.z + offsetZ;
    }
}
