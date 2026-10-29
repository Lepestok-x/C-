//
// Created by admin on 10/29/26.
//

#ifndef RAYLIB_GRAVITYSYSTEM_H
#define RAYLIB_GRAVITYSYSTEM_H
#include "entt.hpp"


class GravitySystem {
public:
    static void update(entt::registry& registry, float deltaTime);
};


#endif //RAYLIB_GRAVITYSYSTEM_H
