//
// Created by admin on 10/19/26.
//

#ifndef MY_CLEAN_GAME_BTGRAVITATE_H
#define MY_CLEAN_GAME_BTGRAVITATE_H
#include <raylib.h>

#include "Cor.h"
#include "Player.h"

class btGravitate {
    float speedGravitate{50.f};
    float gravitate{.0f};
    float velocityY{.0f};
public:
    constexpr btGravitate(const float& gravitate) : gravitate(gravitate) {}

    void gravitateBody(Player& player) {
        const float deltaTime = GetFrameTime();
        if (IsKeyPressed(KEY_SPACE)) velocityY = -gravitate * speedGravitate * deltaTime;
        velocityY += gravitate * deltaTime;
        player.updateVelocity(velocityY, deltaTime);
    }
    void rollbackVelocity() {
        velocityY = .0f;
    }
};
#endif //MY_CLEAN_GAME_BTGRAVITATE_H
