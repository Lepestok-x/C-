//
// Created by admin on 10/29/26.
//
#include "entt.hpp"
#include "raylib.h"
#ifndef RAYLIB_ENTITYFACTORY_H
#define RAYLIB_ENTITYFACTORY_H

class Entity {

public:
    static void player(entt::registry& registry, Vector3 size, Color color);
    static void glass(entt::registry& registry, Vector3 size, Color color);
    static void lamp(entt::registry& registry, Vector3 size, Color color);
};


#endif //RAYLIB_ENTITYFACTORY_H
