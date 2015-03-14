#include "spu.h"
#include "pcsx.h"

void SPU_SetVolumeLeft(uint16_t value)
{
	PCSX_Write16(0x1F801D80,value);
}

void SPU_SetVolumeRight(uint16_t value)
{
	PCSX_Write16(0x1F801D82,value);
}

void SPU_SetReverbVolumeLeft(uint16_t value)
{
	PCSX_Write16(0x1F801D84,value);
}

void SPU_SetReverbVolumeRight(uint16_t value)
{
	PCSX_Write16(0x1F801D86,value);
}

uint16_t SPU_Voice_GetVolumeLeft(int voice)
{
	return PCSX_Read16(0x1F801C00 + voice * 0x10);
}

void SPU_Voice_SetVolumeLeft(int voice,uint16_t value)
{
	PCSX_Write16(0x1F801C00 + voice * 0x10,value);
}

uint16_t SPU_Voice_GetVolumeRight(int voice)
{
	return PCSX_Read16(0x1F801C02 + voice * 0x10);
}

void SPU_Voice_SetVolumeRight(int voice,uint16_t value)
{
	PCSX_Write16(0x1F801C02 + voice * 0x10,value);
}

uint16_t SPU_Voice_GetSampleRate(int voice)
{
	return PCSX_Read16(0x1F801C04 + voice * 0x10);
}

void SPU_Voice_SetSampleRate(int voice,uint16_t value)
{
	PCSX_Write16(0x1F801C04 + voice * 0x10,value);
}

uint16_t SPU_Voice_GetStartAddress(int voice)
{
	return PCSX_Read16(0x1F801C06 + voice * 0x10);
}

void SPU_Voice_SetStartAddress(int voice,uint16_t value)
{
	PCSX_Write16(0x1F801C06 + voice * 0x10,value);
}

uint16_t SPU_Voice_GetADSRLow(int voice)
{
	return PCSX_Read16(0x1F801C08 + voice * 0x10);
}

void SPU_Voice_SetADSRLow(int voice,uint16_t value)
{
	PCSX_Write16(0x1F801C08 + voice * 0x10,value);
}

uint16_t SPU_Voice_GetADSRHigh(int voice)
{
	return PCSX_Read16(0x1F801C0A + voice * 0x10);
}

void SPU_Voice_SetADSRHigh(int voice,uint16_t value)
{
	PCSX_Write16(0x1F801C0A + voice * 0x10,value);
}

uint16_t SPU_Voice_GetADSRVolume(int voice)
{
	return PCSX_Read16(0x1F801C0C + voice * 0x10);
}

void SPU_Voice_SetADSRVolume(int voice,uint16_t value)
{
	PCSX_Write16(0x1F801C0C + voice * 0x10,value);
}

uint16_t SPU_Voice_GetLoopAddress(int voice)
{
	return PCSX_Read16(0x1F801C0E + voice * 0x10);
}

void SPU_Voice_SetLoopAddress(int voice,uint16_t value)
{
	PCSX_Write16(0x1F801C0E + voice * 0x10,value);
}

void SPU_NoteOnLow(uint16_t value)
{
	PCSX_Write16(0x1F801D88,value);
}

void SPU_NoteOnHigh(uint16_t value)
{
	PCSX_Write16(0x1F801D8A,value);
}

void SPU_NoteOffLow(uint16_t value)
{
	PCSX_Write16(0x1F801D8C,value);
}

void SPU_NoteOffHigh(uint16_t value)
{
	PCSX_Write16(0x1F801D8E,value);
}

void SPU_SetFMLow(uint16_t value)
{
	PCSX_Write16(0x1F801D90,value);
}

void SPU_SetFMHigh(uint16_t value)
{
	PCSX_Write16(0x1F801D92,value);
}

void SPU_SetNoiseLow(uint16_t value)
{
	PCSX_Write16(0x1F801D94,value);
}

void SPU_SetNoiseHigh(uint16_t value)
{
	PCSX_Write16(0x1F801D96,value);
}

uint16_t SPU_GetReverbLow(void)
{
	return PCSX_Read16(0x1F801D98);
}

void SPU_SetReverbLow(uint16_t value)
{
	PCSX_Write16(0x1F801D98,value);
}

uint16_t SPU_GetReverbHigh(void)
{
	return PCSX_Read16(0x1F801D9A);
}

void SPU_SetReverbHigh(uint16_t value)
{
	PCSX_Write16(0x1F801D9A,value);
}

void SPU_SetReverbStartAddress(uint16_t value)
{
	PCSX_Write16(0x1F801DA2,value);
}

uint16_t SPU_GetTransferAddress(void)
{
	return PCSX_Read16(0x1F801DA6);
}

void SPU_SetTransferAddress(uint16_t value)
{
	PCSX_Write16(0x1F801DA6,value);
}

void SPU_Write(uint16_t value)
{
	PCSX_Write16(0x1F801DA8,value);
}

uint16_t SPU_ReadControlRegister(void)
{
	return PCSX_Read16(0x1F801DAA);
}

void SPU_WriteControlRegister(uint16_t value)
{
	PCSX_Write16(0x1F801DAA,value);
}

void SPU_SetTransferMode(uint16_t value)
{
	PCSX_Write16(0x1F801DAC,value);
}

uint16_t SPU_ReadStatusRegister(void)
{
	return PCSX_Read16(0x1F801DAE);
}

void SPU_SetCDVolumeLeft(uint16_t value)
{
	PCSX_Write16(0x1F801DB0,value);
}

void SPU_SetCDVolumeRight(uint16_t value)
{
	PCSX_Write16(0x1F801DB2,value);
}

void SPU_SetExternVolumeLeft(uint16_t value)
{
	PCSX_Write16(0x1F801DB4,value);
}

void SPU_SetExternVolumeRight(uint16_t value)
{
	PCSX_Write16(0x1F801DB6,value);
}

uint16_t SPU_GetCurrentVolumeLeft(void)
{
	return PCSX_Read16(0x1F801DB8);
}

uint16_t SPU_GetCurrentVolumeRight(void)
{
	return PCSX_Read16(0x1F801DBA);
}

void SPU_ConfigureReverb(int code,uint16_t value)
{
	PCSX_Write16(0x1F801DC0 + code * 2,value);
}

uint16_t SPU_Voice_GetCurrentVolumeLeft(int voice)
{
	return PCSX_Read16(0x1F801E00 + voice * 0x4);
}

uint16_t SPU_Voice_GetCurrentVolumeRight(int voice)
{
	return PCSX_Read16(0x1F801E02 + voice * 0x4);
}
