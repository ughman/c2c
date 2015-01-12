#include "cop0.h"
#include "pcsx.h"

uint32_t COP0_GetRegister(int reg)
{
	return PCSX_ReadCOPData(0,reg);
}

void COP0_SetRegister(int reg,uint32_t value)
{
	PCSX_WriteCOPData(0,reg,value);
}
