//
// Created by admin on 10/27/26.
//
#include "Engine.h"
#include "entt.hpp"
#include "raylib.h"
#include "raymath.h"
#include "../components/Components.h"
#include "../systems/PlayerSystem.h"
#include "../systems/RenderSystem.h"
#include "../tags/Tags.h"
static entt::registry registry;
static entt::entity camera_entity;
static const char* pathShaderVer = "../resources/shaders/vertex.glsl";
static const char* pathShaderFrag = "../resources/shaders/fragment.glsl";
void Engine::init() {
    camera_entity = registry.create();
    registry.emplace<CameraTag>(camera_entity);
    registry.emplace<Camera3D>(camera_entity, Camera3D {
        .position = {.x = .0f, .y = 25.f, .z = 25.f},
        .target = Vector3Zero(),
        .up = Vector3UnitY,
        .fovy = 60.f,
        .projection = CAMERA_PERSPECTIVE
    });
    const auto shader = registry.create();
    registry.emplace<ShaderTag>(shader);

    const auto player = registry.create();
    registry.emplace<PlayerTag>(player);
    registry.emplace<ModelComponent>(player, GenMeshCube(2.f, 2.f, 2.f));
    registry.emplace<PositionComponent>(player, Vector3{.x = .0f, .y = .0f, .z = .0f});
    registry.emplace<SizeComponent>(player, 2.f);
    registry.emplace<ColorComponent>(player, BLUE);
    registry.emplace<VelocityComponent>(player, 50.f);
    registry.emplace<ShaderComponent>(player, pathShaderVer, pathShaderFrag);

    const auto glass = registry.create();
    registry.emplace<GlassTag>(glass);
    registry.emplace<ModelComponent>(glass, GenMeshCube(100.f, .5f, 100.f));
    registry.emplace<PositionComponent>(glass, Vector3{.x = .0f, .y = -35.0f, .z = -35.0f});
    registry.emplace<SizeComponent>(glass, 2.f);
    registry.emplace<ColorComponent>(glass, DARKGRAY);

    const auto lamp = registry.create();
    registry.emplace<GlassTag>(lamp);
    registry.emplace<ModelComponent>(lamp, GenMeshCube(2.f, 2.f, 2.f));
    registry.emplace<PositionComponent>(lamp, Vector3{.x = .0f, .y = -25.0f, .z = 0.0f});
    registry.emplace<SizeComponent>(lamp, 2.f);
    registry.emplace<ColorComponent>(lamp, WHITE);

}

void Engine::update(const float deltaTime) {
    PlayerSystem::update(registry, deltaTime);
}

void Engine::render() {
    BeginDrawing();
        ClearBackground(BLACK);
        if (registry.valid(camera_entity) && registry.all_of<Camera3D>(camera_entity)) {
            const auto& camera = registry.get<Camera3D>(camera_entity);
            BeginMode3D(camera);
               RenderSystem::render(registry);
            EndMode3D();
        }
      DrawFPS(10, 10);
    EndDrawing();
}

void Engine::unload() {

}
