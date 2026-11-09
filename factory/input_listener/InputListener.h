//
// Created by admin on 11/9/26.
//

#ifndef RAYLIBSHADER_INPUTLISTENER_H
#define RAYLIBSHADER_INPUTLISTENER_H
#include "../player/Player.h"
class InputListener {
public:
    InputListener() = default;
    void input(Player& player, const Camera3D& camera, float deltaTime);
};


#endif //RAYLIBSHADER_INPUTLISTENER_H
