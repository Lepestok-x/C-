//
// Created by admin on 11/3/26.
//

#ifndef RAYLIB_MOVEMENTSYSTEM_H
#define RAYLIB_MOVEMENTSYSTEM_H
#include "entt.hpp"
class MovementSystem {
public:
    static void update(entt::registry& registry, float deltaTime);
};
#endif //RAYLIB_MOVEMENTSYSTEM_H
