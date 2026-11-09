//
// Created by admin on 11/9/26.
//

#include "Lamp.h"

Lamp::Lamp(const Vector3 position, const float scale, const Color color, const Model model) : position(position), scale(scale), color(color), model(model) {}

void Lamp::update(const float deltaTime) {

}

void Lamp::render() const {
   DrawModel(model, position, scale, color);
}
