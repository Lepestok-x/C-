//
// Created by admin on 10/15/26.
//

#ifndef MY_CLEAN_GAME_GROUND_H
#define MY_CLEAN_GAME_GROUND_H
#include <complex>
#include <raylib.h>

class Ground {
      Vector3 position{};
      Vector3 scale{};
      Color color{};
      float angle{};
      float distance{};
public:
    constexpr Ground(const Vector3 &position, const Vector3 &scale, const Color& color) {
        this->position = position;
        this->scale = scale;
        this->color = color;
    }
    void drawGround() const {
       DrawCubeV(position, scale, color);
    }
};
#endif
