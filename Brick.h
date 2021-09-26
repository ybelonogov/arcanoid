//
// Created by alex on 03.09.2021.
//

#ifndef ARCANOID_BRICK_H
#define ARCANOID_BRICK_H

#include <SFML/Graphics/Sprite.hpp>

using namespace sf;
using namespace std;
class Brick: public Sprite{
public:
    virtual bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall) = 0;
};


#endif //ARCANOID_BRICK_H
