#ifndef H_CDR_H
#define H_CDR_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t CDR_GetStatus(void);
extern void CDR_SetMode(int mode);

extern uint8_t CDR_Read(void);
extern uint8_t CDR_ReadResponse(void);

extern uint8_t CDR_Read3(void);

extern void CDR_Write1(uint8_t value);
extern void CDR_Write2(uint8_t value);
extern void CDR_Write3(uint8_t value);

#ifdef __cplusplus
}
#endif

#endif
