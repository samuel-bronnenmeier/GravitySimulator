#include <SDL.h>

#include <stdio.h>

#ifndef WINDOW_H
#define WINDOW_H

//Class for defining SDL windows
class LWindow
{

public:

    //Initializes internals
    LWindow();

    //Creates window
    bool init(int w, int h);

    //Handle window events
    void handleEvent(SDL_Event &e);

    //Get the renderer
    SDL_Renderer* createRenderer();

    //Grab focus
    void focus();

    //Deallocate memory
    void free();

    //Get window dimensions
    int getWidth(), getHeight();

    //Window focii
    bool hasMouseFocus(), hasKeyboardFocus(), isMinimized();

private:

    //Window data
    SDL_Window* mWindow;

    //The window's id
    int mWindowID;

    //Window dimensions
    int mWidth, mHeight;

    //Window focus
    bool mMouseFocus, mKeyboardFocus, mFullScreen, mMinimized, mShown;

};

#endif