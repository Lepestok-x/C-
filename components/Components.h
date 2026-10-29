//
// Created by admin on 10/27/26.
//

#ifndef RAYLIB_COMPONENTS_H
#define RAYLIB_COMPONENTS_H
#include "raylib.h"

struct TransformComponent {
    Vector3 position{};
    Vector3 velocity{};
    Vector3 vel_position{};
    explicit TransformComponent(const Vector3 position) : position(position) {}
};
struct SizeComponent {
    Vector3 size_v{};
    float size{};
    explicit SizeComponent(const Vector3 size_v) : size_v(size_v) {}
    explicit SizeComponent(const float size) : size(size) {}
};
struct VelocityComponent {
    float velocity{};
    explicit VelocityComponent(const float velocity) : velocity(velocity) {}
};
struct ColorComponent {
    Color color{};
    explicit ColorComponent(const Color color) : color(color) {}
};
struct ModelComponent {
    Model model{};
    explicit ModelComponent(const Mesh mesh) {
        this->model = LoadModelFromMesh(mesh);
    }
    ~ModelComponent() {
        if (model.meshCount > 0) {
            UnloadModel(model);
        }
    }
};
struct GravitateComponent {
    Vector3 gravity{};
    explicit GravitateComponent(Vector3 gravity) : gravity(gravity) {}
};
struct PhysicsComponent {
    mutable BoundingBox box{};
};
#endif //RAYLIB_COMPONENTS_H
