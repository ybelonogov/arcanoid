//
// Created by alex on 05.09.2021.
//

#ifndef ARCANOID_CHECK_H
#define ARCANOID_CHECK_H

#include <SFML/Graphics.hpp>
#include "BrickTypes.h"

using namespace sf;

class check {

};

void checkTouchPaddle(float x, float y, float &dx, float &dy, Sprite sPaddle);

void checkTouchBrick(float &dx, float &dy, Sprite &bonus, float x, float y, float &twice_dx, float &twice_dy,
                     float twice_x, float twice_y, bool &move, bool &twice_ball, std::vector<Brick *> &block);

void
checkTouchBall(float x, float y, float &dx, float &dy, float twice_x, float twice_y, float &twice_dx, float &twice_dy,
               Sprite twice_ball);

void checkLine(float x, float y, float &dx, float &dy, int width, int height, RenderWindow &app);

void checkBonus(Sprite &bonus, float x, float y, bool &twice_ball);

#endif //ARCANOID_CHECK_H
