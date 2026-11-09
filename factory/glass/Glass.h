//
// Created by admin on 11/9/26.
//

#ifndef RAYLIBSHADER_GLASS_H
#define RAYLIBSHADER_GLASS_H
#include "raylib.h"


class Glass {
    Model model;
    Vector3 position;
    Color color;
    float scale;
public:
    Glass(Vector3 position, float scale, Color color, Model model);
    Glass() = default;
    void update(float deltaTime);
    void render() const;
};

#endif //RAYLIBSHADER_GLASS_H
