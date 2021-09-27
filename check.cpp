//
// Created by alex on 05.09.2021.
//

#include <memory>
#include "check.h"

void checkTouchPaddle(float x, float y, float &dx, float &dy, Sprite sPaddle) {
    if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds())) {
        dy = -(rand() % 5 + 2);
        if (dx != 6) {
            dx = 6;
        }
    }
}

void checkTouchBrick(float &dx, float &dy, Sprite &bonus, float x, float y, float &twiceDx, float &twiceDy,
                     float twiceX, float twiceY, bool &move, bool &twiceBall,
                     std::vector<std::shared_ptr<Brick>> block) {
    for (int i = 0; i < block.size(); i++) {
        if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i]->getGlobalBounds())) {
            bool change_flag = twiceBall;
//            cerr<<"change"<< " " <<endl;

            if (block[i]->getBonus(dx, dy, bonus, x, y, move, twiceBall))
                block[i]->setPosition(-100, -200);
            if (twiceBall != change_flag) {
                twiceDx = 6;
                twiceDy = 3;
            }
            dx = -dx;
        }
        if (FloatRect(twiceX + 3, twiceY + 3, 6, 6).intersects(block[i]->getGlobalBounds()) && twiceBall) {
            if (block[i]->getBonus(twiceDx, twiceDy, bonus, twiceX, twiceY, move, twiceBall))
                block[i]->setPosition(-100, -200);
            twiceDx = -twiceDx;

        }
    }
}

void
checkTouchBall(float x, float y, float &dx, float &dy, float twiceX, float twiceY, float &twiceDx, float &twiceDy,
               Sprite twiceBall) {
    if (FloatRect(x, y, 3, 3).intersects(twiceBall.getGlobalBounds())) {
        dy = -dy;
        twiceDy = -twiceDy;
    }
}

void checkLine(float x, float y, float &dx, float &dy, int width, int height, RenderWindow &app) {
    if (x < 0 || x > width) dx = -dx;
    if (y < 0) dy = -dy;
    if (y > height) app.close();
//    if (y > height) dy = -dy;
}

void checkBonus(Sprite &bonus, float x, float y, bool &twiceBall) {
    if (FloatRect(x, y, 4, 4).intersects(bonus.getGlobalBounds()) && y > 250) {
        bonus.setPosition(-10000, 1650);
        twiceBall = false;
    }

}