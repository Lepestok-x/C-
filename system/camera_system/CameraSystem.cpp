//
// Created by admin on 11/5/26.
//

#include "CameraSystem.h"

#include "raylib.h"
#include "../../component/Component.h"
#include "../../tag/Tags.h"

void CameraSystem::update(entt::registry &registry, Camera3D& camera, float deltaTime) {
     const auto view = registry.view<PlayerTag, TransformComponent>();
     for (const auto&& [entity, transform] : view.each()) {

          camera.target = transform.position;
          camera.position.x = transform.position.x;
          camera.position.y = transform.position.y + 25.f;
          camera.position.z = transform.position.z + 25.f;
     }
}
