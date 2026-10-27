//
// Created by admin on 10/23/26.
//

#ifndef RAYLIB_PLAYERINPUTSYSTEM_H
#define RAYLIB_PLAYERINPUTSYSTEM_H
#include "entt.hpp"
#include "../components/ColorComponent.h"
#include "../components/ModelComponent.h"
#include "../components/PositionComponent.h"
#include "../components/SizeComponent.h"

struct RenderSystem {

    static void update(entt::registry& registry, const Camera3D& camera);
    static void unloadResources(entt::registry& registry, entt::entity entity) {
         if (const auto* model = registry.try_get<ModelComponent>(entity)) {
             UnloadModel(model->model);
         }
        registry.destroy(entity);
    }
};
#endif //RAYLIB_PLAYERINPUTSYSTEM_H
