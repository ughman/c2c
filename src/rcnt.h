#ifndef H_RCNT_H
#define H_RCNT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum
{
	RCNT_DOTCLOCK,
	RCNT_HBLANK,
	RCNT_SYSDIV8,
	RCNT__COUNT
};

extern uint16_t RCNT_GetValue(int counter);
extern void RCNT_SetMode(int counter,uint16_t mode);
extern void RCNT_SetTarget(int counter,uint16_t mode);

#ifdef __cplusplus
}
#endif

#endif
