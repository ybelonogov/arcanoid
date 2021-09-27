//
// Created by alex on 05.09.2021.
//

#include "BrickTypes.h"

bool Unkillable::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall) {
    return false;
}

bool CanGiveBirth::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall) {
    if (bonus.getGlobalBounds().top > 650)
        bonus.setPosition(x, y);
    return true;
}

bool SpeedUp::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall) {
    dx = dx * 1.2;
    dy = dy * 1.2;
    return true;
}

MultiLives::MultiLives(int hp) { lives = hp; };

bool MultiLives::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall) {

    lives--;
    if (lives == 0) {
        return true;
    }
    return false;
}

bool MakeMove::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall) {
    move += 1;
    return true;
}

bool MakeBall::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall) {
    twiceBall = true;
    return true;
}