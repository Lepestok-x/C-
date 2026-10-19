//
// Created by admin on 10/19/26.
//

#ifndef MY_CLEAN_GAME_BTGRAVITATE_H
#define MY_CLEAN_GAME_BTGRAVITATE_H
#include <raylib.h>

#include "Cor.h"
#include "Player.h"

class btGravitate {
    float gravitate{.0f};
public:
    constexpr btGravitate(const float& gravitate) : gravitate(gravitate) {}

    void gravitateBody(Player& player) const {
        const float deltaTime = GetFrameTime();
        player.updateVelocity(gravitate, deltaTime);
    }
};
#endif //MY_CLEAN_GAME_BTGRAVITATE_H
