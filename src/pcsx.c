#include "pcsx.h"
#include <dlfcn.h>
#include "emu.h"
#include "bios.h"

static void *PCSX_library;

static struct pcsxinitinfo
{
	uint32_t (*invoke)(uint32_t address,int zero,...);
	void (*saveregisters)(void);
	void (*deliverevent)(uint32_t evclass,uint32_t spec);
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

const char *(*PCSX_A0Name)(int id);
const char *(*PCSX_B0Name)(int id);
const char *(*PCSX_C0Name)(int id);

uint32_t (*PCSX_HLEA0)(void);
uint32_t (*PCSX_HLEB0)(void);
uint32_t (*PCSX_HLEC0)(void);

#define METHOD(localname,libname,type) \
do \
{ \
	localname = (type)dlsym(PCSX_library,libname); \
	if (!localname) \
		fprintf(stderr,"Failed to load symbol " #localname ".\n"); \
} while (0)

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
	METHOD(PCSX_A0Name,"pcsxA0Name",const char *(*)(int));
	METHOD(PCSX_B0Name,"pcsxB0Name",const char *(*)(int));
	METHOD(PCSX_C0Name,"pcsxC0Name",const char *(*)(int));
	METHOD(PCSX_HLEA0,"pcsxHLEA0",uint32_t(*)(void));
	METHOD(PCSX_HLEB0,"pcsxHLEB0",uint32_t(*)(void));
	METHOD(PCSX_HLEC0,"pcsxHLEC0",uint32_t(*)(void));
	info.invoke = EMU_Invoke;
	info.saveregisters = EMU_SaveRegisters;
	info.deliverevent = BIOS_DeliverEvent;
	info.ram = &EMU_ram;
	info.scratch = &EMU_scratch;
	PCSX_InitLibrary("c2c.bin",&EMU_reg,&info);
}
