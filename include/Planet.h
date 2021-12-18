#include <SDL.h>

#include "Texture.h"

#ifndef PLANET_H
#define PLANET_H

struct LVector2
{
    int x;
    int y;
};

struct LVector2f
{
    long double x;
    long double y;
};

class LPlanet
{

public:
    LPlanet();

    void init(int px, int py, int pradius, double pvelX, double pvelY, int pmass);

    void update();

    void render(SDL_Renderer* renderer, LTexture* texture);

    void addForce(long double x, long double y);

    void resetForce();

    int getMass();

    LVector2f getPos();

private:
    //The position
    int x, y;

    long double xf, yf;

    //The velocity
    long double velX, velY;

    //The acceleration
    long double accX, accY;

    //The radius
    int radius;

    //The planet's mass
    int mMass;

    //The efective force
    LVector2f mForce;

};

#endif