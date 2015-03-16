#ifndef H_GOOL_H
#define H_GOOL_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum
{
	GOOL_LANGUAGE_GOOL,
	GOOL_LANGUAGE_MIPS,
	GOOL_LANGUAGE__COUNT
};

struct goolenv
{
	uint32_t oldpc;
	uint32_t pc;
	uint32_t pcfar;
	int language;
	int languagefar;
};

typedef void (*goolexechandler_t)(struct goolenv *env,uint32_t instruction);

#ifdef __cplusplus
}
#endif

#endif
