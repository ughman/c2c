#ifndef H_DMA_H
#define H_DMA_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum
{
	DMA_MDEC_IN,
	DMA_MDEC_OUT,
	DMA_GPU,
	DMA_CDR,
	DMA_SPU,
	DMA_PIO,
	DMA_OTC,
	DMA__COUNT
};

extern void DMA_SetAddress(int channel,uint32_t value);
extern void DMA_SetBlockData(int channel,uint32_t value);

extern uint32_t DMA_GetMode(int channel);
extern void DMA_SetMode(int channel,uint32_t value);

extern uint32_t DMA_GetControlRegister(void);
extern void DMA_SetControlRegister(uint32_t value);
extern uint32_t DMA_GetInterruptRegister(void);
extern void DMA_SetInterruptRegister(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif
