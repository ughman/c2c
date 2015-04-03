#include "gte.h"
#include "pcsx.h"

uint32_t GTE_GetRegister(int reg)
{
	if (reg < 32)
		return PCSX_ReadCOPData(2,reg);
	else
		return PCSX_ReadCOPControl(2,reg - 32);
}

void GTE_SetRegister(int reg,uint32_t value)
{
	if (reg < 32)
		PCSX_WriteCOPData(2,reg,value);
	else
		PCSX_WriteCOPControl(2,reg - 32,value);
}

void GTE_Execute(uint32_t args)
{
	PCSX_ExecuteCOP(2,args);
}
