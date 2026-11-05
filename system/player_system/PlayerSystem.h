//
// Created by admin on 11/5/26.
//

#ifndef RAYLIBSHADER_PLAYERSYSTEM_H
#define RAYLIBSHADER_PLAYERSYSTEM_H
#include "entt.hpp"
#include "raylib.h"


class PlayerSystem {
public:
    static void update(entt::registry& registry, const Camera3D& camera, float deltaTime);
};


#endif //RAYLIBSHADER_PLAYERSYSTEM_H
