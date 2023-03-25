#include "game.h"

Game::Game()
{
  window = NULL;
  renderer = NULL;
}

void Game::init()
{
	window = SDL_CreateWindow(
		"zombies",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIN_WIDTH,
		WIN_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);

	const int ren_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	renderer = SDL_CreateRenderer(window, -1, ren_flags);
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::draw()
{
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderClear(renderer);

    for (auto image : stuffToDraw) {
        SDL_Surface* surface = image->getImage();
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect* srect = NULL;


		SDL_Rect drect = 
        {
            image->getX(),
            image->getY(),
            image->getWidth(),
            image->getHeight()
        };

		SDL_RenderCopy(renderer, texture, srect, &drect);
    }

	SDL_RenderPresent(renderer);
}
