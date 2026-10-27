//
// Created by admin on 10/27/26.
//

#ifndef RAYLIB_PLAYERSYSTEM_H
#define RAYLIB_PLAYERSYSTEM_H
#include "entt.hpp"

class PlayerSystem {
public:
    static void update(entt::registry& registry, float deltaTime);
};
#endif //RAYLIB_PLAYERSYSTEM_H
