#include "Window.h"

LWindow::LWindow()
{
    //Initialize non-existant window
    mWindow = NULL;
    mMouseFocus = false;
    mKeyboardFocus = false;
    mFullScreen = false;
    mMinimized = false;
    mWidth = 0;
    mHeight = 0;
}

bool LWindow::init(int w, int h)
{
    mWindow = SDL_CreateWindow("Gravity Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN/* | SDL_WINDOW_RESIZABLE*/);

    if (mWindow != NULL)
    {
        mMouseFocus = true;
        mKeyboardFocus = true;
        mWidth = w;
        mHeight = h;

        mWindowID = SDL_GetWindowID(mWindow);

        mShown = true;        
        
    }
    else
    {
        printf("Could not create a window. SDL Error: %s", SDL_GetError());
    }
    

    return mWindow != NULL;
}

void LWindow::handleEvent(SDL_Event &e)
{
    if (e.type == SDL_WINDOWEVENT && e.window.windowID == mWindowID)
    {
        switch (e.window.event)
        {
        case SDL_WINDOWEVENT_SHOWN:
            mShown = true;
            break;

        case SDL_WINDOWEVENT_HIDDEN:
            mShown = false;
            break;

        case SDL_WINDOWEVENT_ENTER:
            mMouseFocus = true;
            break;

        case SDL_WINDOWEVENT_LEAVE:
            mMouseFocus = false;
            break;

        case SDL_WINDOWEVENT_FOCUS_GAINED:
            mKeyboardFocus = true;
            break;

        case SDL_WINDOWEVENT_FOCUS_LOST:
            mKeyboardFocus = false;
            break;

        case SDL_WINDOWEVENT_MINIMIZED:
            mMinimized = true;
            break;

        case SDL_WINDOWEVENT_MAXIMIZED:
            mMinimized = false;
            break;

        case SDL_WINDOWEVENT_RESTORED:
            mMinimized = false;
            break;
        }

    }  
    
}

void LWindow::focus()
{
    if (!mShown)
    {
        SDL_ShowWindow(mWindow);
    }

    SDL_RaiseWindow(mWindow);
    
}

SDL_Renderer* LWindow::createRenderer()
{
    SDL_Renderer* renderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL)
    {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;

        printf("Could not create a renderer. SDL Error: %s", SDL_GetError());
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    return renderer;
}

int LWindow::getWidth()
{
    return mWidth;
}

int LWindow::getHeight()
{
    return mHeight;
}

bool LWindow::hasMouseFocus()
{
    return mMouseFocus;
}

bool LWindow::hasKeyboardFocus()
{
    return mKeyboardFocus;
}

bool LWindow::isMinimized()
{
    return mMinimized;
}

void LWindow::free()
{
    SDL_DestroyWindow(mWindow);
    mWindow = NULL;
}