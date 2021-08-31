#include <iostream>
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <time.h>

using namespace sf;
using namespace std;
class brick  : public Sprite{
public:
    virtual bool getBonus(float* dx, float* dy, Sprite* bonus, float* x, float* y) = 0;
};
//1) Неразрушаемые. От них мяч просто отскакивает.
class unkillable :public brick{
public:
    bool getBonus(float& dx, float& dy, Sprite& bonus, float* x, float* y){
        return false;
    }
};
//2) Блоки могут быть со спрятанными бонусами: при попадании вертикально вниз падает бонус
class can_give_birth :public brick{
public:
    bool getBonus(float& dx, float& dy, Sprite& bonus, float x, float y){
        bonus.setPosition(x,y);
        return true;
    }
};
//3) Блоки, увеличивающие скорость шарика при столкновении
class speed_up :public brick{
public:
    bool getBonus(float& dx, float& dy, Sprite& bonus, float x, float y){
        dx=dx*2;
        dy=dy*2;
        return true;
    }
};

//4) Блоки имеют уровень здоровья = число попаданий, чтобы блок исчез. За каждое попадание +1 очко игроку, -1 очко здоровья блоку.
class multi_lives :public brick{
public:
    int lives;
    multi_lives(int hp){lives=hp; };
    bool getBonus(float* dx, float* dy, Sprite& bonus, float x, float y){
        lives--;
        if (lives==0){
            return true;
        }
        return false;
    }
};


//6) Бонус: появляется двигающий блок, не задевающий при движении остальные блоки (надо проверять коллизии), и живущий до 3 ударов
//
class make_move :public brick{
public:
//    int lives;
    bool getBonus(float* dx, float* dy, Sprite& bonus, float x, float y,int& move){
//        lives--;
        move+=1;
        return true;
    }
};


//7) Бонус: появляется второй шарик, способный оттолкнуться и от первого, и от блоков/стенок
class make_ball :public brick{
public:
    bool getBonus(float& dx, float& dy, Sprite& bonus, float x, float y,int move,bool& twice_ball){
        twice_ball =true;
        return true;
    }
};
//Shared_ptr
//        Pure Virtual functions
//Inheritance


int main() {
    srand(time(nullptr));

    RenderWindow app(VideoMode(520, 450), "arkanoid");

    app.setFramerateLimit(60);
    Texture t1, t2, t3, t4,t5;
    t1.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/block01.png");
    t2.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/background.jpg");
    t3.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/ball.png");
    t4.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/paddle.png");
//    t5.loadFromFile("/home/alex/Desktop/Cplusplus/arcanoid/images/bonus.png");
    Sprite sBackground(t2), sBall(t3), sPaddle(t4),sBonus(t5);

    sPaddle.setPosition(300, 440);
//  умные указатели для блоков с бонусами
//  бонусы: ускорение, неуязвимость
//  двигать стрелочками
//  пауза пробел
    brick* block[1000];
    int n = 0;
    for (int i = 1; i <=10; i++)
        for (int j = 1; j <= 10; j++) {
            block[n]->setTexture(t1);
            block[n]->setPosition(i * 43, j * 20);
            n++;
        }
    float dx = 6, dy = 3, plade_speed=10;
    float stop_dx = 0, stop_dy = 0, stop_plade_speed=0;
    float x = 300, y = 300;
    bool start=true;
    Sprite bonus;
    bonus.setTexture(t5);
    bonus.setPosition(-100,0);

    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();
        }
        bonus.move(0,3);

        x += dx;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i]->getGlobalBounds())) {
//                block[i]->getBonus(dx,block[i]);
                if (block[i]->getBonus(&dx,&dy,&bonus,&x,&y))
                    block[i]->setPosition(-100, 0);
                dx = -dx;
            }

        y += dy;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i]->getGlobalBounds())) {
                if (block[i]->getBonus(&dx,&dy,&bonus,&x,&y))
                    block[i]->setPosition(-100, 0);
                dy = -dy;
            }

        if (x < 0 || x > 520) dx = -dx;
        if (y < 0) dy = -dy;
        if (y > 450 ) app.close();

        if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(plade_speed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-plade_speed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Space) || start) {
            start= false;
            swap(dx,stop_dx);
            swap(dy,stop_dy);
            swap(plade_speed,stop_plade_speed);
        }
            if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds())) dy = -(rand() % 5 + 2);

        sBall.setPosition(x, y);

        app.clear();
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);
        app.draw(sBonus);
        for (int i = 0; i < n; i++)
            app.draw(*block[i]);

        app.display();
    }

    return 0;
}
