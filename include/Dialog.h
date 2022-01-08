#include "SDL.h"
#include "SDL_ttf.h"

#include "Texture.h"
#include "Button.h"
#include "InputField.h"
#include "Planet.h"
#include "Row.h"

#ifndef DIALOG_H
#define DIALOG_H


enum BUTTONS {
    BUTTONS_OK,
    BUTTONS_CANCEL,
};

enum INPUTS {
    INPUT_POSX,
    INPUT_POSY,
    INPUT_VELX,
    INPUT_VELY,
    INPUT_MASS,
    INPUT_RADIUS,
    INPUT_TOTAL
};

class Dialog
{

public:
    Dialog();

    ~Dialog();

    void init(int posX, int posY, Font font, SDL_Renderer* renderer);

    void handleEvent(SDL_Event &e);

    void update();

    void render(SDL_Renderer* renderer);

    void destroy();

    bool quitRequested();

    LPlanet* createPlanet();

    bool wasSubmitted();

private:
    //Position
    int x, y;

    //The title texture
    LTexture* mTitle;

    //List of input rows
    Row* mRows;

    //List of buttons
    Button* buttons;

    //Has OK bee pressed?
    bool submitted;
};

#endif