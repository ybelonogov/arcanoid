#include <iostream>
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <time.h>

using namespace sf;

int main() {
    srand(time(nullptr));

    RenderWindow app(VideoMode(520, 450), "arkanoid");

    app.setFramerateLimit(60);
    Texture t1, t2, t3, t4;
    t1.loadFromFile("/home/alex/Desktop/Cplusplus/gemes/images/block01.png");
    t2.loadFromFile("/home/alex/Desktop/Cplusplus/gemes/images/background.jpg");
    t3.loadFromFile("/home/alex/Desktop/Cplusplus/gemes/images/ball.png");
    t4.loadFromFile("/home/alex/Desktop/Cplusplus/gemes/images/paddle.png");
    Sprite sBackground(t2), sBall(t3), sPaddle(t4);
    sPaddle.setPosition(300, 440);
//  умные указатели для блоков с бонусами
//  бонусы: ускорение, неуязвимость

//
    Sprite block[1000];
    int n = 0;
    for (int i = 1; i <=10; i++)
        for (int j = 1; j <= 10; j++) {
            block[n].setTexture(t1);
            block[n].setPosition(i * 43, j * 20);
            n++;
        }
    float dx = 6, dy = 3, plade_speed=10;
    float x = 300, y = 300;
    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();
        }

        x += dx;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds())) {
                block[i].setPosition(-100, 0);
                dx = -dx;
            }

        y += dy;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds())) {
                block[i].setPosition(-100, 0);
                dy = -dy;
            }

        if (x < 0 || x > 520) dx = -dx;
        if (y < 0) dy = -dy;
        if (y > 450 ) app.close();
        if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(plade_speed, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-plade_speed, 0);

        if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds())) dy = -(rand() % 5 + 2);

        sBall.setPosition(x, y);

        app.clear();
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);

        for (int i = 0; i < n; i++)
            app.draw(block[i]);

        app.display();
    }

    return 0;
}
