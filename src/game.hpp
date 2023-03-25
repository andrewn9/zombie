#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <vector>
#include "image.hpp"
#include "bullet.hpp"


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

        Game();
        ~Game();

        void init();
        void update();
        void draw();

};

namespace game
{
	// timestep
	extern double ts;
	// Input devices
        extern const Uint8 *key_state;
	extern Mouse mouse;
}

extern std::vector<Image*> stuffToDraw;
extern std::vector<Bullet*> stuffToShot;
