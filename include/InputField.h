#include "SDL.h"

#include <string>

#include "Utils.h"


#ifndef INPUTFIELD_H
#define INPUTFIELD_H


class InputField
{
public:

    InputField();

    ~InputField();

    void init(int x_, int y_, int width_, int height_, Font font, SDL_Renderer* renderer);

    void handleEvent(SDL_Event &e);

    void update();

    void render(SDL_Renderer* renderer);

    void terminate();

    void activate();

    void deactivate();

    bool activated();

    int getValue();

private:

    Point mPos;

    int mWidth, mHeight;

    MouseEvent mouse;

    bool mActive;

    std::string mValue;

    LTexture* mValueTexture;

    bool mRenderText;

    Font mFont;

    SDL_Renderer* mRenderer_ref;

};

#endif