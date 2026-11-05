//
// Created by admin on 11/5/26.
//

#include "PlayerSystem.h"

#include "../../component/Component.h"
#include "raymath.h"
#include "../../tag/Tags.h"
static  Vector3 normalize{};
void PlayerSystem::update(entt::registry &registry, const Camera3D& camera, float deltaTime) {
    const auto view = registry.view<PlayerTag, TransformComponent>();
    for (const auto&& [entity, transform] : view.each()) {
        Vector3 forward = Vector3Subtract(camera.target, transform.position);
        forward.y = .0f;
        forward = Vector3Normalize(forward);
        const Vector3 right = {.x = -forward.z, .y = .0f, .z = forward.x};
        normalize = Vector3Zero();
        if (IsKeyPressed(KEY_W)) normalize = Vector3Add(normalize, forward);
        if (IsKeyPressed(KEY_S)) normalize = Vector3Subtract(normalize, forward);
        if (IsKeyPressed(KEY_A)) normalize = Vector3Subtract(normalize, right);
        if (IsKeyPressed(KEY_D)) normalize = Vector3Add(normalize, right);
        if (normalize != Vector3Zero()) {
            transform.position = Vector3Scale(normalize, transform.velocity * deltaTime);
        }
    }
}
