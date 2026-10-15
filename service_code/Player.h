//
// Created by admin on 10/15/26.
//

#ifndef MY_CLEAN_GAME_PLAYER_H
#define MY_CLEAN_GAME_PLAYER_H
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
class Player {
    Vector3 position{};
    Vector3 scale{};
    Color color{};
    float angle{};
public:
    constexpr Player(const Vector3& pos, const Vector3& scale, const Color& color) : position(pos), scale(scale), color(color) {}

    void rotateCube(const float& angle) {
        this->angle = angle;
    }

    void drawPlayer() const {
        rlPushMatrix();
        rlTranslatef(position.x, position.y, position.z);
        rlRotatef(angle, .0f, 1.f, .0f);
        DrawCubeV(Vector3Zero(), scale, color);
        rlPopMatrix();
    }
};
#endif //MY_CLEAN_GAME_PLAYER_H
