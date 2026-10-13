#include <raylib.h>
#include <ostream>
#include <iostream>
#include <raymath.h>
static constexpr int screenWidth = 1000.f;
static constexpr int screenHeight = 650.f;
static const char* title = "Raylib";
static const char* fragment = "../shaders/fragment.glsl";
static const char* vertex = "../shaders/vertex.glsl";
int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, title);

    Camera3D camera = {
      .position = {.x = 0, .y = 5.f, .z = 5.f},
      .target = {.x = .0f, .y = .0f, .z = .0f},
      .up = {.x = .0f, .y = 1.f, .z = .0f},
      .fovy = 60.f
    };

    const Shader shader = LoadShader(vertex, fragment);
    if (IsShaderValid(shader)) {
        std::cout << "Shader is initialized" << std::endl;
    } else {
        std::cout << "Shader could not be initialized" << std::endl;
    }
    const Mesh cube = GenMeshCube(2.f, 2.f, 2.f);
    const Model modelCube = LoadModelFromMesh(cube);
    modelCube.materials[0].shader = shader;
    modelCube.materials[0].maps[MATERIAL_MAP_DIFFUSE].color = RED;
    const int timeLoc = GetShaderLocation(shader, "u_time");
    while (!WindowShouldClose()) {
        const auto time = static_cast<float>(GetTime());
        SetShaderValue(shader, timeLoc, &time, SHADER_UNIFORM_FLOAT);
        UpdateCamera(&camera, CAMERA_FREE);
        BeginDrawing();
             ClearBackground(BLACK);
               BeginBlendMode(BLEND_ADD_COLORS);
               BeginMode3D(camera);
               DrawMesh(modelCube.meshes[0], modelCube.materials[0], MatrixIdentity());
               EndMode3D();
             EndBlendMode();
        EndDrawing();
    }
    UnloadModel(modelCube);
    UnloadShader(shader);
    CloseWindow();
    return 0;
}
