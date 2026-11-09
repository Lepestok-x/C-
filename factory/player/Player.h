//
// Created by admin on 11/9/26.
//

#ifndef RAYLIBSHADER_PLAYER_H
#define RAYLIBSHADER_PLAYER_H
#include <raylib.h>
class Player {
    Vector3 position;
    Vector3 size{};
    Color color;
    Model model;
    float scale;
    float velocity{50.f};
public:
    Player(Vector3 position, float scale, Color color, Model model);
    Player() = default;
    void update(float deltaTime);
    void render() const;
    void move(Vector3 normalize, float deltaTime);

    [[nodiscard]] Vector3 getPosition() const {
        return position;
    }
};


#endif //RAYLIBSHADER_PLAYER_H
