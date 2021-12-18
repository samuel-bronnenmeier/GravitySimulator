#include <SDL.h>
//#include <SDL_ttf.h>
#include <SDL_image.h>

#include <stdio.h>
#include <cmath>

#include "Window.h"

#include "Texture.h"

#include "Planet.h"

#ifndef SIMULATION_H
#define SIMULATION_H

enum ERROR_TYPE
{
    ERROR_TYPE_SUCCESS,
    ERROR_TYPE_SDL,
    ERROR_TYPE_WINDOW,
    ERROR_TYPE_IMG,
    ERROR_TYPE_TTF
};

//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 720;

const int PLANETS = 4;

class LSimulation
{

public:

    //Initializes SDL, the window, ...
    bool init();

    //Loads all media we need
    bool loadMedia();

    //Cleans up everything
    ERROR_TYPE terminate();

    //Handle all events
    void handleEvents();

    //Update all elements
    void update();

    //Render everything
    void render();

    //Calculate gravity from two planets
    LVector2f calculateGravity(int pm1, int pm2, LVector2f ppos1, LVector2f ppos2);

    //User requested quit
    bool quit;

private:

    //The main window
    LWindow* mWindow;

    //The renderer
    SDL_Renderer* mRenderer;

    //The circle texture
    LTexture* mCircle;

    //The test planets
    LPlanet* mPlanets;

    //The error code
    ERROR_TYPE mCode;

};

#endif