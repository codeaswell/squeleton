#ifndef __DISPLAY_H
#define __DISPLAY_h

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "constants.h"

SDL_Window *window;
SDL_Renderer *renderer;

bool initialize_window()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return false;
    }

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        (FULLSCREEN) ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN);

    if (!window)
    {
        fprintf(stderr, "Error creating Window.\n");
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer)
    {
        fprintf(stderr, "Error creating SDL_Renderer.\n");
        return false;
    }

    SDL_RenderSetLogicalSize(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)
    {
        fprintf(stderr, "Image Initialization error: .\n");
        return false;
    }

    if (TTF_Init() == -1)
    {
        fprintf(stderr, "TTF Initialization error: .\n");
        return false;
    }

    int flags = MIX_INIT_OGG | MIX_INIT_MOD;

    if (Mix_Init(flags) && flags != flags)
    {
        printf("Mix_Init: %s\n", Mix_GetError());
        return false;
    }
    
    return true;
}

void destroy_window()
{
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

#endif