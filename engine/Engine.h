//
// Created by admin on 10/27/26.
//

#ifndef RAYLIB_ENGINE_H
#define RAYLIB_ENGINE_H
#include "raylib.h"

class  Engine {
public:
    static void init();
    static void update(float deltaTime);
    static void render();
    static void unload();
};
#endif //RAYLIB_ENGINE_H
