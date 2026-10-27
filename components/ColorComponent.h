//
// Created by admin on 10/23/26.
//

#ifndef RAYLIB_COLORCOMPONENT_H
#define RAYLIB_COLORCOMPONENT_H
#include "raylib.h"

struct ColorComponent {
    Color color{};
    explicit ColorComponent(const Color& color) : color(color) {}
};
#endif //RAYLIB_COLORCOMPONENT_H
