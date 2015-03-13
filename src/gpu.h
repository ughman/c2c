#ifndef H_GPU_H
#define H_GPU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t GPU_Read(void);
extern void GPU_Write(uint32_t value);
extern void GPU_WriteAlt(uint32_t value);

extern uint32_t GPU_GetStatus(void);

#ifdef __cplusplus
}
#endif

#endif
