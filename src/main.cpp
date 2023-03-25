#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include "game.h"

int main(int argc, char **argv)
{
	int exit_code = 1;

	Game *game = new Game();
	game->init();

	SDL_Event e;
	bool game_running = true;

	while (game_running)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				delete game;
				break;
			}
			game->draw();
		}

	}

	exit_code = 0;
	return exit_code;
}
