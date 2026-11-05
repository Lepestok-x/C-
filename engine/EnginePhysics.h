//
// Created by admin on 11/5/26.
//

#ifndef RAYLIBSHADER_ENGINEPHYSICS_H
#define RAYLIBSHADER_ENGINEPHYSICS_H
#include "raylib.h"
#include "../dependencies/entt/entt.hpp"

class EnginePhysics {
public:
    static void init(entt::registry& registry);
    static void update(entt::registry& registry, Camera3D& camera, float deltaTime);
    static void render(entt::registry &registry, const Camera3D& camera);
    static void unload(entt::registry& registry);
};


#endif //RAYLIBSHADER_ENGINEPHYSICS_H
