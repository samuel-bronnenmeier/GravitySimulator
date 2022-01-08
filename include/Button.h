#include "SDL.h"
#include "SDL_ttf.h"

#include <string>

#include "Texture.h"
#include "Utils.h"

#ifndef BUTTON_H
#define BUTTON_H

class Button
{
public:
    Button();

    ~Button();

    void init(std::string text, TTF_Font* font, SDL_Renderer* renderer, int x, int y);

    void handleEvent(SDL_Event &e);

    void update();

    void render(SDL_Renderer* renderer);

    void terminate();

    bool gotClicked();

private:
    std::string mText;

    LTexture* mTextTexture;

    MouseEvent mouse;

    Point mPosition;
};

#endif