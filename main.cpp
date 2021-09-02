#include <iostream>
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <time.h>

using namespace sf;
using namespace std;

class brick : public Sprite {
public:
    virtual bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) = 0;
};

//1) Неразрушаемые. От них мяч просто отскакивает.
class unkillable : public brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
        return false;
    }
};

//2) Блоки могут быть со спрятанными бонусами: при попадании вертикально вниз падает бонус
class can_give_birth : public brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
        if (bonus.getGlobalBounds().top > 650)
//            cerr<< <<endl;
            bonus.setPosition(x, y);
        return true;
    }
};

//3) Блоки, увеличивающие скорость шарика при столкновении
class speed_up : public brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
        dx = dx * 1.2;
        dy = dy * 1.2;
        return true;
    }
};

//4) Блоки имеют уровень здоровья = число попаданий, чтобы блок исчез. За каждое попадание +1 очко игроку, -1 очко здоровья блоку.
class multi_lives : public brick {
public:
    int lives;

    multi_lives(int hp) { lives = hp; };

    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
        lives--;
        if (lives == 0) {
            return true;
        }
        return false;
    }
};


//6) Бонус: появляется двигающий блок, не задевающий при движении остальные блоки (надо проверять коллизии), и живущий до 3 ударов
//
class make_move : public brick {
public:
//    int lives;
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
//        lives--;
        move += 1;
        return true;
    }
};


//7) Бонус: появляется второй шарик, способный оттолкнуться и от первого, и от блоков/стенок
class make_ball : public brick {
public:
    bool getBonus(float &dx, float &dy, Sprite &bonus, float x, float y, bool &move, bool &twice_ball) {
        twice_ball = true;
        return true;
    }
};


//        Pure Virtual functions
//Inheritance
void check_touch_paddle(float x, float y, float &dx, float &dy, Sprite sPaddle) {
    if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds())) {
        dy = -(rand() % 5 + 2);
        if (dx != 6) {
            dx = 6;
        }
    }
}

void check_touch_brick(float &dx, float &dy, Sprite &bonus, float x, float y, float &twice_dx, float &twice_dy,
                       float twice_x, float twice_y, bool &move, bool &twice_ball, vector<brick *> &block, int n) {
    for (int i = 0; i < block.size(); i++) {
        if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i]->getGlobalBounds())) {
            bool change_flag = twice_ball;
//            cerr<<"change"<< " " <<endl;
            if (block[i]->getBonus(dx, dy, bonus, x, y, move, twice_ball))
                block[i]->setPosition(-100, 0);
            if (twice_ball != change_flag) {
                twice_dx = 6;
                twice_dy = 3;
            }
            dx = -dx;
        }
        if (FloatRect(twice_x + 3, twice_y + 3, 6, 6).intersects(block[i]->getGlobalBounds()) && twice_ball) {
            if (block[i]->getBonus(twice_dx, twice_dy, bonus, twice_x, twice_y, move, twice_ball))
                block[i]->setPosition(-100, 0);
            twice_dx = -twice_dx;

        }
    }
}

void
check_touch_ball(float x, float y, float &dx, float &dy, float twice_x, float twice_y, float &twice_dx, float &twice_dy,
                 Sprite twice_ball) {
    if (FloatRect(x, y, 3, 3).intersects(twice_ball.getGlobalBounds())) {
        dy = -dy;
        twice_dy = -twice_dy;
    }
}

void check_line(float x, float y, float &dx, float &dy, int width, int height, RenderWindow &app) {
    if (x < 0 || x > width) dx = -dx;
    if (y < 0) dy = -dy;
    if (y > height) app.close();
//    if (y > height) dy = -dy;
}

void check_bonus(Sprite &bonus, float x, float y, bool &twice_ball) {
    if (FloatRect(x, y, 4, 4).intersects(bonus.getGlobalBounds()) && y > 250) {
        bonus.setPosition(-10000, 1650);
        twice_ball = false;
    }

}

