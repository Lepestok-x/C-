//
// Created by admin on 10/7/26.
//

#ifndef RAYLIB_COLLISION_H
#define RAYLIB_COLLISION_H
#include "Box.h"
#include "Floor.h"
#include "raylib.h"

class Collision {
      BoundingBox v1{};
      BoundingBox v2{};
public:
    [[nodiscard]] bool collision(const Box& box_v1, const Floor& floor_v2) {
        const auto box_position = box_v1.box();
        const auto floor_position = floor_v2.floor_f();
        const auto floor_size = floor_v2.floorSize();
        const float width = box_v1.boxWidth() / 2.f;
        const float height = box_v1.boxHeight() / 2.f;
        const float depth = box_v1.boxLength() / 2.f;
        const float floorWidth = floor_size.x / 2;
        const float floorHeight = floor_size.y / 2;
        const float floorDepth = floor_size.z / 2;
        v1 = {box_position.x - width, box_position.y - height, box_position.z - depth,
            box_position.x + width, box_position.y + height, box_position.z + depth};
        v2 = {floor_position.x - floorWidth, floor_position.y - floorHeight, floor_position.z - floorDepth,
            floor_position.x + floorWidth, floor_position.y + floorHeight, floor_position.z + floorDepth};
        return CheckCollisionBoxes(v1, v2);
    }
};
#endif //RAYLIB_COLLISION_H
