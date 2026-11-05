//
// Created by admin on 11/5/26.
//

#ifndef RAYLIBSHADER_COMPONENT_H
#define RAYLIBSHADER_COMPONENT_H

#include <string>
#include <unordered_map>
#include "raylib.h"
struct ModelComponent {
    float scale{};
    Model model{};
    Color color{};
    explicit ModelComponent(const Mesh& mesh, const float scale, const Color color) {
        this->model = LoadModelFromMesh(mesh);
        this->color = color;
        this->scale = scale;
    }
};
struct TransformComponent {
     float velocity{};
     Vector3 position{};
     Vector3 normalize{};
     explicit TransformComponent(const Vector3 position, const float velocity) : position(position), velocity(velocity) {}
};
struct ShaderComponent {
    std::unordered_map<std::string, Shader> shaders;
};
struct UniformComponent {
    float u_time;
};
#endif //RAYLIBSHADER_COMPONENT_H
