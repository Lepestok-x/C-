//
// Created by admin on 11/9/26.
//

#ifndef RAYLIBSHADER_LAMP_H
#define RAYLIBSHADER_LAMP_H
#include "raylib.h"


class Lamp {
    Model model;
    Vector3 position;
    Color color;
    float scale;
public:
    Lamp(Vector3 position, float scale, Color color, Model model);
    Lamp() = default;
    void update(float deltaTime);
    void render() const;
};


#endif //RAYLIBSHADER_LAMP_H
