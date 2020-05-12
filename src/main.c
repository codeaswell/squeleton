#define SDL_MAIN_HANDLED

#include "display.h"

bool is_running = false;
int ticksLastFrame;

void process_input()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
    {
        is_running = false;
        break;
    }
    case SDL_KEYDOWN:
    {
        if (event.key.keysym.sym == SDLK_ESCAPE)
            is_running = false;
        if (event.key.keysym.sym == SDLK_UP)
        {
        }
        if (event.key.keysym.sym == SDLK_DOWN)
        {
        }
        if (event.key.keysym.sym == SDLK_RIGHT)
        {
        }
        if (event.key.keysym.sym == SDLK_LEFT)
        {
        }
        break;
    }
    case SDL_KEYUP:
    {
        if (event.key.keysym.sym == SDLK_UP)
        {
        }
        if (event.key.keysym.sym == SDLK_DOWN)
        {
        }
        if (event.key.keysym.sym == SDLK_RIGHT)
        {
        }
        if (event.key.keysym.sym == SDLK_LEFT)
        {
        }
    }
    }
}

void setup()
{
   
}

void update()
{
    int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - ticksLastFrame);
    if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
        SDL_Delay(timeToWait);

    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    ticksLastFrame = SDL_GetTicks();
}

void render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    
    SDL_RenderPresent(renderer);
}

int main(int argc, char **argv)
{
    SDL_SetMainReady();
    is_running = initialize_window();

    setup();

    while (is_running)
    {
        process_input();
        update();
        render();
    }

    destroy_window();

    return 0;
}
