//
// Created by alex on 26.09.2021.
//

#include "game.h"

void
game::loadTexture()  {
//    Texture ball, block, paddle, background;
    block.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/block01.png");
    background.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/background.jpg");
    ball.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/ball.png");
    paddle.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/paddle.png");
   //    t1.loadFromFile("block01.png");
//    t2.loadFromFile("background.jpg");
//    t3.loadFromFile("images/ball.png");
//    t4.loadFromFile("images/paddle.png");
//    t5.loadFromFile("block01.png");
    sBackground.setTexture(background);
    sBall.setTexture(ball);
    sPaddle.setTexture(paddle);
    bonus.setTexture(block);
    sBall2.setTexture(ball);

    sPaddle.setPosition(300, HEIGHT - 10);
}

void game::generateField() {
    int n = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
//            blocks[n] = new MultiLives(1);
            int type = rand() % 6;
            if (type == 0) {
                blocks.push_back( new Unkillable);
            }
            if (type == 1) {
                blocks.push_back( new SpeedUp);
            }
            if (type == 2) {
                blocks.push_back( new CanGiveBirth);
            }
            if (type == 3) {
                blocks.push_back( new MultiLives(1 + rand() % 6));
            }
            if (type == 4) {
                blocks.push_back( new MakeMove);
            }
            if (type == 5) {
                blocks.push_back( new MakeBall);
            }
            blocks[n]->setTexture(block);
            blocks[n]->setPosition(i * 43, j * 20);
            n++;
        }
    bonus.setTexture(block);
    bonus.setPosition(-10000, 650);
    moveBlock->setTexture(block);
    moveBlock->setPosition(1000, 220);

}

void game::play() {
    RenderWindow app(VideoMode(WIGHT, HEIGHT), "arkanoid");
    app.setFramerateLimit(60);
    vector<Brick *> tmp;
    tmp.push_back(moveBlock);
    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();
        }
        bonus.move(0, 1);
        x += dx;
        twiceX += twiceDx;
        checkTouchBrick(dx, dy, bonus, x, y, twiceDx, twiceDy, twiceX, twiceY, move_block_active, twiceBall,
                        blocks);
        checkTouchBrick(dx, dy, bonus, x, y, twiceDx, twiceDy, twiceX, twiceY, move_block_active, twiceBall, tmp);
        checkTouchBall(x, y, dx, dy, twiceX, twiceY, twiceDx, twiceDy, sBall2);
        y += dy;
        twiceY += twiceDy;
        checkTouchBrick(dy, dx, bonus, x, y, twiceDy, twiceDx, twiceX, twiceY, move_block_active, twiceBall,
                        blocks);
        checkTouchBrick(dy, dx, bonus, x, y, twiceDy, twiceDx, twiceX, twiceY, move_block_active, twiceBall, tmp);
        checkTouchBall(x, y, dx, dy, twiceX, twiceY, twiceDx, twiceDy, sBall2);
        checkLine(x, y, dx, dy, WIGHT, HEIGHT, app);
        checkLine(twiceX, twiceY, twiceDx, twiceDy, WIGHT, HEIGHT, app);
        if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(pladeSpeed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-pladeSpeed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Escape)) app.close();
        if (Keyboard::isKeyPressed(Keyboard::Space) || start) {
            start = false;
            swap(dx, stopDx);
            swap(dy, stopDy);
            swap(twiceDx, stopTwiceDx);
            swap(twiceDy, stopTwiceDy);
            swap(pladeSpeed, stopPladeSpeed);
        }
        checkTouchPaddle(x, y, dx, dy, sPaddle);
        checkTouchPaddle(twiceX, twiceY, twiceDx, twiceDy, sPaddle);
        sBall.setPosition(x, y);
        app.clear();
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);
        app.draw(bonus);
        checkBonus(bonus, x, y, twiceBall);
        checkBonus(bonus, twiceX, twiceY, twiceBall);
        if (move_block_active) {
            moveBlock->move(0.5, 0);
            app.draw(*moveBlock);
            if (moveBlock->getGlobalBounds().left > WIGHT)
                moveBlock->setPosition(-43, 220);
        }
        if (twiceBall) {
            sBall2.setPosition(twiceX, twiceY);
            app.draw(sBall2);
        } else {
            twiceX = 260;
            twiceY = 250;
            twiceDx = 0;
            twiceDy = 0;
        }
        for (int i = 0; i < blocks.size(); i++)
            app.draw(*blocks[i]);

        app.display();
    }
}
