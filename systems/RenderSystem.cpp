//
// Created by admin on 10/27/26.
//

#include "RenderSystem.h"
#include "raylib.h"
#include "../components/Components.h"
#include "../tags/Tags.h"

void RenderSystem::render(entt::registry& registry) {
    const auto& view = registry.view<ModelComponent, PositionComponent, SizeComponent, ColorComponent>();
    const auto& viewShader = registry.view<ShaderTag, ModelComponent, ShaderComponent, PositionComponent, ColorComponent>();
    for (auto[entity, model, shader, position, color] : viewShader.each()) {
        model.model.materials[0].shader = shader.shader;
        int u_viewPosition = GetShaderLocation(shader.shader, "vertexPosition");
        int u_color = GetShaderLocation(shader.shader, "u_color");
        SetShaderValue(shader.shader, u_viewPosition, &position.position, SHADER_ATTRIB_VEC3);
        SetShaderValue(shader.shader, u_color, &color.color, SHADER_ATTRIB_VEC4);
    }
    for (auto [entity, model, position, size, color] : view.each()) {
        DrawModel(model.model, position.position, size.size, color.color);
    }
}
