//
// Created by admin on 10/23/26.
//
#include "RenderSystem.h"
#include "entt.hpp"
void RenderSystem::update(entt::registry& registry, const Camera3D& camera) {
    const auto& view = registry.view<ModelComponent, PositionComponent, SizeComponent, ColorComponent>();
    for (const auto& entity : view) {
        const auto& model = view.get<ModelComponent>(entity);
        const auto& pos = view.get<PositionComponent>(entity);
        const auto& size = view.get<SizeComponent>(entity);
        const auto& color = view.get<ColorComponent>(entity);
        BeginDrawing();
             ClearBackground(BLACK);
             BeginMode3D(camera);
               DrawModel(model.model, pos.position, size.size, color.color);
             EndMode3D();
        EndDrawing();
    }
}
