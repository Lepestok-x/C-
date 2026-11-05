//
// Created by admin on 11/5/26.
//

#include "EnginePhysics.h"
#include "../component/Component.h"
#include "../factory/Factory.h"
#include "../system/render_system/RenderSystem.h"
#include <raymath.h>

#include "../system/camera_system/CameraSystem.h"
#include "../system/movement_system/MovementSystem.h"
#include "../system/player_system/PlayerSystem.h"

void EnginePhysics::init(entt::registry& registry) {
    Factory::player(registry, Vector3Zero(), {.x = 5.f, .y = 5.f, .z = 5.f}, 1.f, BLUE);
    Factory::player(registry, {.x = .0f, .y = -35.f, .z = -35.f}, {.x = 100.f, .y = .5f, .z = 100.f}, 1.f, DARKGRAY);
}

void EnginePhysics::update(entt::registry& registry, Camera3D& camera, const float deltaTime) {
    PlayerSystem::update(registry, camera, deltaTime);
    MovementSystem::update(registry, deltaTime);
    CameraSystem::update(registry, camera, deltaTime);
}
void EnginePhysics::render(entt::registry &registry, const Camera3D& camera) {
    BeginDrawing();
       ClearBackground(BLACK);
          BeginMode3D(camera);
            BeginBlendMode(BLEND_ALPHA);
              RenderSystem::render(registry);
            EndBlendMode();
          EndMode3D();
    DrawFPS(10, 10);
    EndDrawing();
}

void EnginePhysics::unload(entt::registry& registry) {
    const auto unloadsViews = registry.view<ModelComponent>();
    for (const auto&& [entity, model] : unloadsViews.each()) {
        UnloadModel(model.model);
    }
}
