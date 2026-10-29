//
// Created by admin on 10/29/26.
//

#ifndef RAYLIB_ENTITYFACTORY_H
#define RAYLIB_ENTITYFACTORY_H
#include "entt.hpp"
#include "../components/Components.h"
#include "../tags/Tags.h"


class Entity {

public:
    static void player(entt::registry& registry, Vector3 size, Color color);
    static void glass(entt::registry& registry, Vector3 size, Color color);
    static void lamp(entt::registry& registry, Vector3 size, Color color);
};


#endif //RAYLIB_ENTITYFACTORY_H
