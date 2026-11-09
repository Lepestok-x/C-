//
// Created by admin on 11/9/26.
//

#include "Player.h"
Player::Player(Vector3 position, float scale, Color color, Model model) : position(position), scale(scale), color(color), model(model) {}

void Player::update(const float deltaTime) {

}

void Player::move(const Vector3 normalize, const float deltaTime) {
    position.z += normalize.z * velocity * deltaTime;
    position.x += normalize.x * velocity * deltaTime;
}

void Player::render() const {
    DrawModel(model, position, scale, color);
}

