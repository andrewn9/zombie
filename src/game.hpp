#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <vector>
#include "image.hpp"

#pragma once

#define WIN_WIDTH   640
#define WIN_HEIGHT  400

struct Mouse{
	int x;
	int y;
};

class Game {
    public:
        SDL_Window *window;
        SDL_Renderer *renderer;

	// Input devices
        const Uint8 *key_state;
	Mouse mouse;

	// timestep
	double ts;

        Game();
        ~Game();

        void init();
        void update();
        void draw();

        std::vector<Image*> stuffToDraw;
};
