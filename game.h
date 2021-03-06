//
// Created by alex on 26.09.2021.
//

#ifndef ARCANOID_GAME_H
#define ARCANOID_GAME_H

#include <memory>
#include "check.h"
#include "random"

class game {
private:
    const int WIGHT = 520, HEIGHT = 650;
    Texture ball, block, paddle, background;
    std::vector<std::shared_ptr<Brick>> blocks;
    float dx = 6, dy = 3, pladeSpeed = 10,
            twiceDx = 0, twiceDy = 0, twiceX = 300, twiceY = 300, stopDx = 0, stopDy = 0, stopTwiceDx = 0,
            stopTwiceDy = 0, stopPladeSpeed = 0, x = 300, y = 300;
    bool start = true;
    bool twiceBall = false;

    Sprite bonus, sPaddle, sBall, sBall2, sBackground;
    std::shared_ptr<Brick> moveBlock = make_shared<MultiLives>  (1);
    bool moveBlockActive = false;


public:
    void generateField();

    void play();

    void
    loadTexture();
};

#endif //ARCANOID_GAME_H
