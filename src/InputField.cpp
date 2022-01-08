#include "InputField.h"

InputField::InputField()
{
    mPos.x = 0;
    mPos.y = 0;

    mActive = false;

    mValue = "";

    mValueTexture = new LTexture();
}

InputField::~InputField()
{
    terminate();
}

void InputField::init(int x_, int y_, int width_, int height_, Font font, SDL_Renderer* renderer)
{
    mPos.x = x_;
    mPos.y = y_;

    mWidth = width_;
    mHeight = height_;

    mActive = false;

    mValue = "std";
    mValueTexture->loadFromRenderedText(mValue, {255, 255, 255}, font.medium, renderer);

    SDL_StartTextInput();

    mRenderText = false;

    mFont = font;

    mRenderer_ref = renderer;
}

void InputField::handleEvent(SDL_Event &e)
{

    //Handle mouse events
    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
    {

        SDL_GetMouseState(&mouse.x, &mouse.y);

        //Check if mouse is in button
        mouse.inside = true;
        //Mouse is left of the button
        if(mouse.x < mPos.x)
        {
            mouse.inside = false;
        }
        //Mouse is right of the button
        else if(mouse.x > mPos.x + 90)
        {
            mouse.inside = false;
        }
        //Mouse above the button
        else if(mouse.y < mPos.y)
        {
            mouse.inside = false;
        }
        //Mouse below the button
        else if(mouse.y > mPos.y + 22)
        {
            mouse.inside = false;
        }

        if (mouse.inside)
        {

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                mouse.buttonDown = true;
            }

            if (e.type == SDL_MOUSEBUTTONUP)
            {
                mouse.buttonUp = true;
                mouse.buttonDown = false;
            }

        }

    }

    //Handle text input !TODO
    if (mActive)
    {

        //Handle special chars like strg + c
        if (e.type == SDL_KEYDOWN)
        {

            //Handle backspace
            if( e.key.keysym.sym == SDLK_BACKSPACE && mValue.length() > 0 )
            {
                //lop off character
                mValue.pop_back();
                mRenderText = true;
            }
            //Handle copy
            else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
            {
                SDL_SetClipboardText( mValue.c_str() );
            }
            //Handle paste
            else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
            {
                mValue = SDL_GetClipboardText();
                mRenderText = true;
            }

        }

        //Handle the SDL textinput events
        if (e.type == SDL_TEXTINPUT)
        {
            
            if (!(SDL_GetModState() & KMOD_CTRL && (e.text.text[ 0 ] == 'c' ||
                                                    e.text.text[ 0 ] == 'C' ||
                                                    e.text.text[ 0 ] == 'v' ||
                                                    e.text.text[ 0 ] == 'V')))
            {
                mValue += e.text.text;
                mRenderText = true;
            }
            

        }
        
        
    }
    

}

void InputField::update()
{
    //Activate when clicked !TODO Move this two layers up
    if (mouse.buttonUp)
    {

        if (mActive)
        {
            deactivate();
        }
        else
        {
            activate();
        }
        
        mouse.buttonUp = false;
    }

    if (mRenderText)
    {

        if( mValue != "" )
        {
            //Render new text
            mValueTexture->loadFromRenderedText(mValue, {255, 255, 255}, mFont.medium, mRenderer_ref);
        }
        //Text is empty
        else
        {
            //Render space texture
            mValueTexture->loadFromRenderedText(" ", {255, 255, 255}, mFont.medium, mRenderer_ref);
        }

    }
    
}

void InputField::render(SDL_Renderer* renderer)
{
    //Render a border for the text field
    SDL_SetRenderDrawColor(renderer, 0xDD, 0xDD, 0xDD, 0xFF);
    SDL_Rect drawRect = {mPos.x - 1, mPos.y - 1, mWidth + 2, mHeight + 2};
    SDL_RenderDrawRect(renderer, &drawRect);

    //Render the actual filled field
    SDL_SetRenderDrawColor(renderer, 0x85, 0x85, 0x85, 0xFF);

    if (mouse.inside)
    {
        SDL_SetRenderDrawColor(renderer, 0x99, 0x99, 0x99, 0xFF);
    }

    if (mActive)
    {
        SDL_SetRenderDrawColor(renderer, 0x70, 0x70, 0x70, 0xFF);
    }
    
    SDL_Rect fillRect = {mPos.x, mPos.y, mWidth, mHeight};
    SDL_RenderFillRect(renderer, &fillRect);

    //Render the text inside
    SDL_Rect renderRect = {mPos.x + 1, mPos.y + (mHeight / 2) - (mValueTexture->getHeight() / 2), mValueTexture->getWidth(), mValueTexture->getHeight()};
    mValueTexture->render(renderer, &renderRect);
}

void InputField::terminate()
{
    //Delete everything
    mValueTexture->free();
}

void InputField::activate()
{
    mActive = true;
}

void InputField::deactivate()
{
    mActive = false;
}

bool InputField::activated()
{
    return mActive;
}

int InputField::getValue()
{
    return std::stoi(mValue);
}