//
// Created by alex on 05.09.2021.
//

#ifndef ARCANOID_CHECK_H
#define ARCANOID_CHECK_H

#include <SFML/Graphics.hpp>
#include "BrickTypes.h"

using namespace sf;


void checkTouchPaddle(float x, float y, float &dx, float &dy, Sprite sPaddle);

void checkTouchBrick(float &dx, float &dy, Sprite &bonus, float x, float y, float &twiceDx, float &twiceDy,
                     float twiceX, float twiceY, bool &move, bool &twiceBall, std::vector<std::shared_ptr<Brick>>);

void
checkTouchBall(float x, float y, float &dx, float &dy, float twiceX, float twiceY, float &twiceDx, float &twiceDy,
               Sprite twiceBall);

void checkLine(float x, float y, float &dx, float &dy, int width, int height, RenderWindow &app);

void checkBonus(Sprite &bonus, float x, float y, bool &twiceBall);

#endif //ARCANOID_CHECK_H
