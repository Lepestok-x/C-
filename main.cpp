#include <iostream>

#include "raylib.h"
#include "entity/Ball2D.h"
#include "entity/Weapon.h"
float timeLiner = 0.135;
float inrecremtnTimer = 0.0;
static Ball2D ball2_d = Ball2D{100, 100, 15, GREEN};
static Weapon weapon = Weapon{Rectangle{100,100, 100, 8}, Vector2{0.0f, 6.5f}, RED};
static std::vector<Ball> balls;
int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(1000,650, "Cube");
    for (int i = 0; i < 5; i++) {
        balls.emplace_back(Vector2{350 + (static_cast<float>(i) * 80.f), 350}, 15, 15);
    }
    while (!WindowShouldClose()) {
        const float mouseX = static_cast<float>(GetMouseX()) - ball2_d.x();
        const float mouseY = static_cast<float>(GetMouseY()) - ball2_d.y();
        const float angle = std::atan2(mouseY, mouseX);
        if (inrecremtnTimer >= 0.0f) {
            inrecremtnTimer -= GetFrameTime();
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && inrecremtnTimer <= 0.0f) {
            ball2_d.fire(angle, 5, RED);
            inrecremtnTimer = timeLiner;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        weapon.drawGunAk47(angle);
        weapon.movedXnY(ball2_d.x(), ball2_d.y());
        ball2_d.updateBall(300);
        ball2_d.update(300);
        ball2_d.drawCircle();
        ball2_d.drawBullet();
        ball2_d.clearBullets();
        for (int i = 0 ; i < balls.size(); i++) {
            for (int j = i + 1; j < balls.size(); j++) {
                Ball& ballA = balls[i];
                Ball& ballB = balls[j];
                if (ballA.collision(ballB)) {
                    Vector2 delta = {ballA.getVector().x - ballB.getVector().x, ballA.getVector().y - ballB.getVector().y};
                    ballA.moveUpdate(delta.x, delta.y);
                    ballB.moveUpdate(-delta.x, -delta.y);
                }
            }
        }
        for (Ball& ball : balls) {
            if (ball2_d.collision(ball)) {
                Vector2 delta = {ball.getVector().x - ball2_d.x(), ball.getVector().y - ball2_d.y()};
                ball.moveUpdate(delta.x, delta.y);
            }
            if(ball2_d.bulletCollision(ball)) {
                Vector2 delta = {ball.getVector().x - ball2_d.getVelocityBullet().x, ball.getVector().y - ball2_d.getVelocityBullet().y};
                ball2_d.updatePositionBullet(-delta.x, -delta.y);
            }
            ball.drawBall();
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}