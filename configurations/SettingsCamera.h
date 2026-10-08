//
// Created by admin on 10/7/26.
//

#ifndef RAYLIB_SETTINGSCAMERA_H
#define RAYLIB_SETTINGSCAMERA_H
#include "raylib.h"

class SettingsCamera: public  Camera3D {

public:
    SettingsCamera() : Camera3D() {
        // Settings camera
        this->position = {.x = 0.f, .y = 35.f, .z = 35.f};
        this->target = {.x = 0.f, .y = 0.f, .z = 0.f};
        this->up = {.x = 0.0f, .y = 1.0f, .z = 0.0f};
        this->fovy = 60.f; // corner
        this->projection = CAMERA_PERSPECTIVE;
    }
};
#endif //RAYLIB_SETTINGSCAMERA_H
