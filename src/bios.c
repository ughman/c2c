#include "bios.h"
#include <stdio.h>
#include <stdlib.h>
#include "pcsx.h"
#include "emu.h"
#include "cop0.h"

uint32_t BIOS_MemCpy(uint32_t dest,uint32_t src,int32_t len)
{
	if (!dest)
		return dest;
	if (len < 0)
		return dest;
	for (uint32_t i = 0;i < len;i++)
		EMU_Write8(dest + i,EMU_ReadU8(src + i));
	return dest;
}

uint32_t BIOS_MemSet(uint32_t dest,uint8_t value,int32_t len)
{
	if (!dest)
		return dest;
	if (len < 0)
		return dest;
	for (uint32_t i = 0;i < len;i++)
		EMU_Write8(dest + i,value);
	return dest;
}

#define CASE_METHOD(id,name) case id: EMU_NativeCall((void *)name); return RA

uint32_t BIOS_Execute(uint32_t address)
{
	switch (address)
	{
	case 0xA0:
		switch (T1)
		{
		CASE_METHOD(0x2A,BIOS_MemCpy);
		CASE_METHOD(0x2B,BIOS_MemSet);
		default:
			fprintf(stderr,"Unrecognized BIOS(A0) method: %i:%s\n",T1,PCSX_A0Name(T1));
			return PCSX_HLEA0();
		}
		break;
	case 0xB0:
		switch (T1)
		{
		case 0x17:
			EMU_LoadRegisters();
			PCSX_ExecuteCOP(0,16 << 21);
			return COP0_GetRegister(14);
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

#undef CASE_METHOD
