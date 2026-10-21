//
// Created by admin on 10/15/26.
//

#ifndef MY_CLEAN_GAME_PLAYER_H
#define MY_CLEAN_GAME_PLAYER_H
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
class Player {
    Vector3 position{};
    Vector3 oldPosition{};
    Vector3 scale{};
    Color color{};
    float angle{};
    float speed{50.f};
    float velocityY{};
public:
    constexpr Player(const Vector3& pos, const Vector3& scale, const Color& color) : position(pos), scale(scale), color(color) {}

    void movePlayer(const Vector3& normalize) {
        this->position = normalize;
    }
    void drawPlayer() const {
        rlPushMatrix();
        rlTranslatef(position.x, position.y, position.z);
        rlRotatef(angle, .0f, 1.f, .0f);
        DrawCubeV(Vector3Zero(), scale, color);
        rlPopMatrix();
    }

    void rotateCameraWithPlayer(Camera3D& camera, const float& distance) const {
        camera.target = position;
        camera.position.x = position.x;
        camera.position.y = position.y + distance;
        camera.position.z = position.z + distance;
    }
    void saveCurrentPosition() {
        this->oldPosition = position;
    }
    void updateVelocity(const float& gravitate, const float& dt) {
        this->position.y += gravitate * dt;
    }
    void updateOldPosition() {
        this->position.y = oldPosition.y;
    }
    void rollbackZ() {
        this->position.x = oldPosition.z;
    }
    void rotateCube(const float& angle) {
        this->angle = angle;
    }
    [[nodiscard]] Vector3 &v_position() {
        return  position;
    }
    [[nodiscard]] Vector3 &v_scale() {
        return scale;
    }
};
#endif //MY_CLEAN_GAME_PLAYER_H
