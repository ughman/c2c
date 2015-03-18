#ifndef H_BIOS_H
#define H_BIOS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t BIOS_MemCpy(uint32_t dest,uint32_t src,int32_t len);
extern uint32_t BIOS_MemSet(uint32_t dest,uint8_t value,int32_t len);

extern uint32_t BIOS_Execute(uint32_t address);

#ifdef __cplusplus
}
#endif

#endif
