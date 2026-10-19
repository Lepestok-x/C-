//
// Created by admin on 10/19/26.
//

#ifndef MY_CLEAN_GAME_BODYCOLLISION_H
#define MY_CLEAN_GAME_BODYCOLLISION_H
#include <raylib.h>
#include <raymath.h>
class  BodyCollision {

public:
    constexpr BodyCollision() = default;

    [[nodiscard]] BoundingBox rectangleBody(Vector3& position, Vector3& size) const {
        constexpr float divide = 2.f;
        const Vector3 min = {.x = position.x - size.x / divide, .y = position.y - size.y / divide, .z = position.z - size.z / divide};
        const Vector3 max = {.x = position.x + size.x / divide, .y = position.y + size.y / divide, .z = position.z + size.z / divide};
        return {.min = min, .max = max};
    }
    [[nodiscard]] bool rectangle(const BoundingBox& v1, const BoundingBox& v2) const {
        const bool collisionX = (v1.min.x <= v2.max.x) && (v1.max.x >= v2.min.x);
        const bool collisionY = (v1.min.y <= v2.max.y) && (v1.max.y >= v2.min.y);
        const bool collisionZ = (v1.min.z <= v2.max.z) && (v1.max.z >= v2.min.z);
        return (collisionX && collisionY && collisionZ);
    }
};
#endif //MY_CLEAN_GAME_BODYCOLLISION_H
