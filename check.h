//
// Created by alex on 05.09.2021.
//

#ifndef ARCANOID_CHECK_H
#define ARCANOID_CHECK_H

#include <SFML/Graphics.hpp>
#include "BrickTypes.h"

using namespace sf;


void checkTouchPaddle(BallInfo &ball, Sprite sPaddle);

void checkTouchBrick(BallInfo &firstBall, Sprite &bonus, BallInfo &secondBall,bool &move, bool &twiceBall,
                     std::vector<std::shared_ptr<Brick>> block);

void
checkTouchBall(BallInfo &firstBall, BallInfo &SecondBall,
              Sprite twiceBall);

void checkLine(BallInfo &ball, int width, int height, RenderWindow &app);

void checkBonus(Sprite &bonus, BallInfo &ball, bool &twiceBall);

#endif //ARCANOID_CHECK_H
