//
// Created by alex on 03.09.2021.
//

#ifndef ARCANOID_BRICK_H
#define ARCANOID_BRICK_H

#include <SFML/Graphics/Sprite.hpp>

using namespace sf;
using namespace std;
class BallInfo{
public:
    float dx;
    float dy;
    float x, y;
    char axis;
    BallInfo(float &x, float &y,float &dx, float &dy)  {
        this->x=x;
        this->y=y;
        this->dx=dx;
        this->dy=dy;
        this->axis='x';
    }

};
class Brick: public Sprite{
public:
    virtual bool getBonus(BallInfo &ball, Sprite &bonus, bool &move, bool &twiceBall) = 0;
};


#endif //ARCANOID_BRICK_H
