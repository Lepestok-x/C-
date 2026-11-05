//
// Created by admin on 11/5/26.
//

#ifndef RAYLIBSHADER_MOVEMENTSYSTEM_H
#define RAYLIBSHADER_MOVEMENTSYSTEM_H
#include "entt.hpp"
class MovementSystem {
public:
    static void update(entt::registry& registry, float deltaTime);
};


#endif //RAYLIBSHADER_MOVEMENTSYSTEM_H
