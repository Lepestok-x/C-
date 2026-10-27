//
// Created by admin on 10/27/26.
//

#ifndef RAYLIB_LAMPSYSTEM_H
#define RAYLIB_LAMPSYSTEM_H
#include "entt.hpp"

class LampSystem {
public:
   static void update(entt::registry& registry, const float deltaTime);
};


#endif //RAYLIB_LAMPSYSTEM_H
