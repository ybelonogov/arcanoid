//
// Created by alex on 05.09.2021.
//

#ifndef ARCANOID_BRICK_TYPES_H
#define ARCANOID_BRICK_TYPES_H

#include "brick.h"

class brick_types {

};

//1) Неразрушаемые. От них мяч просто отскакивает.
class unkillable : public brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball);
};

//2) Блоки могут быть со спрятанными бонусами: при попадании вертикально вниз падает бонус
class can_give_birth : public brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball);
};

//3) Блоки, увеличивающие скорость шарика при столкновении
class speed_up : public brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball);
};

//4) Блоки имеют уровень здоровья = число попаданий, чтобы блок исчез. За каждое попадание +1 очко игроку, -1 очко здоровья блоку.
class multi_lives : public brick {
public:
    multi_lives(int hp);

    int lives;

    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball);
};


//6) Бонус: появляется двигающий блок, не задевающий при движении остальные блоки (надо проверять коллизии), и живущий до 3 ударов
//
class make_move : public brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball);
};


//7) Бонус: появляется второй шарик, способный оттолкнуться и от первого, и от блоков/стенок
class make_ball : public brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball);
};


#endif //ARCANOID_BRICK_TYPES_H
