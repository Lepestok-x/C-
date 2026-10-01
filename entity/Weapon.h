//
// Created by admin on 9/30/26.
//

#ifndef MY3DSURVIVALGAME_WEAPON_H
#define MY3DSURVIVALGAME_WEAPON_H
#include <numbers>
#include <raylib.h>

class Weapon {
    Rectangle rectangle_;
    Vector2 velocity;
    Color color_;
    float startDegree{};
public:
    explicit Weapon(const Rectangle rectangle, Vector2 vector2, Color color) :
    rectangle_(rectangle), velocity(vector2), color_(color) {

    }
    void drawGunAk47(const float& degrees) {
        const float degree = degrees * (180 / std::numbers::pi_v<float>);
        DrawRectanglePro(rectangle_, velocity, degree, color_);
    }
    void movedXnY(const float& x, const float& y) {
        this->rectangle_.x = x;
        this->rectangle_.y = y;
    }
};
#endif //MY3DSURVIVALGAME_WEAPON_H