int main() {
    srand(time(nullptr));
    int width = 520, height = 450;
    height = 650;
    RenderWindow app(VideoMode(width, height), "arkanoid");
    app.setFramerateLimit(60);
    Texture t1, t2, t3, t4, t5;
    t1.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/block01.png");
    t2.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/background.jpg");
    t3.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/ball.png");
    t4.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/paddle.png");
    t5.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/block01.png");
    Sprite sBackground(t2), sBall(t3), sPaddle(t4), sBonus(t5), sBall2(t3);
    sPaddle.setPosition(300, height - 10);
//  двигать стрелочками
//  пауза пробел
    vector<brick *> block(1000);
    int n = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
//            block[n] = new multi_lives(1);
            int type = rand() % 6;
            if (type == 0) {
                block[n] = new unkillable;
            }
            if (type == 1) {
                block[n] = new speed_up;
            }
            if (type == 2) {
                block[n] = new can_give_birth;
            }
            if (type == 3) {
                block[n] = new multi_lives(1 + rand() % 6);
            }
            if (type == 4) {
                block[n] = new make_move;
            }
            if (type == 5) {
                block[n] = new make_ball;
            }
//          сдннлать шаред//ненадо

            block[n]->setTexture(t1);
            block[n]->setPosition(i * 43, j * 20);
            n++;
        }
    float dx = 6, dy = 3, plade_speed = 10,
            twice_dx = 0, twice_dy = 0, twice_x = 300, twice_y = 300, stop_dx = 0, stop_dy = 0, stop_twice_dx = 0,
            stop_twice_dy = 0, stop_plade_speed = 0, x = 300, y = 300;
    bool start = true;
    bool twice_ball = false;
    Sprite bonus;
    auto move_block= new multi_lives(1);
    bonus.setTexture(t5);
    bonus.setPosition(-10000, 650);
    move_block->setTexture(t5);
    move_block->setPosition(1000, 220);
    bool move_block_active = false;

    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();
        }
        bonus.move(0, 1);
        x += dx;
        twice_x += twice_dx;
        check_touch_brick(dx, dy, bonus, x, y, twice_dx, twice_dy, twice_x, twice_y, move_block_active, twice_ball, block, n);
        check_touch_ball(x, y, dx, dy, twice_x, twice_y, twice_dx, twice_dy, sBall2);
        y += dy;
        twice_y += twice_dy;
        check_touch_brick(dy, dx, bonus, x, y, twice_dy, twice_dx, twice_x, twice_y, move_block_active, twice_ball, block, n);
        check_touch_ball(x, y, dx, dy, twice_x, twice_y, twice_dx, twice_dy, sBall2);
        check_line(x, y, dx, dy, width, height, app);
        check_line(twice_x, twice_y, twice_dx, twice_dy, width, height, app);
        if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(plade_speed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-plade_speed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Escape)) app.close();
        if (Keyboard::isKeyPressed(Keyboard::Space) || start) {
            start = false;
            swap(dx, stop_dx);
            swap(dy, stop_dy);
            swap(twice_dx, stop_twice_dx);
            swap(twice_dy, stop_twice_dy);
            swap(plade_speed, stop_plade_speed);
        }
        check_touch_paddle(x, y, dx, dy, sPaddle);
        check_touch_paddle(twice_x, twice_y, twice_dx, twice_dy, sPaddle);
        sBall.setPosition(x, y);
        app.clear();
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);
        app.draw(bonus);
        check_bonus(bonus, x, y, twice_ball);
        check_bonus(bonus, twice_x, twice_y, twice_ball);
        if (move_block->getGlobalBounds().left>width){
            move_block->setPosition(-43, 220);
        }
        if (move_block_active) {
            move_block->move(0.5,0);
            app.draw(*move_block);
//            vector <>
//            check_touch_brick(dx, dy, bonus, x, y, twice_dx, twice_dy, twice_x, twice_y, move_block_active, twice_ball, block, n);
//            check_touch_brick(dy, dx, bonus, x, y, twice_dy, twice_dx, twice_x, twice_y, move_block_active, twice_ball, block, n);
        }
        if (twice_ball) {
            sBall2.setPosition(twice_x, twice_y);
            app.draw(sBall2);
        } else {
            twice_x = 260;
            twice_y = 250;
            twice_dx = 0;
            twice_dy = 0;
        }
        for (int i = 0; i < n; i++)
            app.draw(*block[i]);

        app.display();
    }

    return 0;
}
