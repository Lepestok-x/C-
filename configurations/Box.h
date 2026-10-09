//
// Created by admin on 10/7/26.
//

#ifndef RAYLIB_BOX_H
#define RAYLIB_BOX_H
#include "raylib.h"
#include "rlgl.h"
class Box {
    Vector3 position{};
    Vector3 normal{};
    Vector3 oldPosition{};
    Color color{};
    float width{};
    float height{};
    float length{};
    float angle{}, speed = 50.f;
    float normalSpeed = 1.f;
    float gravitate {-18.9f};
    float velocity {};
public:
    Box(const Vector3& position, const float& width, const float& height, const float& length, const Color& color) {
        this->position = position;
        this->width = width;
        this->height = height;
        this->length = length;
        this->color = color;
     };
    void update(Camera3D& camera3_d, const float& time) {
        if (IsKeyPressed(KEY_SPACE)) {
            std::cout << "Backspace" << std::endl;
            velocity = -gravitate;
        }

        oldPosition = position;
        velocity += gravitate * time;
        position.y += velocity * time;

        normal = {.x = 0.f, .y = 0.f, .z = 0.f,};
        if (IsKeyDown(KEY_W)) normal.z -= normalSpeed;
        if (IsKeyDown(KEY_S)) normal.z += normalSpeed;
        if (IsKeyDown(KEY_D)) normal.x += normalSpeed;
        if (IsKeyDown(KEY_A)) normal.x -= normalSpeed;

        if (IsKeyDown(KEY_Q)) position.y -= speed * time;
        if (IsKeyDown(KEY_E)) position.y += speed * time;

        if (normal.z != 0 || normal.x != 0) {
            normal = Vector3Normalize(normal);
            position.x += normal.x * speed * time;
            position.z += normal.z * speed * time;
        }
        if(IsKeyDown(KEY_LEFT)) {
            angle += speed * time;
        }
        if(IsKeyDown(KEY_RIGHT)) {
            angle -= speed * time;
        }
        camera3_d.target = position;
        camera3_d.position.x = position.x;
        camera3_d.position.y = position.y + 35.f;
        camera3_d.position.z = position.z + 35.f;
    }
    void drawBox() const {
        rlPushMatrix();
        rlTranslatef(position.x, position.y, position.z);
        rlRotatef(angle, 0.f, 1.f, 0.f);
        DrawCube({.x = 0.f, .y = 0.f, .z = 0.f,}, width, height, length, color);
        DrawCubeWires({.x = 0.f, .y = 0.f, .z = 0.f,}, width, height, length, color);
        rlPopMatrix();
    }
    void rollback() {
        position.y = oldPosition.y;
        velocity = 0.f;
    }
    [[nodiscard]] Vector3 box() const {
        return position;
    }
    [[nodiscard]] float boxWidth() const {
        return width;
    }
    [[nodiscard]] float boxHeight() const {
        return height;
    }
    [[nodiscard]] float boxLength() const {
        return length;
    }
};
#endif //RAYLIB_BOX_H
