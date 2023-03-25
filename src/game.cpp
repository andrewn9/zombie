#include "game.hpp"
#include "error.hpp"

Game::Game()
{
  window = NULL;
  renderer = NULL;
}

void Game::init()
{
	// Create window
	window = SDL_CreateWindow(
		"zombies",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIN_WIDTH,
		WIN_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);

	// Create renderer
	const int ren_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	renderer = SDL_CreateRenderer(window, -1, ren_flags);

	// Calculate game timestep
	{
		SDL_DisplayMode dm;
		int displayIndex = SDL_GetWindowDisplayIndex(window);

		// Monitror refresh rate (set at its default value)
		int refreshRate = 60;

		if (SDL_GetDesktopDisplayMode(displayIndex, &dm) == 0)
			if (dm.refresh_rate != 0)
				refreshRate = dm.refresh_rate;

		ts = 60.0 / refreshRate;
		PERR("%d %lf\n", refreshRate, ts);
	}
	
	// Get keyboard state access
	key_state = SDL_GetKeyboardState(NULL);
}

Game::~Game()
{
	// Free resources
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::update()
{
    draw();
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
