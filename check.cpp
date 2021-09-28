//
// Created by alex on 05.09.2021.
//

#include <memory>
#include "check.h"

void checkTouchPaddle(BallInfo &ball, Sprite sPaddle) {
    if (FloatRect(ball.x, ball.y, 12, 12).intersects(sPaddle.getGlobalBounds())) {
        ball.dy = -(random() % 5 + 2);
        if (ball.dx != 6) {
            ball.dx = 6;
        }
    }
}

void checkTouchBrick(BallInfo &firstBall, Sprite &bonus, BallInfo &secondBall,bool &move, bool &twiceBall,
                     std::vector<std::shared_ptr<Brick>> block) {
    for (int i = 0; i < block.size(); i++) {
        if (FloatRect(firstBall.x + 3, firstBall.y + 3, 6, 6).intersects(block[i]->getGlobalBounds())) {
            bool change_flag = twiceBall;
//            cerr<<"change"<< " " <<endl;

            if (block[i]->getBonus(firstBall, bonus,  move, twiceBall))
                block[i]->setPosition(-100, -200);
            if (twiceBall != change_flag) {
                secondBall.dx = 6;
                secondBall.dy = 3;
            }
            if(firstBall.axis=='y')
                firstBall.dy = -firstBall.dy;
            else
                firstBall.dx = -firstBall.dx;
        }
        if (FloatRect(secondBall.x + 3, secondBall.y + 3, 6, 6).intersects(block[i]->getGlobalBounds()) && twiceBall) {
            if (block[i]->getBonus(secondBall, bonus,move, twiceBall))
                block[i]->setPosition(-100, -200);
            if (secondBall.axis=='y')
                 secondBall.dy = -secondBall.dy;
            else;
                secondBall.dx = -secondBall.dx;


        }
    }
}

void
checkTouchBall(BallInfo &firstBall, BallInfo &SecondBall,
               Sprite twiceBall) {
    if (FloatRect(firstBall.x, firstBall.y, 3, 3).intersects(twiceBall.getGlobalBounds())) {
        firstBall.dy = -firstBall.dy;
        SecondBall.dy = -SecondBall.dy;
    }
}

void checkLine(BallInfo &ball, int width, int height, RenderWindow &app) {
    if (ball.x < 0 || ball.x > width) ball.dx = -ball.dx;
    if (ball.y < 0) ball.dy = -ball.dy;
    if (ball.y > height) app.close();
//    if (ball.y > height) ball.dy = -ball.dy;
}

void checkBonus(Sprite &bonus, BallInfo &ball, bool &twiceBall) {
    if (FloatRect(ball.x, ball.y, 4, 4).intersects(bonus.getGlobalBounds()) && ball.y > 250) {
        bonus.setPosition(-10000, 1650);
        twiceBall = false;
        if(ball.axis=='y')
            ball.dy=-ball.dy;
        else
            ball.dx=-ball.dx;
    }

}