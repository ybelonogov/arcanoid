//
// Created by alex on 05.09.2021.
//

#include "BrickTypes.h"

bool Unkillable::getBonus(BallInfo &ball, Sprite &bonus, bool &move, bool &twiceBall)  {
    return false;
}

bool CanGiveBirth::getBonus(BallInfo &ball, Sprite &bonus, bool &move, bool &twiceBall)  {
    if (bonus.getGlobalBounds().top > 650)
        bonus.setPosition(ball.x, ball.y);
    return true;
}

bool SpeedUp::getBonus(BallInfo &ball, Sprite &bonus, bool &move, bool &twiceBall)  {
    ball.dx = ball.dx * 1.2;
    ball.dy = ball.dy * 1.2;
    return true;
}

MultiLives::MultiLives(int hp) { lives = hp; };

bool MultiLives::getBonus(BallInfo &ball, Sprite &bonus, bool &move, bool &twiceBall)  {

    lives--;
    if (lives == 0) {
        return true;
    }
    return false;
}

bool MakeMove::getBonus(BallInfo &ball, Sprite &bonus, bool &move, bool &twiceBall)  {
    move += 1;
    return true;
}

bool MakeBall::getBonus(BallInfo &ball, Sprite &bonus, bool &move, bool &twiceBall)  {
    twiceBall = true;
    return true;
}