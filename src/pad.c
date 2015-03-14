#include "pad.h"
#include "pcsx.h"

uint8_t PAD_Read(void)
{
	return PCSX_Read8(0x1F801040);
}

void PAD_Write(uint8_t value)
{
	PCSX_Write8(0x1F801040,value);
}

uint16_t PAD_GetStatus(void)
{
	return PCSX_Read16(0x1F801044);
}

void PAD_SetControl(uint16_t value)
{
	PCSX_Write16(0x1F80104A,value);
}
