#include <SDL_ttf.h>

#include <cmath>

#include "Planet.h"

#ifndef UTILS_H
#define UTILS_H

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 720;

struct Point {
    int x;
    int y;
};

struct Font {
    TTF_Font* small;
    TTF_Font* medium;
    TTF_Font* big;
};

struct MouseEvent {
    bool inside;
    bool buttonDown;
    bool buttonUp;
    int x;
    int y;
};

class Utils
{

public:

    //Calculate gravity from two planets
    static LVector2f calculateGravity(int pm1, int pm2, LVector2f ppos1, LVector2f ppos2);

};

#endif