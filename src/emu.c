#include "emu.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "pcsx.h"
#include "bios.h"

uint32_t *EMU_reg;
uint32_t *EMU_ram;

uint32_t (*EMU_codemap[EMU_RAMWORDS])(uint32_t address);

uint32_t EMU_ExecuteUnrecognizedCode(uint32_t pc)
{
	fprintf(stderr,"Unrecognized code at PC := %X\n",pc);
	return (EMU_codemap[(pc & 0x1FFFFF) >> 2] = PCSX_ExecuteBlock)(pc);
}

uint32_t EMU_ExecuteBadEntryPointCode(uint32_t pc)
{
	fprintf(stderr,"Bad entry point for native code at PC := %X\n",pc);
	return (EMU_codemap[(pc & 0x1FFFFF) >> 2] = PCSX_ExecuteBlock)(pc);
}

void EMU_Init(void)
{
	extern void ZZ_Init(void);
	PCSX_Init();
	EMU_codemap[0x28] = BIOS_Execute;
	EMU_codemap[0x2C] = BIOS_Execute;
	EMU_codemap[0x30] = BIOS_Execute;
	for (int i = 0;i < EMU_RAMWORDS;i++)
	{
		if (!EMU_codemap[i])
			EMU_codemap[i] = PCSX_ExecuteBlock;
	}
	ZZ_Init();
}

int8_t EMU_ReadS8(uint32_t address)
{
	return EMU_ReadU8(address);
}

int16_t EMU_ReadS16(uint32_t address)
{
	return EMU_ReadU16(address);
}

uint8_t EMU_ReadU8(uint32_t address)
{
	if (address >= 0x80000000 && address <= 0x801FFFFF)
	{
		{
			uint32_t (*codehandler)(uint32_t) = EMU_codemap[(address & 0x1FFFFF) >> 2];
			if (codehandler != EMU_ExecuteUnrecognizedCode && codehandler != PCSX_ExecuteBlock)
			{
				fprintf(stderr,"Reading code as data.\n");
			}
		}
		return PCSX_Read32(address & ~3) >> (address & 3) * 8;
	}
	else
	{
		return PCSX_Read8(address);
	}
}

uint16_t EMU_ReadU16(uint32_t address)
{
	if (address & 1)
		fprintf(stderr,"Unaligned halfword load.\n");
	if (address >= 0x80000000 && address <= 0x801FFFFF)
	{
		{
			uint32_t (*codehandler)(uint32_t) = EMU_codemap[(address & 0x1FFFFF) >> 2];
			if (codehandler != EMU_ExecuteUnrecognizedCode && codehandler != PCSX_ExecuteBlock)
			{
				fprintf(stderr,"Reading code as data.\n");
			}
		}
		return PCSX_Read32(address & ~2) >> (address & 2) * 8;
	}
	else
	{
		return PCSX_Read16(address);
	}
}

uint32_t EMU_ReadU32(uint32_t address)
{
	if (address & 3)
		fprintf(stderr,"Unaligned word load.\n");
	if (address >= 0x80000000 && address <= 0x801FFFFF)
	{
		{
			uint32_t (*codehandler)(uint32_t) = EMU_codemap[(address & 0x1FFFFF) >> 2];
			if (codehandler != EMU_ExecuteUnrecognizedCode && codehandler != PCSX_ExecuteBlock)
			{
				fprintf(stderr,"Reading code as data.\n");
			}
		}
		return PCSX_Read32(address);
	}
	else
	{
		return PCSX_Read32(address);
	}
}

void EMU_Write8(uint32_t address,uint8_t value)
{
	if (address >= 0x80000000 && address <= 0x801FFFFF)
	{
		{
			uint32_t (*codehandler)(uint32_t) = EMU_codemap[(address & 0x1FFFFF) >> 2];
			if (codehandler != EMU_ExecuteUnrecognizedCode && codehandler != PCSX_ExecuteBlock)
			{
				fprintf(stderr,"Writing code.\n");
			}
		}
		PCSX_Write8(address,value);
	}
	else
	{
		PCSX_Write8(address,value);
	}
}

void EMU_Write16(uint32_t address,uint16_t value)
{
	if (address & 1)
		fprintf(stderr,"Unaligned halfword store.\n");
	if (address >= 0x80000000 && address <= 0x801FFFFF)
	{
		{
			uint32_t (*codehandler)(uint32_t) = EMU_codemap[(address & 0x1FFFFF) >> 2];
			if (codehandler != EMU_ExecuteUnrecognizedCode && codehandler != PCSX_ExecuteBlock)
			{
				fprintf(stderr,"Writing code.\n");
			}
		}
		PCSX_Write16(address,value);
	}
	else
	{
		PCSX_Write16(address,value);
	}
}

void EMU_Write32(uint32_t address,uint32_t value)
{
	if (address & 3)
		fprintf(stderr,"Unaligned word store.\n");
	if (address >= 0x80000000 && address <= 0x801FFFFF)
	{
		{
			uint32_t (*codehandler)(uint32_t) = EMU_codemap[(address & 0x1FFFFF) >> 2];
			if (codehandler != EMU_ExecuteUnrecognizedCode && codehandler != PCSX_ExecuteBlock)
			{
				fprintf(stderr,"Writing code.\n");
			}
		}
		PCSX_Write32(address,value);
	}
	else
	{
		PCSX_Write32(address,value);
	}
}

