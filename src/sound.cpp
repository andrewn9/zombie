/*
 * sound.cpp
 *
 * sick sound system for a sick game
 */

#include <iostream>	// For std::string
#include <cstdio>

#include <SDL2/SDL_mixer.h>

#include "dir.hpp"
#include "sound.hpp"

namespace snd
{
	// Sound effects
	Sfx *square;
	Sfx *snare;

	void SoundSystem::loadAllSfx()
	{
		#define	USE_SFX(name)	name = loadSfx(#name ".wav")
		USE_SFX(square);
		USE_SFX(snare);
	}

	void SoundSystem::freeAllSfx()
	{
		#undef USE_SFX
		#define	USE_SFX(name)	Mix_FreeChunk(reinterpret_cast<Mix_Chunk *>(name))
		USE_SFX(square);
		USE_SFX(snare);
	}

	// Loads sfx
	Sfx *SoundSystem::loadSfx(std::string path)
	{
		std::string full_path = DIR_SND + path;
		Mix_Chunk *chunk = Mix_LoadWAV(full_path.c_str());
		if (chunk == nullptr)
			throw 1;
		return reinterpret_cast<Sfx *>(chunk);
	}

	// Plays sfx
	void SoundSystem::playSfx(Sfx *sfx)
	{
		Mix_PlayChannel(-1, reinterpret_cast<Mix_Chunk *>(sfx), 0);
	}

	// Init SoundSystem
	SoundSystem::SoundSystem()
	{
		// Init SDL_Mixer
		constexpr int mix_flags = MIX_INIT_MP3;
		if (!(Mix_Init(mix_flags) & mix_flags))
			throw "failed to init SDL_Mixer";

		// Open audio channels
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			throw "failed to open audio channels";

		// Load sfx
		loadAllSfx();
	}

	// Quit SoundSystem
	SoundSystem::~SoundSystem()
	{
		freeAllSfx();
		Mix_Quit();
	}
}
