/*
 * sound.hpp
 *
 * sick sound system for a sick game
 */

#include <string>

#include <SDL2/SDL_mixer.h>

#pragma once

namespace snd
{
	typedef Mix_Chunk Sfx;

	// Sound effects
	extern Sfx *square;
	extern Sfx *snare;

	// Sound system
	struct SoundSystem{
	private:
		void loadAllSfx();
		void freeAllSfx();
		Sfx *loadSfx(std::string path);
	public:
		SoundSystem();
		~SoundSystem();
		void playSfx(Sfx *sfx);
	};

	extern SoundSystem ss;
}
