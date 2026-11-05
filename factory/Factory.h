//
// Created by admin on 11/5/26.
//

#ifndef RAYLIBSHADER_FACTORY_H
#define RAYLIBSHADER_FACTORY_H
#include "entt.hpp"
#include "raylib.h"
class Factory {
public:
    static void player(entt::registry& registry, Vector3 position, Vector3 size, float scale, Color color);
    static void glass(entt::registry& registry, Vector3 position, Vector3 size, float scale, Color color);
};


#endif //RAYLIBSHADER_FACTORY_H
