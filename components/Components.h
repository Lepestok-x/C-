//
// Created by admin on 10/27/26.
//

#ifndef RAYLIB_COMPONENTS_H
#define RAYLIB_COMPONENTS_H
#include "raylib.h"

struct PositionComponent {
    Vector3 position{};
    explicit PositionComponent(const Vector3 position) : position(position) {}
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
struct ShaderComponent {
    Shader shader{};
    explicit ShaderComponent(const char* vrPath, const char* frPath) {
        if (vrPath == nullptr && frPath == nullptr) {
            TraceLog(LOG_FATAL, "Path not specified");
            return;
        }
        this->shader = LoadShader(vrPath, frPath);
        if (shader.id != 0) {
            TraceLog(LOG_ERROR, "Shader not initialized");
        }
    }
    ~ShaderComponent() {
        if (shader.id != -1) {
            UnloadShader(shader);
            TraceLog(LOG_INFO, "Shader unloaded");
        }
    }
};
#endif //RAYLIB_COMPONENTS_H
