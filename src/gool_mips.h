#ifndef H_GOOL_MIPS_H
#define H_GOOL_MIPS_H

#include "gool.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void GOOL_MIPS_ExecuteOnce(struct goolenv *env);
extern void GOOL_MIPS_ExecuteFromZZ(uint32_t pc);

#ifdef __cplusplus
}
#endif

#endif
