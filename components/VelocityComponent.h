//
// Created by admin on 10/23/26.
//

#ifndef RAYLIB_VELOCITYCOMPONENT_H
#define RAYLIB_VELOCITYCOMPONENT_H
struct VelocityComponent {
  float velocity{};
  explicit constexpr VelocityComponent(const float& velocity) : velocity(velocity) {}
};
#endif //RAYLIB_VELOCITYCOMPONENT_H
