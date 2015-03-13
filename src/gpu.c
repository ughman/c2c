#include "gpu.h"
#include "pcsx.h"

uint32_t GPU_Read(void)
{
	return PCSX_Read32(0x1F801810);
}

void GPU_Write(uint32_t value)
{
	PCSX_Write32(0x1F801810,value);
}

void GPU_WriteAlt(uint32_t value)
{
	PCSX_Write32(0x1F801814,value);
}

uint32_t GPU_GetStatus(void)
{
	return PCSX_Read32(0x1F801814);
}
