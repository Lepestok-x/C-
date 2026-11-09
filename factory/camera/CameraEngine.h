//
// Created by admin on 11/9/26.
//

#ifndef RAYLIBSHADER_CAMERAENGINE_H
#define RAYLIBSHADER_CAMERAENGINE_H
#include "raylib.h"
#include "../player/Player.h"


class CameraEngine {
    float wheelDistance{50.f};
    float distance{35.f};
    float angleY{1.5f};
    float angleX{.1f};
    float intensity{.3f};
    Camera3D camera;
public:
    CameraEngine() = default;
    void init();
    void update(const Player& player, float deltaTime);

    [[nodiscard]] Camera3D getCamera() const {
        return camera;
    }
};


#endif //RAYLIBSHADER_CAMERAENGINE_H
