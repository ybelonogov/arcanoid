#include <iostream>
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <time.h>
#include "check.h"
#include "game.h"

using namespace sf;
using namespace std;
int main() {
    srand(time(nullptr));
    game arcanoid;
    arcanoid.loadTexture();
    arcanoid.generateField();
    arcanoid.play();
}