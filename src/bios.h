#ifndef H_BIOS_H
#define H_BIOS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int32_t BIOS_AToI(uint32_t str);
extern uint32_t BIOS_MemCpy(uint32_t dest,uint32_t src,int32_t len);
extern uint32_t BIOS_MemSet(uint32_t dest,uint8_t value,int32_t len);

extern void BIOS_DeliverEvent(uint32_t evclass,uint32_t spec);
extern uint32_t BIOS_OpenEvent(uint32_t evclass,uint32_t spec,uint32_t mode,uint32_t func);
extern int BIOS_TestEvent(uint32_t event);
extern int BIOS_EnableEvent(uint32_t event);

extern uint32_t BIOS_Execute(uint32_t address);

#ifdef __cplusplus
}
#endif

#endif
