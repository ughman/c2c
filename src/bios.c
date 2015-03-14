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
			fprintf(stderr,"Unrecognized BIOS(A0) method: %i:%s\n",T1,PCSX_A0Name(T1));
			return PCSX_HLEA0();
		}
		break;
	case 0xB0:
		switch (T1)
		{
		default:
			fprintf(stderr,"Unrecognized BIOS(B0) method: %i:%s\n",T1,PCSX_B0Name(T1));
			return PCSX_HLEB0();
		}
		break;
	case 0xC0:
		switch (T1)
		{
		default:
			fprintf(stderr,"Unrecognized BIOS(C0) method: %i:%s\n",T1,PCSX_C0Name(T1));
			return PCSX_HLEC0();
		}
		break;
	default:
		fprintf(stderr,"Invalid BIOS routine class.\n");
		abort();
		break;
	}
}
