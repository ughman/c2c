#include "dma.h"
#include "pcsx.h"

void DMA_SetAddress(int channel,uint32_t value)
{
	PCSX_Write32(0x1F801080 + channel * 0x10,value);
}

void DMA_SetBlockData(int channel,uint32_t value)
{
	PCSX_Write32(0x1F801084 + channel * 0x10,value);
}

uint32_t DMA_GetMode(int channel)
{
	return PCSX_Read32(0x1F801088 + channel * 0x10);
}

void DMA_SetMode(int channel,uint32_t value)
{
	PCSX_Write32(0x1F801088 + channel * 0x10,value);
}

uint32_t DMA_GetControlRegister(void)
{
	return PCSX_Read32(0x1F8010F0);
}

void DMA_SetControlRegister(uint32_t value)
{
	PCSX_Write32(0x1F8010F0,value);
}

uint32_t DMA_GetInterruptRegister(void)
{
	return PCSX_Read32(0x1F8010F4);
}

void DMA_SetInterruptRegister(uint32_t value)
{
	PCSX_Write32(0x1F8010F4,value);
}
