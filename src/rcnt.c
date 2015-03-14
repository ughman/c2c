#include "rcnt.h"
#include "pcsx.h"

uint16_t RCNT_GetValue(int counter)
{
	return PCSX_Read16(0x1F801100 + counter * 0x10);
}

void RCNT_SetMode(int counter,uint16_t value)
{
	PCSX_Write16(0x1F801104 + counter * 0x10,value);
}

void RCNT_SetTarget(int counter,uint16_t value)
{
	PCSX_Write16(0x1F801108 + counter * 0x10,value);
}
