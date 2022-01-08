#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <stdio.h>
#include <cmath>

#include "Window.h"

#include "Texture.h"

#include "Planet.h"

#include "Utils.h"

#include "Dialog.h"

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

struct Mouse {
    bool clicked;
    int x;
    int y;
};

//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

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

    //Create Dialog field
    void createDialog(int x, int y);

    //User requested quit
    bool quit;

private:

    //The main window
    LWindow* mWindow;

    //The renderer
    SDL_Renderer* mRenderer;

    //The circle texture
    LTexture* mCircle;

    //The planets
    LPlanet* mPlanets;

    //The number of planets
    unsigned int mNumOfPlans;

    //Virtual mouse
    Mouse* mMouse;

    //Dialog (if shown or not)
    Dialog* mDialog;

    //Standard font
    Font mFont;

    //The error code
    ERROR_TYPE mCode;

};

#endif