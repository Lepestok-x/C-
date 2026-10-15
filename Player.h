//
// Created by admin on 10/14/26.
//

#ifndef MY_CLEAN_GAME_PLAYER_H
#define MY_CLEAN_GAME_PLAYER_H

class Player {
    int id{};
    int x{}, y{};
    int width{}, height{};
public:
    constexpr Player(const int& id, const int& x, const int& y, const int& width, const int& height) : id(id), x(x), y(y), width(width), height(height) {};
    void setX(const int& x) {
        this->x = x;
    }
    void setY(const int& y) {
        this->y = y;
    }
    void setWidth(const int& width) {
        this->width = width;
    }
    void setHeight(const int& height) {
        this->height = height;
    }
    void setId(const int& id) {
        this->id = id;
    }
    [[nodiscard]] int getId() const {
        return id;
    }
    [[nodiscard]] int getX() const {
        return x;
    }
    [[nodiscard]] int getY() const {
        return y;
    }
    [[nodiscard]] int getWidth() const {
        return width;
    }
    [[nodiscard]] int getHeight() const {
        return height;
    }
};
#endif //MY_CLEAN_GAME_PLAYER_H
