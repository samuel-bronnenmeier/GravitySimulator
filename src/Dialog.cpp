#include "Dialog.h"

Dialog::Dialog()
{
    x = 0;
    y = 0;

    mTitle = new LTexture();

    buttons = new Button[2];

    mRows = new Row[INPUT_TOTAL];

    submitted = false;
}

Dialog::~Dialog()
{
    destroy();
}

void Dialog::init(int planX, int planY, Font font, SDL_Renderer* renderer)
{
    x = 10;
    y = 10;

    SDL_Color textColor = {255, 255, 255};
    if (!mTitle->loadFromRenderedText("Create new planet", textColor, font.big, renderer))
    {
        printf("Failed to render text texure!");
    }

    //----------Initialize the buttons----------
    buttons[BUTTONS_OK].init("OK", font.medium, renderer, x + 300 - 100 - 120, y + 360);

    buttons[BUTTONS_CANCEL].init("Cancel", font.medium, renderer, x + 300 - 100 - 10, y + 360);


    //----------Initialize all rows----------
    mRows[INPUT_POSX].init(x + 10, y + 40 + 10, font, renderer, "x-Position");
    mRows[INPUT_POSY].init(x + 10, y + 70 + 10, font, renderer, "y-Position");
    mRows[INPUT_VELX].init(x + 10, y + 100 + 10, font, renderer, "x-Velocity");
    mRows[INPUT_VELY].init(x + 10, y + 130 + 10, font, renderer, "y-Velocity");
    mRows[INPUT_MASS].init(x + 10, y + 160 + 10, font, renderer, "Mass");
    mRows[INPUT_RADIUS].init(x + 10, y + 190 + 10, font, renderer, "Radius");

}

void Dialog::handleEvent(SDL_Event &e)
{
    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
    {
        //TODO React to mouse (including shadow?, buttons + textfields)
        for (int i = 0; i < 2; i++)
        {
            buttons[i].handleEvent(e);
        }
        
    }

    for (int i = 0; i < INPUT_TOTAL; i++)
    {
        mRows[i].handleEvent(e);
    }
    
}

void Dialog::update()
{
    //Update according to the earlier events
    if (buttons[BUTTONS_OK].gotClicked())
    {
        
        submitted = true;

    }

    for (int i = 0; i < INPUT_TOTAL; i++)
    {
        if (mRows[i].update())
        {
            
            for (int i = 0; i < INPUT_TOTAL; i++)
            {
                mRows[i].setActivation(false);
            }

            mRows[i].setActivation(true);            
            
        }
    }
    
    
}

void Dialog::render(SDL_Renderer* renderer)
{
    SDL_Rect fillRect = {x, y, 300, 400};

    SDL_SetRenderDrawColor(renderer, 0xA1, 0xA1, 0xA1, 0xFF);

    SDL_RenderFillRect(renderer, &fillRect);

    SDL_Rect titleRect = {x + 10, y + 10, mTitle->getWidth(), mTitle->getHeight()};
    mTitle->render(renderer, &titleRect);

    buttons[BUTTONS_OK].render(renderer);
    buttons[BUTTONS_CANCEL].render(renderer);

    //Render the rows
    for (int i = 0; i < INPUT_TOTAL; i++)
    {
        mRows[i].render(renderer);
    }
    
}

void Dialog::destroy()
{
    delete buttons;

    for (int i = 0; i < INPUT_TOTAL; i++)
    {
        mRows[i].destroy();
    }
    mRows = NULL;
    

    mTitle->free();
    mTitle = NULL;
}

bool Dialog::quitRequested()
{

    return buttons[BUTTONS_CANCEL].gotClicked();

}

LPlanet* Dialog::createPlanet()
{
    //New planet!
    LPlanet* newPlanet = new LPlanet();

    int x_ = mRows[INPUT_POSX].getValue();
    int y_ = mRows[INPUT_POSY].getValue();
    int vx_ = mRows[INPUT_VELX].getValue();
    int vy_ = mRows[INPUT_VELY].getValue();
    int m_ = mRows[INPUT_MASS].getValue();
    int r_ = mRows[INPUT_RADIUS].getValue();

    newPlanet->init(x_, y_, r_, vx_, vy_, m_);

    return newPlanet;
}

bool Dialog::wasSubmitted()
{
    return submitted;
}