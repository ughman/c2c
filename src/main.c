#include "emu.h"

int main(int argc,char **argv)
{
	EMU_Init();
	EMU_Invoke(0x80049DC4,0);
}
