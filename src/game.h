#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <vector>
#include "image.h"

#define WIN_WIDTH   640
#define WIN_HEIGHT  400

class Game {
    public:
        SDL_Window *window;
        SDL_Renderer *renderer;
        const Uint8 *key_state;

        Game();
        ~Game();

        void init();
        void update();
        void draw();

        std::vector<Image*> stuffToDraw;
};

#pragma once