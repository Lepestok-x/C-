//
// Created by admin on 10/27/26.
//

#ifndef RAYLIB_PLAYERSYSTEM_H
#define RAYLIB_PLAYERSYSTEM_H
#include "entt.hpp"
#include "raylib.h"

class PlayerSystem {
public:
    static void update(entt::registry &registry, const Camera3D &camera);
};
#endif //RAYLIB_PLAYERSYSTEM_H
