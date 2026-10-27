//
// Created by admin on 10/23/26.
//

#ifndef RAYLIB_MODELCOMPONENT_H
#define RAYLIB_MODELCOMPONENT_H
#include "raylib.h"
struct ModelComponent {
    Model model{};
    explicit ModelComponent(const Mesh& mesh) {
        this->model = LoadModelFromMesh(mesh);
    }
};
#endif //RAYLIB_MODELCOMPONENT_H
