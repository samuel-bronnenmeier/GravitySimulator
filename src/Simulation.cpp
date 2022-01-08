#include "Simulation.h"

bool LSimulation::init()
{
    bool success = true;

    mCode = ERROR_TYPE_SUCCESS;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        mCode = ERROR_TYPE_SDL;
        success = false;

        printf("SDL_Init failed. SDL Error: %s", SDL_GetError());
    }
    else
    {
        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
        {
            mCode = ERROR_TYPE_IMG;
            success = false;

            printf("IMG_Init failed. SDL Error: %s", IMG_GetError());
        }

        if (TTF_Init() == -1)
        {
            mCode = ERROR_TYPE_TTF;
            success = false;
        }
        
        mWindow = new LWindow();

        if(!mWindow->init(SCREEN_WIDTH, SCREEN_HEIGHT))
        {
            mCode = ERROR_TYPE_WINDOW;
            success = false;
            printf("Window could not be created.");
        }
        else
        {
            mRenderer = mWindow->createRenderer();
            if (mRenderer == NULL)
            {
                printf("Could not create renderer. SDL Error: %s", SDL_GetError());
            }
            else
            {
                mCircle = new LTexture();

                mNumOfPlans = PLANETS;

                mPlanets = new LPlanet[mNumOfPlans];
                
                mPlanets[0].init((SCREEN_WIDTH / 2) - 4 * 10, SCREEN_HEIGHT / 2, 20, 0.0, -1.0, 50);
                mPlanets[1].init((SCREEN_WIDTH / 2) + 4 * 10, SCREEN_HEIGHT / 2, 20, 0.0, 1.0, 50);
                mPlanets[2].init((SCREEN_WIDTH / 2) + 330 - 1 * 5, SCREEN_HEIGHT / 2, 10, 0.0, -0.5, 1);
                mPlanets[3].init((SCREEN_WIDTH / 2) + 330 + 1 * 5, SCREEN_HEIGHT / 2, 10, 0.0, -1.5, 1);

                mMouse = new Mouse();

                mMouse->x = 0;
                mMouse->y = 0;
                mMouse->clicked = false;

                mDialog = NULL;
            }
            
            
        }
        
        
    }

    return success;
}

bool LSimulation::loadMedia()
{
    bool success = true;

    if (!mCircle->loadFromFile("res/Circle.png", mRenderer))
    {
        printf("Could not load circle image.");
        success = false;
    }

    mFont.small = TTF_OpenFont("res/Roboto-Regular.ttf", 12);
    if( mFont.small == NULL )
    {
        printf("Failed to load standard font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }

    mFont.medium = TTF_OpenFont("res/Roboto-Regular.ttf", 17);
    if( mFont.medium == NULL )
    {
        printf("Failed to load standard font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }

    mFont.big = TTF_OpenFont("res/Roboto-Regular.ttf", 25);
    if( mFont.big == NULL )
    {
        printf("Failed to load standard font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }

    return success;
}

ERROR_TYPE LSimulation::terminate()
{
    delete mPlanets;

    mCircle->free();

    delete mDialog;

    SDL_DestroyRenderer(mRenderer);
    mRenderer = NULL;

    mWindow->free();
    mWindow = NULL;

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();

    return mCode;
}

void LSimulation::handleEvents()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }

        mWindow->handleEvent(e);

        if (e.type == SDL_MOUSEBUTTONUP)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);

            mMouse->x = x;
            mMouse->y = y;

            mMouse->clicked = true;
        }

        if (mDialog != NULL)
        {
            mDialog->handleEvent(e);
        }
        
    }
    
}

void LSimulation::update()
{

    for (int i = 0; i < mNumOfPlans; i++)
    {
        mPlanets[i].resetForce();
    }

    for (int i = 0; i < mNumOfPlans; i++)
    {
        for (int j = 0; j < mNumOfPlans; j++)
        {
            if (i != j)
            {
                LVector2f grav = Utils::calculateGravity(mPlanets[i].getMass(), mPlanets[j].getMass(), mPlanets[i].getPos(), mPlanets[j].getPos());

                mPlanets[i].addForce(grav.x, grav.y);
            }
            
        }
        
    }
    
    for (int i = 0; i < mNumOfPlans; i++)
    {
        mPlanets[i].update();
    }

    if (mMouse->clicked == true)
    {
        createDialog(mMouse->x, mMouse->y);

        mMouse->clicked = false;
    }

    if (mDialog != NULL)
    {

        mDialog->update();
        
        if (mDialog->quitRequested())
        {
            delete mDialog;

            mDialog = NULL;
        }
        else if (mDialog->wasSubmitted())
        {
            LPlanet* a = new LPlanet[mNumOfPlans];

            for (int i = 0; i < mNumOfPlans; i++)
            {
                a[i] = mPlanets[i];
            }

            delete mPlanets;

            mNumOfPlans++;

            mPlanets = new LPlanet[mNumOfPlans];

            for (int i = 0; i < mNumOfPlans - 1; i++)
            {
                mPlanets[i] = a[i];
            }

            mPlanets[mNumOfPlans - 1] = *mDialog->createPlanet();

            delete mDialog;

            mDialog = NULL;

        }
        
    }    
    
}

void LSimulation::createDialog(int x, int y)
{

    if (mDialog == NULL)
    {

        mDialog = new Dialog();

        mDialog->init(x, y, mFont, mRenderer);
    }

}

void LSimulation::render()
{
    if (!mWindow->isMinimized())
    {
        SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(mRenderer);

        for (int i = 0; i < mNumOfPlans; i++)
        {
            mPlanets[i].render(mRenderer, mCircle);
        }

        if (mDialog != NULL)
        {
            mDialog->render(mRenderer);
        }        

        SDL_RenderPresent(mRenderer);
    }
}