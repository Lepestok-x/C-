//
// Created by admin on 11/5/26.
//

#include "RenderSystem.h"
#include "../../component/Component.h"
void RenderSystem::render(entt::registry &registry) {
    const auto& view = registry.view<ModelComponent, TransformComponent>();
    for (const auto&& [entity, model, transform] : view.each()) {
        DrawModel(model.model, transform.position, model.scale, model.color);
        DrawModelWires(model.model, transform.position, model.scale, model.color);
    }
}
