//
// Created by admin on 11/9/26.
//

#include "Engine.h"

#include <iostream>

#include "raymath.h"
#include "../factory/player/Player.h"

void Engine::init() {
    camera_engine.init();

    const Mesh meshPlayer = GenMeshCube(2.5f, 2.5f, 2.5f);
    playerModel = LoadModelFromMesh(meshPlayer);
    player = Player{Vector3Zero(), 2.f, BLUE, playerModel};

    const Mesh meshGlass = GenMeshCube(100.f, .5f, 100.f);
    glassModel = LoadModelFromMesh(meshGlass);
    glass = Glass{{.x = .0f, .y = -35.f, .z = -35.f / 2.f}, 2.f, GRAY, glassModel};

    const Mesh meshLamp = GenMeshCube(1.5f, 1.5f, 1.5f);
    lampModel = LoadModelFromMesh(meshLamp);
    lamp = Lamp{{.x = .0f, .y = -25.f, .z = -35.f / 2.f}, 2.f, WHITE, lampModel};
}

void Engine::update(const float deltaTime) {
    input_listener.input(player, camera_engine.getCamera(), deltaTime);
    player.update(deltaTime);
    glass.update(deltaTime);
    lamp.update(deltaTime);
    camera_engine.update(player, deltaTime);
}

void Engine::render() const {
    BeginDrawing();
      ClearBackground(BLACK);
       BeginMode3D(camera_engine.getCamera());
        BeginBlendMode(BLEND_ALPHA);
         player.render();
         glass.render();
         lamp.render();
        EndBlendMode();
       EndMode3D();
    EndDrawing();
}
Engine::~Engine() {
    if (playerModel.meshCount > 0) {
        UnloadModel(playerModel);
        std::cout << "model unloaded: " << playerModel.meshCount << std::endl;
    }
}
