#include "main.h"

LSimulation simulation;

int main(int argc, char* args[])
{
    if (simulation.init())
    {
        if (simulation.loadMedia())
        {
            simulation.quit = false;

            while (!simulation.quit)
            {
                simulation.handleEvents();

                simulation.update();

                simulation.render();

            }
            
        }
        else
        {
            printf("Could not load media.");
        }
        
    }
    else
    {
        printf("Could not init.");
    }
    

    int code = simulation.terminate();

    return code;
}