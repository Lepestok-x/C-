//
// Created by admin on 9/30/26.
//

#ifndef MY3DSURVIVALGAME_BALL_H
#define MY3DSURVIVALGAME_BALL_H
#include <complex>
#include <raylib.h>

class Ball {
    Vector2 vector2_{};
    float size{};
    float speed{};
public:
   explicit Ball(const Vector2& vector, const float& size, const float& speed):vector2_{vector}, size{size}, speed {speed} {}

   [[nodiscard]] float getX() const {
       return vector2_.x;
   }
   [[nodiscard]] float getY() const {
       return vector2_.y;
   }
   [[nodiscard]] float getSize() const {
       return size;
   }
   [[nodiscard]] Vector2 getVector() const {
       return vector2_;
   }
   void moveUpdate(const float& x, const float& y) {
       const float time = GetFrameTime();
       this->vector2_.x += x * speed * time;
       this->vector2_.y += y * speed * time;
   }
   [[nodiscard]] bool collision(const Ball& ball) const {
       float positionX = ball.getX() - vector2_.x;
       float positionY = ball.getY() - vector2_.y;
       float distance = (positionX * positionX) + (positionY * positionY);
       float radiusBall = size + ball.getSize();
       float radius = (radiusBall * radiusBall);
       return (distance <= radius);
   }
    void drawBall() const {
       DrawCircleV(vector2_, size, RED);
   }
};
#endif //MY3DSURVIVALGAME_BALL_H
