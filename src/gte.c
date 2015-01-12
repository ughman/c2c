#include "gte.h"
#include "pcsx.h"

uint32_t GTE_GetDataRegister(int reg)
{
	return PCSX_ReadCOPData(2,reg);
}

void GTE_SetDataRegister(int reg,uint32_t value)
{
	PCSX_WriteCOPData(2,reg,value);
}

uint32_t GTE_GetControlRegister(int reg)
{
	return PCSX_ReadCOPControl(2,reg);
}

void GTE_SetControlRegister(int reg,uint32_t value)
{
	PCSX_WriteCOPControl(2,reg,value);
}

void GTE_Execute(uint32_t args)
{
	PCSX_ExecuteCOP(2,args);
}
