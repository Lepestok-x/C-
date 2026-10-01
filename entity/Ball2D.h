//
// Created by admin on 9/30/26.
//
#ifndef MY3DSURVIVALGAME_BALL2D_H
#define MY3DSURVIVALGAME_BALL2D_H
#include <vector>

#include "Ball.h"
#include "Bullet.h"
#include "raylib.h"

class Ball2D {
    float size{};
    int distance{};
    Color color_{};
    std::vector<Bullet> bullets_;
    Vector2 velocity{};

public:
    Ball2D(const float ballX, const float ballY, const float size, const Color color_) {
        this->velocity.x = ballX;
        this->velocity.y = ballY;
        this->size = size;
        this->color_ = color_;
    }

    [[nodiscard]] float x() const { return this->velocity.x; }
    [[nodiscard]] float y() const { return this->velocity.y; }

    void fire(const float& angle, const float& size, Color color) {
        bullets_.emplace_back(velocity, angle, size, color, 300);
    }

    void updateBall(const float& speed) {
        const float time = GetFrameTime();
        if (IsKeyDown(KEY_W)) velocity.y -= speed * time;
        if (IsKeyDown(KEY_S)) velocity.y += speed * time;
        if (IsKeyDown(KEY_A)) velocity.x -= speed * time;
        if (IsKeyDown(KEY_D)) velocity.x += speed * time;
    }

    void update(const float& speed) {
        for (Bullet &bullet: bullets_) {
            bullet.updateBullet(speed * GetFrameTime());
        }
    }

    void drawCircle() const {
        DrawCircleV(velocity, size, color_);
    }

    void drawBullet() {
        for (Bullet &bullet: bullets_) {
            bullet.drawBullet();
        }
    }
    void clearBullets() {
        for (Bullet& bullet: bullets_) {
            if (bullet.windowDelete()) {
                if (!bullets_.empty()) {
                    bullets_.erase(bullets_.begin());
                }
            }
        }
    }
    [[nodiscard]] float getX() const {
        return velocity.x;
    }
    [[nodiscard]] float getY() const {
        return  velocity.y;
    }
    [[nodiscard]] bool collision(const Ball& ball) const {
        float positionX = ball.getX() - velocity.x;
        float positionY = ball.getY() - velocity.y;
        float distance = (positionX * positionX) + (positionY * positionY);
        float radiusBall = size + ball.getSize();
        float radius = (radiusBall * radiusBall);
        return (distance <= radius);
    }
    [[nodiscard]] bool bulletCollision(const Ball& ball) const {
        for (const Bullet& bullet : bullets_) {
            float positionX = ball.getX() - bullet.vector2().x;
            float positionY = ball.getY() - bullet.vector2().y;
            float distance = (positionX * positionX) + (positionY * positionY);
            float radiusBall = bullet.get_size() + ball.getSize();
            float radius = (radiusBall * radiusBall);
            return (distance <= radius);
        }
        return false;
    }

    void updatePositionBullet(const float& x, const float& y) {
        for (Bullet& bullet : bullets_) {
          bullet.updateMovementBullet(x, y);
        }
    }
    [[nodiscard]] Vector2 getVelocityBullet() const {
        for (const Bullet& bullet: bullets_) {
            if (!bullets_.empty()) {
                return bullet.vector2();
            }
        }
        return velocity;
    }
};


#endif //MY3DSURVIVALGAME_BALL2D_H
