#include "common.h"
#include <stdio.h>
#include "emu.h"

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
	EMU_Invoke(0x80049DC4,0);
	SDL_Quit();
	return EXIT_SUCCESS;
}
