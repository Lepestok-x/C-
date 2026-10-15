#include <chrono>
#include <raylib.h>
#include <ostream>
#include <iostream>
#include <random>
#include <raymath.h>
#include <thread>
#include <vector>
#include "Player.h"

// Хотя, я думаю это работает только с массивами, в дальнейшем узнаем.
static int myId = 0; // Инициализируем за ранее, чтобы не получить мусор!
static int index = 0;
static int randomX = 0;
static int randomY = 0;
int random(const int& number);
int main() {

    // Используем динамический массив.
    std::vector<Player*> players(3); // Задаем за ранее 3 элемента.
    myId = random(1000);
    randomX = random(0xFF);
    randomY = random(0xFF);
    players[0] = new Player(myId, randomX, randomY, 100, 100);
    while (!players.empty()) {
        if(!players.empty()) index++; // инкрементируем, если список имеет не больше 1, сделано для того, чтобы не выйти за предел динамического массива.
        int outsiderId = random(1000);
        randomX = random(0xFF);
        randomY = random(0xFF);
        players[index] = new Player(outsiderId, randomX, randomY, 100, 100);
        for (const Player* player : players) {
            if (player != nullptr) {
                if (player->getId() == myId) {
                    std::cout << "I'm!" << std::endl;
                } else {
                    std::cout << "Outsider!" << std::endl;
                }
            }
        }
        if(players.size() > 2) break; // Выходим из цикла, если дошли до опредленного размера.
        std::this_thread::sleep_for(std::chrono::milliseconds(1 / 60)); // Фиксированное время.
    }
    for (const Player* player : players) delete player;
    return 0;
}

int random(const int& number) {
    if (number <= 0) return 0;
    return std::rand() % number;
}
