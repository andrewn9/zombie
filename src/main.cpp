#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include "main.h"

int main(int argc, char **argv)
{
	int exit_code = 1;

	SDL_Window *win = NULL;
	SDL_Renderer *ren = NULL;

	win = SDL_CreateWindow(
		"zombies",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIN_WIDTH,
		WIN_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);

	const int ren_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	ren = SDL_CreateRenderer(win, -1, ren_flags);

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

	SDL_Event e;
	bool game_running = true;
	while (game_running)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				game_running = false;
				break;
			}
		}

		SDL_RenderClear(ren);
		SDL_RenderPresent(ren);
	}

	exit_code = 0;

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return exit_code;
}
