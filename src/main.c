#include "common.h"
#include <stdio.h>
#include "emu.h"
#include "core.h"

int main(int argc,char **argv)
{
	if (SDL_Init(0) < 0)
	{
		// no logging available because init failed
		fprintf(stderr,"SDL_Init failed: %s\n",SDL_GetError());
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,APP_TITLE,SDL_GetError(),NULL);
		return EXIT_FAILURE;
	}
#ifdef NDEBUG
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_INFO);
#else
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);
#endif
	EMU_Init();
	CORE_Start();
	SDL_Quit();
	return EXIT_SUCCESS;
}
