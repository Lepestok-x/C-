//
// Created by admin on 10/27/26.
//

#include "RenderSystem.h"
#include "raylib.h"
#include "../components/Components.h"
#include "../tags/Tags.h"

void RenderSystem::render(entt::registry& registry) {
    const entt::basic_view view = registry.view<ModelComponent, TransformComponent, SizeComponent, ColorComponent>();
    for (const auto&& [entity, model, transform, size, color] : view.each()) {
        DrawModel(model.model, transform.position, size.size, color.color);
        DrawModelWires(model.model, transform.position, size.size, color.color);
    }
}
