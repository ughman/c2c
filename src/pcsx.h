#ifndef H_PCSX_H
#define H_PCSX_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t (*PCSX_Read8)(uint32_t address);
extern uint16_t (*PCSX_Read16)(uint32_t address);
extern uint32_t (*PCSX_Read32)(uint32_t address);

extern void (*PCSX_Write8)(uint32_t address,uint8_t value);
extern void (*PCSX_Write16)(uint32_t address,uint16_t value);
extern void (*PCSX_Write32)(uint32_t address,uint32_t value);

extern uint32_t (*PCSX_ReadCOPData)(int copid,int reg);
extern void (*PCSX_WriteCOPData)(int copid,int reg,uint32_t value);

extern uint32_t (*PCSX_ReadCOPControl)(int copid,int reg);
extern void (*PCSX_WriteCOPControl)(int copid,int reg,uint32_t value);

extern void (*PCSX_ExecuteCOP)(int copid,uint32_t copargs);

extern void (*PCSX_Syscall)(uint32_t pc);

extern void (*PCSX_Cycle)(int cycles);
extern uint32_t (*PCSX_RunInterrupts)(uint32_t pc);
extern const char *(*PCSX_Disassemble)(uint32_t pc);

extern const char *(*PCSX_A0Name)(int id);
extern const char *(*PCSX_B0Name)(int id);
extern const char *(*PCSX_C0Name)(int id);

extern uint32_t (*PCSX_HLEA0)(void);
extern uint32_t (*PCSX_HLEB0)(void);
extern uint32_t (*PCSX_HLEC0)(void);

extern void PCSX_Init(void);

#ifdef __cplusplus
}
#endif

#endif
