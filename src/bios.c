#include "bios.h"
#include <stdio.h>
#include <stdlib.h>
#include "pcsx.h"
#include "emu.h"

uint32_t BIOS_Execute(uint32_t address)
{
	switch (address)
	{
	case 0xA0:
		switch (T1)
		{
		default:
			return PCSX_ExecuteOnce(0xA0);
		}
		break;
	case 0xB0:
		switch (T1)
		{
		default:
			return PCSX_ExecuteOnce(0xB0);
		}
		break;
	case 0xC0:
		switch (T1)
		{
		default:
			return PCSX_ExecuteOnce(0xC0);
		}
		break;
	default:
		fprintf(stderr,"Invalid BIOS routine class.\n");
		abort();
		break;
	}
}
