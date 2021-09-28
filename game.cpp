//
// Created by alex on 26.09.2021.
//

#include "game.h"

void
game::loadTexture() {
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
            int type = random() % 6;
            if (type == 0) {
                blocks.push_back(make_shared<Unkillable>());
            }
            if (type == 1) {
                blocks.push_back(make_shared<SpeedUp>());
            }
            if (type == 2) {
                blocks.push_back(make_shared<CanGiveBirth>());
            }
            if (type == 3) {
                blocks.push_back(make_shared<MultiLives>(random()%6 +1));
            }
            if (type == 4) {
                blocks.push_back(make_shared<MakeMove>());
            }
            if (type == 5) {
                blocks.push_back(make_shared<MakeBall>());
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
    std::vector<std::shared_ptr<Brick>> moveBlocks;
    moveBlocks.push_back(moveBlock);
    BallInfo firstBall(x,y,dx,dy);
    BallInfo secondBall(twiceX,twiceY,twiceDx,twiceDy);
    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();
        }
        bonus.move(0, 1);
        firstBall.x += firstBall.dx;
        secondBall.x+= secondBall.dx;
        checkTouchBrick(firstBall, bonus, secondBall, moveBlockActive, twiceBall,
                        blocks);
        checkTouchBrick(firstBall, bonus, secondBall, moveBlockActive, twiceBall, moveBlocks);
        firstBall.axis='y';
        secondBall.axis='y';
        checkTouchBall(firstBall, secondBall, sBall2);
        firstBall.y += firstBall.dy;
        secondBall.y += secondBall.dy;
        checkTouchBrick(firstBall, bonus, secondBall, moveBlockActive, twiceBall,
                        blocks);
        checkTouchBrick(firstBall, bonus, secondBall, moveBlockActive, twiceBall, moveBlocks);
        firstBall.axis='x';
        secondBall.axis='x';
        checkTouchBall(firstBall, secondBall, sBall2);
        checkLine(firstBall, WIGHT, HEIGHT, app);
        checkLine(secondBall, WIGHT, HEIGHT, app);
        if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(pladeSpeed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-pladeSpeed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Escape)) app.close();
        if (Keyboard::isKeyPressed(Keyboard::Space) || start) {
            start = false;
            swap(firstBall.dx, stopDx);
            swap(firstBall.dy, stopDy);
            swap(secondBall.dx, stopTwiceDx);
            swap(secondBall.dy, stopTwiceDy);
            swap(pladeSpeed, stopPladeSpeed);
        }
        checkTouchPaddle(firstBall, sPaddle);
        checkTouchPaddle(secondBall, sPaddle);
        sBall.setPosition(firstBall.x, firstBall.y);
        app.clear();
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);
        app.draw(bonus);
        checkBonus(bonus, firstBall, twiceBall);
        checkBonus(bonus, secondBall, twiceBall);
        if (moveBlockActive) {
            moveBlock->move(0.5, 0);
            app.draw(*moveBlock);
            if (moveBlock->getGlobalBounds().left > WIGHT)
                moveBlock->setPosition(-43, 220);
        }
        if (twiceBall) {
            sBall2.setPosition(secondBall.x, secondBall.y);
            app.draw(sBall2);
        } else {
            secondBall.x = 260;
            secondBall.y = 250;
            secondBall.dx= 0;
            secondBall.dy = 0;
        }
        for (int i = 0; i < blocks.size(); i++)
            app.draw(*blocks[i]);

        app.display();
    }
}
