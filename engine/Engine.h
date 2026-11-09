//
// Created by admin on 11/9/26.
//

#ifndef RAYLIBSHADER_ENGINE_H
#define RAYLIBSHADER_ENGINE_H
#include "raylib.h"
#include "../factory/camera/CameraEngine.h"
#include "../factory/glass/Glass.h"
#include "../factory/input_listener/InputListener.h"
#include "../factory/lamp/Lamp.h"
#include "../factory/player/Player.h"


class Engine {
    Model playerModel, glassModel, lampModel;
    Player player;
    Glass glass;
    Lamp lamp;
    InputListener input_listener;
    CameraEngine camera_engine;
public:
    Engine() = default;
    ~Engine();
    void init();
    void update(float deltaTime);
    void render() const;
};


#endif //RAYLIBSHADER_ENGINE_H
