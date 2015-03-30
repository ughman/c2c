#ifndef H_COP0_H
#define H_COP0_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t COP0_GetRegister(int reg);
extern void COP0_SetRegister(int reg,uint32_t value);

#ifdef __cplusplus
}
#endif

#endif
