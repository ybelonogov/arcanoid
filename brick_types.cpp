//
// Created by alex on 05.09.2021.
//

#include "brick_types.h"
bool unkillable::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
    return false;
}
bool can_give_birth::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
    if (bonus.getGlobalBounds().top > 650)
        bonus.setPosition(x, y);
    return true;
}
bool speed_up::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
    dx = dx * 1.2;
    dy = dy * 1.2;
    return true;
}
multi_lives::multi_lives(int hp) { lives = hp; };
bool multi_lives::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {

    lives--;
    if (lives == 0) {
        return true;
    }
    return false;
}
bool make_move::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
    move += 1;
    return true;
}
bool make_ball::getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
    twice_ball = true;
    return true;
}