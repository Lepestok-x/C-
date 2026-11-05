//
// Created by admin on 11/5/26.
//

#ifndef RAYLIBSHADER_CAMERASYSTEM_H
#define RAYLIBSHADER_CAMERASYSTEM_H
#include "entt.hpp"
#include "raylib.h"
class CameraSystem {
public:
    static void update(entt::registry& registry, Camera3D& camera, float deltaTime);
};


#endif //RAYLIBSHADER_CAMERASYSTEM_H
