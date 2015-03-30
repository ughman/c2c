#ifndef H_IRQ_H
#define H_IRQ_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

enum
{
	IRQ_VBLANK,
	IRQ_GPU,
	IRQ_CDR,
	IRQ_DMA,
	IRQ_TMR0,
	IRQ_TMR1,
	IRQ_TMR2,
	IRQ_PAD,
	IRQ_SIO,
	IRQ_SPU,
	IRQ_PAD_SPECIAL,
	IRQ__COUNT
};

extern uint16_t IRQ_GetStatus(void);
extern void IRQ_AcknowledgeBits(uint16_t value);
extern uint16_t IRQ_GetMask(void);
extern void IRQ_SetMask(uint16_t value);

#ifdef __cplusplus
}
#endif

#endif
