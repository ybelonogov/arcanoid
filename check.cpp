//
// Created by alex on 05.09.2021.
//

#include "check.h"

void check_touch_paddle(float x, float y, float &dx, float &dy, Sprite sPaddle) {
    if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds())) {
        dy = -(rand() % 5 + 2);
        if (dx != 6) {
            dx = 6;
        }
    }
}

void check_touch_brick(float &dx, float &dy, Sprite &bonus, float x, float y, float &twice_dx, float &twice_dy,
                       float twice_x, float twice_y, bool &move, bool &twice_ball, std::vector<brick *> &block, int n) {
    for (int i = 0; i < block.size(); i++) {
        if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i]->getGlobalBounds())) {
            bool change_flag = twice_ball;
//            cerr<<"change"<< " " <<endl;
            if (block[i]->getBonus(dx, dy, bonus, x, y, move, twice_ball))
                block[i]->setPosition(-100, -200);
            if (twice_ball != change_flag) {
                twice_dx = 6;
                twice_dy = 3;
            }
            dx = -dx;
        }
        if (FloatRect(twice_x + 3, twice_y + 3, 6, 6).intersects(block[i]->getGlobalBounds()) && twice_ball) {
            if (block[i]->getBonus(twice_dx, twice_dy, bonus, twice_x, twice_y, move, twice_ball))
                block[i]->setPosition(-100, -200);
            twice_dx = -twice_dx;

        }
    }
}

void
check_touch_ball(float x, float y, float &dx, float &dy, float twice_x, float twice_y, float &twice_dx, float &twice_dy,
                 Sprite twice_ball) {
    if (FloatRect(x, y, 3, 3).intersects(twice_ball.getGlobalBounds())) {
        dy = -dy;
        twice_dy = -twice_dy;
    }
}

void check_line(float x, float y, float &dx, float &dy, int width, int height, RenderWindow &app) {
    if (x < 0 || x > width) dx = -dx;
    if (y < 0) dy = -dy;
    if (y > height) app.close();
//    if (y > height) dy = -dy;
}

void check_bonus(Sprite &bonus, float x, float y, bool &twice_ball) {
    if (FloatRect(x, y, 4, 4).intersects(bonus.getGlobalBounds()) && y > 250) {
        bonus.setPosition(-10000, 1650);
        twice_ball = false;
    }

}