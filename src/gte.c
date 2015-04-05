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

void GTE_RotateTranslateProjectSingle(void)
{
	PCSX_ExecuteCOP(2,0x180001);
}

void GTE_RotateTranslateProjectTriple(void)
{
	PCSX_ExecuteCOP(2,0x280030);
}

void GTE_NormalClip(void)
{
	PCSX_ExecuteCOP(2,0x1400006);
}

void GTE_Multiply_V0_Rotation(void)
{
	PCSX_ExecuteCOP(2,0x486012);
}

void GTE_Multiply_V1_Rotation(void)
{
	PCSX_ExecuteCOP(2,0x48E012);
}

void GTE_Multiply_V2_Rotation(void)
{
	PCSX_ExecuteCOP(2,0x496012);
}

void GTE_Multiply_IR_Rotation(void)
{
	PCSX_ExecuteCOP(2,0x49E012);
}

void GTE_Multiply_V0_Light(void)
{
	PCSX_ExecuteCOP(2,0x4A6012);
}

void GTE_Multiply_V1_Light(void)
{
	PCSX_ExecuteCOP(2,0x4AE012);
}

void GTE_Multiply_V2_Light(void)
{
	PCSX_ExecuteCOP(2,0x4B6012);
}

void GTE_Multiply_IR_Light(void)
{
	PCSX_ExecuteCOP(2,0x4BE012);
}

void GTE_MultiplyAdd_V0_Rotation_Translation(void)
{
	PCSX_ExecuteCOP(2,0x480012);
}

void GTE_DepthCueSingle(void)
{
	PCSX_ExecuteCOP(2,0x780010);
}

void GTE_DepthCueTriple(void)
{
	PCSX_ExecuteCOP(2,0xF8002A);
}

void GTE_DepthCueColorLight(void)
{
	PCSX_ExecuteCOP(2,0x680029);
}
