#include <iostream>
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <time.h>
//#include ""
#include "brick.h"
#include "brick_types.h"
#include "check.h"
using namespace sf;
using namespace std;
int main() {
    srand(time(nullptr));
    int width = 520, height = 450;
    height = 650;
    RenderWindow app(VideoMode(width, height), "arkanoid");
    app.setFramerateLimit(60);
    Texture t1, t2, t3, t4, t5;
    t1.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/block01.png");
    t2.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/background.jpg");
    t3.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/ball.png");
    t4.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/paddle.png");
    t5.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/block01.png");
    Sprite sBackground(t2), sBall(t3), sPaddle(t4), sBonus(t5), sBall2(t3);
    sPaddle.setPosition(300, height - 10);
//  двигать стрелочками
//  пауза пробел
//  выход эскейп
    vector<brick *> block(100);
    int n = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
//            block[n] = new multi_lives(1);
            int type = rand() % 6;
            if (type == 0) {
                block[n] = new unkillable;
            }
            if (type == 1) {
                block[n] = new speed_up;
            }
            if (type == 2) {
                block[n] = new can_give_birth;
            }
            if (type == 3) {
                block[n] = new multi_lives(1 + rand() % 6);
            }
            if (type == 4) {
                block[n] = new make_move;
            }
            if (type == 5) {
                block[n] = new make_ball;
            }
//          сдннлать шаред//ненадо

            block[n]->setTexture(t1);
            block[n]->setPosition(i * 43, j * 20);
            n++;
        }
    float dx = 6, dy = 3, plade_speed = 10,
            twice_dx = 0, twice_dy = 0, twice_x = 300, twice_y = 300, stop_dx = 0, stop_dy = 0, stop_twice_dx = 0,
            stop_twice_dy = 0, stop_plade_speed = 0, x = 300, y = 300;
    bool start = true;
    bool twice_ball = false;
    Sprite bonus;
    auto move_block = new multi_lives(1);
    bonus.setTexture(t5);
    bonus.setPosition(-10000, 650);
    move_block->setTexture(t5);
    move_block->setPosition(1000, 220);
    bool move_block_active = false;
//    block.push_back(move_block);
    vector<brick *> tmp;
    tmp.push_back(move_block);
    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();
        }
        bonus.move(0, 1);
        x += dx;
        twice_x += twice_dx;
        check_touch_brick(dx, dy, bonus, x, y, twice_dx, twice_dy, twice_x, twice_y, move_block_active, twice_ball,
                          block, n);
        check_touch_brick(dx, dy, bonus, x, y, twice_dx, twice_dy, twice_x, twice_y, move_block_active, twice_ball, tmp,
                          1);
        check_touch_ball(x, y, dx, dy, twice_x, twice_y, twice_dx, twice_dy, sBall2);
        y += dy;
        twice_y += twice_dy;
        check_touch_brick(dy, dx, bonus, x, y, twice_dy, twice_dx, twice_x, twice_y, move_block_active, twice_ball,
                          block, n);
        check_touch_brick(dy, dx, bonus, x, y, twice_dy, twice_dx, twice_x, twice_y, move_block_active, twice_ball, tmp,
                          1);
        check_touch_ball(x, y, dx, dy, twice_x, twice_y, twice_dx, twice_dy, sBall2);
        check_line(x, y, dx, dy, width, height, app);
        check_line(twice_x, twice_y, twice_dx, twice_dy, width, height, app);
        if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(plade_speed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-plade_speed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Escape)) app.close();
        if (Keyboard::isKeyPressed(Keyboard::Space) || start) {
            start = false;
            swap(dx, stop_dx);
            swap(dy, stop_dy);
            swap(twice_dx, stop_twice_dx);
            swap(twice_dy, stop_twice_dy);
            swap(plade_speed, stop_plade_speed);
        }
        check_touch_paddle(x, y, dx, dy, sPaddle);
        check_touch_paddle(twice_x, twice_y, twice_dx, twice_dy, sPaddle);
        sBall.setPosition(x, y);
        app.clear();
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);
        app.draw(bonus);
        check_bonus(bonus, x, y, twice_ball);
        check_bonus(bonus, twice_x, twice_y, twice_ball);
        if (move_block_active) {
            move_block->move(0.5, 0);
            app.draw(*move_block);
            if (move_block->getGlobalBounds().left > width)
                move_block->setPosition(-43, 220);
        }
        if (twice_ball) {
            sBall2.setPosition(twice_x, twice_y);
            app.draw(sBall2);
        } else {
            twice_x = 260;
            twice_y = 250;
            twice_dx = 0;
            twice_dy = 0;
        }
        for (int i = 0; i < n; i++)
            app.draw(*block[i]);

        app.display();
    }

    return 0;
}
