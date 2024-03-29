#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "error.hpp"
#include "game.hpp"
#include "player.hpp"
#include "zombie.hpp"
#include "gun.hpp"

int main(int argc, char **argv)
{
	int exit_code = 1;

	Game *game = new Game();
	game->init();

	Player *player = new Player(50,50,50,50);
	Zombie *zombie = new Zombie(150,150,50,50);
	Gun *gun = new Gun(player);

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
				return 0;
				break;
			case SDL_MOUSEMOTION:
				game::mouse.x = e.motion.x;
				game::mouse.y = e.motion.y;
				PINF("move moused to (%d, %d)", game::mouse.x, game::mouse.y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button)
				{
				case SDL_BUTTON_LEFT:
					gun->shoot();
					break;
				}
				break;
			}

		}
		game->update();
		player->update();
		gun->update();

		zombie->targetX=player->x;
		zombie->targetY=player->y;
		zombie->update();
	}

	exit_code = 0;
	return exit_code;
}
