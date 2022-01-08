#include "Button.h"

Button::Button()
{
    mText = "";

    mTextTexture = new LTexture();
}

Button::~Button()
{
    //Delete everything
}

void Button::init(std::string text, TTF_Font* font, SDL_Renderer* renderer, int x, int y)
{
    mText = text;

    SDL_Color textColor = {255, 255, 255};
    if (!mTextTexture->loadFromRenderedText(text, textColor, font, renderer))
    {
        printf("Failed to render button's text texure! Button: %s\n", text);
    }

    mPosition.x = x;
    mPosition.y = y;

    mouse.inside = false;
    mouse.buttonDown = false;
    mouse.buttonUp = false;
    
}

void Button::handleEvent(SDL_Event &e)
{
    SDL_GetMouseState(&mouse.x, &mouse.y);

    //Check if mouse is in button
    mouse.inside = true;
    //Mouse is left of the button
    if(mouse.x < mPosition.x)
    {
        mouse.inside = false;
    }
    //Mouse is right of the button
    else if(mouse.x > mPosition.x + 90)
    {
        mouse.inside = false;
    }
    //Mouse above the button
    else if(mouse.y < mPosition.y)
    {
        mouse.inside = false;
    }
    //Mouse below the button
    else if(mouse.y > mPosition.y + 22)
    {
        mouse.inside = false;
    }

    //mouse.buttonDown = false;

    if (mouse.inside)
    {

        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            mouse.buttonDown = true;
        }
        
    }

    if (e.type == SDL_MOUSEBUTTONUP)
    {
        mouse.buttonUp = true;
        mouse.buttonDown = false;
    }
    
}

void Button::update()
{
    //Update appearence based on events
}

void Button::render(SDL_Renderer* renderer)
{
    SDL_Rect fillRect = {mPosition.x, mPosition.y, 90, 22};
    SDL_SetRenderDrawColor(renderer, 0x30, 0x30, 0x30, 0xFF);
    if (mouse.inside)
    {
        SDL_SetRenderDrawColor(renderer, 0x50, 0x50, 0x50, 0xFF);
    }
    if (mouse.buttonDown)
    {
        SDL_SetRenderDrawColor(renderer, 0x20, 0x20, 0x20, 0xFF);
    }
    
    
    SDL_RenderFillRect(renderer, &fillRect);

    SDL_Rect textRect = {mPosition.x + 45 - (mTextTexture->getWidth() / 2), mPosition.y + 11 - (mTextTexture->getHeight() / 2), mTextTexture->getWidth(), mTextTexture->getHeight()};
    mTextTexture->render(renderer, &textRect);
}

void Button::terminate()
{
    //Delete everything
    mTextTexture->free();
}

bool Button::gotClicked()
{
    if (mouse.buttonUp && mouse.inside)
    {
        mouse.buttonUp = false;
        return true;
    }
    
    if (mouse.buttonUp)
    {
        mouse.buttonUp = false;
    }

    return false;
}