void EMU_ReadLeft(uint32_t address,uint32_t *valueref)
{
	static uint32_t mask[4] = {0xFFFFFF,0xFFFF,0xFF,0};
	static int shift[4] = {24,16,8,0};
	uint32_t value = EMU_ReadU32(address & ~3);
	*valueref &= mask[address & 3];
	*valueref |= value << shift[address & 3];
}

void EMU_ReadRight(uint32_t address,uint32_t *valueref)
{
	static uint32_t mask[4] = {0,0xFF000000,0xFFFF0000,0xFFFFFF00};
	static int shift[4] = {0,8,16,24};
	uint32_t value = EMU_ReadU32(address & ~3);
	*valueref &= mask[address & 3];
	*valueref |= value >> shift[address & 3];
}

void EMU_WriteLeft(uint32_t address,uint32_t value)
{
	static uint32_t mask[4] = {0xFFFFFF00,0xFFFF0000,0xFF000000,0};
	static int shift[4] = {24,16,8,0};
	uint32_t memvalue = EMU_ReadU32(address & ~3);
	memvalue &= mask[address & 3];
	memvalue |= value >> shift[address & 3];
	EMU_Write32(address & ~3,memvalue);
}

void EMU_WriteRight(uint32_t address,uint32_t value)
{
	static uint32_t mask[4] = {0,0xFF,0xFFFF,0xFFFFFF};
	static int shift[4] = {0,8,16,24};
	uint32_t memvalue = EMU_ReadU32(address & ~3);
	memvalue &= mask[address & 3];
	memvalue |= value << shift[address & 3];
	EMU_Write32(address & ~3,memvalue);
}

void *EMU_Pointer(uint32_t address)
{
	if (address >= 0x80000000 && address <= 0x801FFFFF)
	{
		return &EMU_ram[(address & 0x1FFFFF) >> 2];
	}
	abort();
}

void EMU_SMultiply(int32_t a,int32_t b)
{
	int64_t result = (int64_t)a * (int64_t)b;
	LO = result;
	HI = result >> 32;
}

void EMU_UMultiply(uint32_t a,uint32_t b)
{
	uint64_t result = (uint64_t)a * (uint64_t)b;
	LO = result;
	HI = result >> 32;
}

void EMU_SDivide(int32_t a,int32_t b)
{
	if (b)
	{
		LO = a / b;
		HI = a % b;
	}
	else
	{
		LO = 0xFFFFFFFF;
		HI = a;
	}
}

void EMU_UDivide(uint32_t a,uint32_t b)
{
	if (b)
	{
		LO = a / b;
		HI = a % b;
	}
	else
	{
		LO = 0xFFFFFFFF;
		HI = a;
	}
}

uint32_t EMU_Invoke(uint32_t address,int argc,...)
{
	va_list args;
	uint32_t ra_saved = RA;
	uint32_t pc;
	SP -= argc * 4;
	va_start(args,argc);
	for (int i = 0;i < argc;i++)
	{
		if (i == 0)
			A0 = va_arg(args,uint32_t);
		else if (i == 1)
			A1 = va_arg(args,uint32_t);
		else if (i == 2)
			A2 = va_arg(args,uint32_t);
		else if (i == 3)
			A3 = va_arg(args,uint32_t);
		else
			EMU_Write32(SP + i * 4,va_arg(args,uint32_t));
	}
	va_end(args);
	RA = 0xDEADBEEF;
	pc = address;
	while (pc != 0xDEADBEEF)
	{
		if (pc & 3)
			fprintf(stderr,"Unaligned program counter.\n");
		pc = EMU_codemap[(pc & 0x1FFFFF) >> 2](pc);
	}
	SP += argc * 4;
	RA = ra_saved;
	return V0;
}

void EMU_Syscall(uint32_t pc)
{
	PCSX_Syscall(pc);
}

void EMU_Break(uint32_t id)
{
	// TODO
}

void EMU_NativeCall(void *method)
{
	static uint32_t stackbuffer[16];
	memcpy(stackbuffer,(uint8_t *)EMU_ram + (SP & 0x1FFFFF),sizeof(stackbuffer));
	stackbuffer[0] = A0;
	stackbuffer[1] = A1;
	stackbuffer[2] = A2;
	stackbuffer[3] = A3;
	__asm__
	(
		"movl %2,%%ecx;"
		"subl %%ecx,%%esp;"
		"shr $2,%%ecx;"
		"movl %%esp,%%edi;"
		"rep movsd;"
		"call *%1;"
		"addl %2,%%esp;"
		: "=a"(V0)
		: "m"(method),"i"(sizeof(stackbuffer)),"S"(stackbuffer)
		: "%ecx","%edx","%edi","flags","memory"
	);
}

void EMU_Cycle(int cycles)
{
	PCSX_Cycle(cycles);
}

uint32_t EMU_RunInterrupts(uint32_t pc)
{
	return PCSX_RunInterrupts(pc);
}

void EMU_InvalidateICache(void)
{
	PCSX_InvalidateICache();
}
