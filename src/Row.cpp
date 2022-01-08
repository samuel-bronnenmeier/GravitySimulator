#include "Row.h"

Row::Row()
{
    mPos.x = 0;
    mPos.y = 0;

    mTextTexture = new LTexture();

    mField = new InputField();
}

Row::~Row()
{
    destroy();
}

void Row::init(int x, int y, Font font, SDL_Renderer* renderer, std::string text)
{
    mPos.x = x;
    mPos.y = y;

    if (!mTextTexture->loadFromRenderedText(text, {255, 255, 255}, font.medium, renderer))
    {
        printf("Couldn't load text texture for: %s", text);
    }

    mField->init(mPos.x + (300 - mPos.x) - 90, mPos.y - 2, 90, mTextTexture->getHeight() + 4, font, renderer);

    mField->deactivate();
    
}

void Row::handleEvent(SDL_Event &e)
{
    mField->handleEvent(e);
}

void Row::update()
{
    //Update everything accordingly
    mField->update();
}

void Row::render(SDL_Renderer* renderer)
{
    //Draw a red rect for debugging reason
    // SDL_Rect totalRect = {mPos.x, mPos.y, 300 - mPos.x, mTextTexture->getHeight()};
    // SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    // SDL_RenderDrawRect(renderer, &totalRect);

    //Render the text
    SDL_Rect textRect = {mPos.x, mPos.y, mTextTexture->getWidth(), mTextTexture->getHeight()};
    mTextTexture->render(renderer, &textRect);

    //Render the input field
    mField->render(renderer);
}

void Row::destroy()
{
    //Delete everything
    mTextTexture->free();
    mTextTexture = NULL;

    delete mField;
}

int Row::getValue()
{
    return mField->getValue();
}