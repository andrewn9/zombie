/*
 * error.cpp
 *
 * Error logging system
 */

#include <cstdio>

#include "error.hpp"

#define	GAME_NAME	"zombie singular: "

namespace errlog
{
	void pErrorStart()
	{
		std::fprintf(stderr, GAME_NAME ": error: ");
	}

	void pErrorEnd()
	{
		std::fputc('\n', stderr);
	}

	void pInfoStart()
	{
		std::fprintf(stderr, GAME_NAME ": info: ");
	}

	void pInfoEnd()
	{
		pErrorEnd();
	}
}
