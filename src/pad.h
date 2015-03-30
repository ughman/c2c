#ifndef H_PAD_H
#define H_PAD_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t PAD_Read(void);
extern void PAD_Write(uint8_t value);

extern uint16_t PAD_GetStatus(void);

extern void PAD_SetControl(uint16_t value);

#ifdef __cplusplus
}
#endif

#endif
