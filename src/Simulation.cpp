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

        /*if (TTF_Init() == -1)
        {
            mCode = ERROR_TYPE_TTF;
            success = false;
        }*/
        
        
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

                mPlanets = new LPlanet[PLANETS];
                
                mPlanets[0].init((SCREEN_WIDTH / 2) - 4 * 10, SCREEN_HEIGHT / 2, 20, 0.0, -1.0, 50);
                mPlanets[1].init((SCREEN_WIDTH / 2) + 4 * 10, SCREEN_HEIGHT / 2, 20, 0.0, 1.0, 50);
                mPlanets[2].init((SCREEN_WIDTH / 2) + 330 - 1 * 5, SCREEN_HEIGHT / 2, 10, 0.0, -0.5, 1);
                mPlanets[3].init((SCREEN_WIDTH / 2) + 330 + 1 * 5, SCREEN_HEIGHT / 2, 10, 0.0, -1.5, 1);
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

    return success;
}

ERROR_TYPE LSimulation::terminate()
{
    delete mPlanets;

    mCircle->free();

    SDL_DestroyRenderer(mRenderer);
    mRenderer = NULL;

    mWindow->free();
    mWindow = NULL;

    IMG_Quit();
    //TTF_Quit();
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
        
    }
    
}

void LSimulation::update()
{
    for (int i = 0; i < PLANETS; i++)
    {
        mPlanets[i].resetForce();
    }

    for (int i = 0; i < PLANETS; i++)
    {
        for (int j = 0; j < PLANETS; j++)
        {
            if (i != j)
            {
                LVector2f grav = calculateGravity(mPlanets[i].getMass(), mPlanets[j].getMass(), mPlanets[i].getPos(), mPlanets[j].getPos());

                mPlanets[i].addForce(grav.x, grav.y);
            }
            
        }
        
    }
    
    for (int i = 0; i < PLANETS; i++)
    {
        mPlanets[i].update();
    }
    
}

void LSimulation::render()
{
    if (!mWindow->isMinimized())
    {
        SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(mRenderer);

        for (int i = 0; i < PLANETS; i++)
        {
            mPlanets[i].render(mRenderer, mCircle);
        }
        

        SDL_RenderPresent(mRenderer);
    }
}

LVector2f LSimulation::calculateGravity(int pm1, int pm2, LVector2f ppos1, LVector2f ppos2)
{
    int r_squared = ((ppos2.x - ppos1.x) * (ppos2.x - ppos1.x)) + ((ppos2.y - ppos1.y) * (ppos2.y - ppos1.y));

    double numGrav = 5 * (((double)pm1 * (double)pm2) / (double)r_squared);
    if (numGrav > 100.0)
    {
        numGrav = 1.0;
    }
    

    LVector2f dirVec = {(double)(ppos2.x - ppos1.x), (double)(ppos2.y - ppos1.y)};

    double dist = sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

    LVector2f normedVec = {dirVec.x / dist, dirVec.y / dist};

    LVector2f grav = {normedVec.x * numGrav, normedVec.y * numGrav};

    return grav;
}