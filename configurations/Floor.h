//
// Created by admin on 10/7/26.
//

#ifndef RAYLIB_FLOOR_H
#define RAYLIB_FLOOR_H
#include "raylib.h"

class  Floor {
    Vector3 position{};
    Vector3 size{};
    Color color{};

public:
    Floor(const Vector3& position, const Vector3& size, const Color& color) {
        this->position = position;
        this->size = size;
        this->color = color;
    }
    void drawFloor() const {
        DrawCubeV(this->position, this->size, this->color);
        DrawCubeWiresV(this->position, this->size, this->color);
    }
    [[nodiscard]] Vector3 floor_f() const {
        return this->position;
    }
    [[nodiscard]] Vector3 floorSize() const {
        return this->size;
    }
    void update_color(const Color& color) {
        this->color = color;
    }
};
#endif //RAYLIB_FLOOR_H
