//
// Created by admin on 10/23/26.
//

#ifndef RAYLIB_POSITIONCOMPONENT_H
#define RAYLIB_POSITIONCOMPONENT_H
#include <raylib.h>
struct PositionComponent {
    Vector3 position{};
   constexpr PositionComponent(const Vector3& position) : position(position) {}
};
#endif //RAYLIB_POSITIONCOMPONENT_H
