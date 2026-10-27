//
// Created by admin on 10/23/26.
//

#ifndef RAYLIB_PLAYERSYSTEM_H
#define RAYLIB_PLAYERSYSTEM_H
#include "../components/PositionComponent.h"
#include "../components/VelocityComponent.h"
#include "../tags/Tags.h"
#include "entt.hpp"
struct PlayerSystem {
   static void update(entt::registry& registry, const float& deltaTime);
};
#endif //RAYLIB_PLAYERSYSTEM_H
