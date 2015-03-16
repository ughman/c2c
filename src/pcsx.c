#include "pcsx.h"
#include <stdio.h>
#include <dlfcn.h>
#include "emu.h"

static void *PCSX_library;

static struct pcsxinitinfo
{
	void (*reportnativecode)(uint32_t address,uint32_t wordcount);
	uint32_t (*invoke)(uint32_t address,int zero,...);
	uint32_t **ram;
	uint32_t **scratch;
} info;

static void (*PCSX_InitLibrary)(const char *filename,uint32_t **regbase,struct pcsxinitinfo *info);

uint8_t (*PCSX_Read8)(uint32_t address);
uint16_t (*PCSX_Read16)(uint32_t address);
uint32_t (*PCSX_Read32)(uint32_t address);

void (*PCSX_Write8)(uint32_t address,uint8_t value);
void (*PCSX_Write16)(uint32_t address,uint16_t value);
void (*PCSX_Write32)(uint32_t address,uint32_t value);

uint32_t (*PCSX_ReadCOPData)(int copid,int reg);
void (*PCSX_WriteCOPData)(int copid,int reg,uint32_t value);

uint32_t (*PCSX_ReadCOPControl)(int copid,int reg);
void (*PCSX_WriteCOPControl)(int copid,int reg,uint32_t value);

void (*PCSX_ExecuteCOP)(int copid,uint32_t copargs);

void (*PCSX_Syscall)(uint32_t pc);

void (*PCSX_Cycle)(int cycles);
uint32_t (*PCSX_RunInterrupts)(uint32_t pc);
const char *(*PCSX_Disassemble)(uint32_t pc);
uint32_t (*PCSX_ExecuteOnce)(uint32_t pc);
uint32_t (*PCSX_ExecuteOnceNoCycle)(uint32_t pc);
uint32_t (*PCSX_ExecuteBlock)(uint32_t address);
void (*PCSX_InvalidateICache)(void);

#define METHOD(localname,libname,type) \
do \
{ \
	localname = (type)dlsym(PCSX_library,libname); \
	if (!localname) \
		fprintf(stderr,"Failed to load symbol " #localname ".\n"); \
} while (0)

static void PCSX_ReportNativeCode(uint32_t address,uint32_t wordcount)
{
	while (wordcount--)
	{
		EMU_codemap[(address & 0x1FFFFF) >> 2] = EMU_ExecuteUnrecognizedCode;
		address += 4;
	}
}

void PCSX_Init(void)
{
	PCSX_library = dlopen("psx.dll",RTLD_LAZY);
	if (!PCSX_library)
		fprintf(stderr,"Failed to load PCSX library.\n");
	METHOD(PCSX_InitLibrary,"pcsxInit",void(*)(const char *,uint32_t **,struct pcsxinitinfo *));
	METHOD(PCSX_Read8,"pcsxReadMemory8",uint8_t(*)(uint32_t));
	METHOD(PCSX_Read16,"pcsxReadMemory16",uint16_t(*)(uint32_t));
	METHOD(PCSX_Read32,"pcsxReadMemory32",uint32_t(*)(uint32_t));
	METHOD(PCSX_Write8,"pcsxWriteMemory8",void(*)(uint32_t,uint8_t));
	METHOD(PCSX_Write16,"pcsxWriteMemory16",void(*)(uint32_t,uint16_t));
	METHOD(PCSX_Write32,"pcsxWriteMemory32",void(*)(uint32_t,uint32_t));
	METHOD(PCSX_ReadCOPData,"pcsxReadCOPData",uint32_t(*)(int,int));
	METHOD(PCSX_WriteCOPData,"pcsxWriteCOPData",void(*)(int,int,uint32_t));
	METHOD(PCSX_ReadCOPControl,"pcsxReadCOPControl",uint32_t(*)(int,int));
	METHOD(PCSX_WriteCOPControl,"pcsxWriteCOPControl",void(*)(int,int,uint32_t));
	METHOD(PCSX_ExecuteCOP,"pcsxExecuteCOP",void(*)(int,uint32_t));
	METHOD(PCSX_Syscall,"pcsxSyscall",void(*)(uint32_t));
	METHOD(PCSX_Cycle,"pcsxCycle",void(*)(int));
	METHOD(PCSX_RunInterrupts,"pcsxRunInterrupts",uint32_t(*)(uint32_t));
	METHOD(PCSX_Disassemble,"pcsxDisassemble",const char *(*)(uint32_t));
	METHOD(PCSX_ExecuteOnce,"pcsxExecuteOnce",uint32_t(*)(uint32_t));
	METHOD(PCSX_ExecuteOnceNoCycle,"pcsxExecuteOnceNoCycle",uint32_t(*)(uint32_t));
	METHOD(PCSX_ExecuteBlock,"pcsxExecuteBlock",uint32_t(*)(uint32_t));
	METHOD(PCSX_InvalidateICache,"pcsxInvalidateICache",void(*)(void));
	info.reportnativecode = PCSX_ReportNativeCode;
	info.invoke = EMU_Invoke;
	info.ram = &EMU_ram;
	info.scratch = &EMU_scratch;
	PCSX_InitLibrary("c2c.bin",&EMU_reg,&info);
}
