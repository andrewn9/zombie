#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WIN_WIDTH   640
#define WIN_HEIGHT  400

class Game {
    public:

        SDL_Window *window;
        SDL_Renderer *renderer;

        Game();
        ~Game();

        void init();
        void draw();
};

#pragma once