#include "cdr.h"
#include "pcsx.h"

uint8_t CDR_GetStatus(void)
{
	return PCSX_Read8(0x1F801800);
}

void CDR_SetMode(int mode)
{
	PCSX_Write8(0x1F801800,mode);
}

uint8_t CDR_Read(void)
{
	return PCSX_Read8(0x1F801802);
}

uint8_t CDR_ReadResponse(void)
{
	return PCSX_Read8(0x1F801801);
}

uint8_t CDR_Read3(void)
{
	return PCSX_Read8(0x1F801803);
}

void CDR_Write1(uint8_t value)
{
	PCSX_Write8(0x1F801801,value);
}

void CDR_Write2(uint8_t value)
{
	PCSX_Write8(0x1F801802,value);
}

void CDR_Write3(uint8_t value)
{
	PCSX_Write8(0x1F801803,value);
}
