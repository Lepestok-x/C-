//
// Created by admin on 9/30/26.
//

#ifndef MY3DSURVIVALGAME_BULLET_H
#define MY3DSURVIVALGAME_BULLET_H
#include <complex>

class Bullet {
    Vector2 velocity{};
    float angle{};
    float size{};
    Color color{};
    float speed{};
public:
    explicit Bullet(const Vector2 velocity, const float angle, const float size, const Color color, const float speed) {
        this->angle = angle;
        this->size = size;
        this->color = color;
        this->velocity = velocity;
        this->speed = speed;
    }
    void updateBullet(const float& bulletSpeed) {
        velocity.x += std::cos(angle) * bulletSpeed;
        velocity.y += std::sin(angle) * bulletSpeed;
    }
    void drawBullet() const {
        DrawCircleV(velocity, size, color);
    }
    [[nodiscard]] bool windowDelete() const {
        return (velocity.x < size || velocity.x > static_cast<float>(GetScreenWidth())
               || velocity.y < size || velocity.y > static_cast<float>(GetScreenHeight()));
    }
    [[nodiscard]] Vector2 vector2() const {
        return velocity;
    }
    [[nodiscard]] float get_size() const {
        return size;
    }
    void updateMovementBullet(const float& x, const float& y) {
        const float time = GetFrameTime();
        this->velocity.x += x * speed * time;
        this->velocity.y += y * speed * time;
    }
};
#endif //MY3DSURVIVALGAME_BULLET_H
