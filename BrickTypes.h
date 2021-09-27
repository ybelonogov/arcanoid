//
// Created by alex on 05.09.2021.
//

#ifndef ARCANOID_BRICKTYPES_H
#define ARCANOID_BRICKTYPES_H

#include "Brick.h"


//1) Неразрушаемые. От них мяч просто отскакивает.
class Unkillable : public Brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball);
};

//2) Блоки могут быть со спрятанными бонусами: при попадании вертикально вниз падает бонус
class CanGiveBirth : public Brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball);
};

//3) Блоки, увеличивающие скорость шарика при столкновении
class SpeedUp : public Brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall);
};

//4) Блоки имеют уровень здоровья = число попаданий, чтобы блок исчез. За каждое попадание +1 очко игроку, -1 очко здоровья блоку.
class MultiLives : public Brick {
private:
    int lives;
public:
    MultiLives(int hp);

    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall);

    MultiLives();
};


//6) Бонус: появляется двигающий блок, не задевающий при движении остальные блоки (надо проверять коллизии), и живущий до 3 ударов
//
class MakeMove : public Brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall);
};


//7) Бонус: появляется второй шарик, способный оттолкнуться и от первого, и от блоков/стенок
class MakeBall : public Brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twiceBall);
};


#endif //ARCANOID_BRICKTYPES_H
