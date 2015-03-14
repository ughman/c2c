#include "irq.h"
#include "pcsx.h"

extern uint16_t IRQ_GetStatus(void)
{
	return PCSX_Read16(0x1F801070);
}

extern void IRQ_AcknowledgeBits(uint16_t value)
{
	return PCSX_Write16(0x1F801070,value);
}

uint16_t IRQ_GetMask(void)
{
	return PCSX_Read16(0x1F801074);
}

void IRQ_SetMask(uint16_t value)
{
	PCSX_Write16(0x1F801074,value);
}
