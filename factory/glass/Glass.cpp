//
// Created by admin on 11/9/26.
//

#include "Glass.h"
Glass::Glass(Vector3 position, float scale, Color color, Model model) : position(position), scale(scale), color(color), model(model) {}


void Glass::update(float deltaTime) {

}

void Glass::render() const {
    DrawModel(model, position, scale, color);
}
