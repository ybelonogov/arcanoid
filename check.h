//
// Created by alex on 05.09.2021.
//

#ifndef ARCANOID_CHECK_H
#define ARCANOID_CHECK_H

#include <SFML/Graphics.hpp>
#include "brick.h"

using namespace sf;

class check {

};

void check_touch_paddle(float x, float y, float &dx, float &dy, Sprite sPaddle);

void check_touch_brick(float &dx, float &dy, Sprite &bonus, float x, float y, float &twice_dx, float &twice_dy,
                       float twice_x, float twice_y, bool &move, bool &twice_ball, std::vector<brick *> &block, int n);

void
check_touch_ball(float x, float y, float &dx, float &dy, float twice_x, float twice_y, float &twice_dx, float &twice_dy,
                 Sprite twice_ball);

void check_line(float x, float y, float &dx, float &dy, int width, int height, RenderWindow &app);

void check_bonus(Sprite &bonus, float x, float y, bool &twice_ball);

#endif //ARCANOID_CHECK_H
