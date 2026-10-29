//
// Created by admin on 10/29/26.
//

#ifndef RAYLIB_PHYSICSSYSTEM_H
#define RAYLIB_PHYSICSSYSTEM_H
#include "entt.hpp"


class PhysicsSystem {
public:
    static void update(entt::registry& registry, float deltaTime);
};


#endif //RAYLIB_PHYSICSSYSTEM_H
