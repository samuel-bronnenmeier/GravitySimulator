#include "Planet.h"

LPlanet::LPlanet()
{
    x = 0;
    y = 0;

    velX = 0;
    velY = 0;

    accX = 0;
    accY = 0;

    radius = 0;

    mMass = 0;

    mForce.x = 0;
    mForce.y = 0;

    mForce.x = 0;
    mForce.y = 0;
}

void LPlanet::init(int px, int py, int pradius, double pvelX, double pvelY, int pmass)
{
    x = px;
    y = py;

    xf = x;
    yf = y;

    radius = pradius;

    velX = pvelX;
    velY = pvelY;

    mMass = pmass;
}

void LPlanet::update()
{
    accX = 0;
    accY = 0;

    accX = mForce.x / mMass;
    accY = mForce.y / mMass;

    velX += accX;
    velY += accY;

    xf += velX;
    yf += velY;

    x = xf;
    y = yf;
}

void LPlanet::render(SDL_Renderer* renderer, LTexture* texture)
{
    SDL_Rect dstrect = {x - radius, y - radius, texture->getWidth() / 50 * radius, texture->getHeight() / 50 * radius};

    texture->render(renderer, &dstrect, NULL, 0.0, NULL, SDL_FLIP_NONE);
}

void LPlanet::addForce(long double x, long double y)
{
    mForce.x += x;
    mForce.y += y;
}

void LPlanet::resetForce()
{
    mForce.x = 0;
    mForce.y = 0;
}

int LPlanet::getMass()
{
    return mMass;
}

LVector2f LPlanet::getPos()
{
    return {x, y};
}