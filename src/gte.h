#ifndef H_GTE_H
#define H_GTE_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t GTE_GetDataRegister(int reg);
extern void GTE_SetDataRegister(int reg,uint32_t value);

extern uint32_t GTE_GetControlRegister(int reg);
extern void GTE_SetControlRegister(int reg,uint32_t value);

extern void GTE_Execute(uint32_t args);

#ifdef __cplusplus
}
#endif

#endif
