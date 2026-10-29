//
// Created by admin on 10/27/26.
//
#include "Engine.h"
#include "entt.hpp"
#include "raylib.h"
#include "../entities/Entity.h"
#include "../systems/CameraSystem.h"
#include "../systems/GravitySystem.h"
#include "../systems/PhysicsSystem.h"
#include "../systems/PlayerSystem.h"
#include "../systems/RenderSystem.h"
static entt::registry registry;
void Engine::init() {
    Entity::player(registry, {.x = 2.f, .y = 2.f, .z = 2.f}, BLUE);
    Entity::glass(registry, {.x = 100.f, .y = .5f, .z = 100.f}, DARKGRAY);
    Entity::lamp(registry, {.x = 1.f, .y = 1.f, .z = 1.f}, WHITE);
}

void Engine::update(Camera& camera, const float deltaTime) {
    PlayerSystem::update(registry, deltaTime);
    GravitySystem::update(registry, deltaTime);
    PhysicsSystem::update(registry, deltaTime);
    CameraSystem::update(registry, camera, deltaTime);
}

void Engine::render(const Camera& camera) {
    BeginDrawing();
        ClearBackground(BLACK);
            BeginMode3D(camera);
               RenderSystem::render(registry);
            EndMode3D();
      DrawFPS(10, 10);
    EndDrawing();
}
