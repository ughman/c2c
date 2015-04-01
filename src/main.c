#include "common.h"
#include "emu.h"

int main(int argc,char **argv)
{
	if (SDL_Init(0) < 0)
	{
		fprintf(stderr,"SDL_Init failed: %s\n",SDL_GetError());
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,APP_TITLE,SDL_GetError(),NULL);
		return EXIT_FAILURE;
	}
	EMU_Init();
	EMU_Invoke(0x80049DC4,0);
	SDL_Quit();
	return EXIT_SUCCESS;
}
