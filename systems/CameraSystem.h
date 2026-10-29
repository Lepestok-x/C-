//
// Created by admin on 10/29/26.
//

#ifndef RAYLIB_CAMERASYSTEM_H
#define RAYLIB_CAMERASYSTEM_H
#include "entt.hpp"
#include "raylib.h"

class CameraSystem {
public:
    static void update(entt::registry& registry, Camera& camera, float deltaTime);
};
#endif //RAYLIB_CAMERASYSTEM_H
