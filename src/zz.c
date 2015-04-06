#include "common.h"
#include "emu.h"
#include "cop0.h"
#include "gte.h"

#define ZZ_JUMPREGISTER_BEGIN(reg) \
do \
{ \
	jr_dest = reg; \
} while (0)

#define ZZ_JUMPREGISTER(addr,label) \
do \
{ \
	if (jr_dest == addr) \
		goto label; \
} while (0)

#define ZZ_JUMPREGISTER_END() \
do \
{ \
	if (jr_dest != 0xDEADBEEF) \
	{ \
	} \
	return jr_dest; \
} while (0)

#define ZZ_CLOCKCYCLES(clocks,address) \
do \
{ \
	EMU_Cycle(clocks); \
	EMU_RunInterrupts(); \
} while (0)

#define ZZ_CLOCKCYCLES_JR(clocks) \
do \
{ \
	EMU_Cycle(clocks); \
	EMU_RunInterrupts(); \
} while (0)

static uint32_t ZZ_Native(uint32_t address);

void ZZ_Init(void)
{
#define ZZ_MARK_NATIVE(start,end,label,function) ZZ_MARK_TARGET(start,end,label)
#define ZZ_MARK_TARGET(start,end,label) \
do \
{ \
	EMU_codemap[(start & 0x1FFFFF) >> 2] = ZZ_Native; \
	ZZ_MARK(start + 0x4,end); \
} while (0)
#define ZZ_MARK(start,end) \
do for (uint32_t address = start;address < end;address += 4)\
{ \
	EMU_codemap[(address & 0x1FFFFF) >> 2] = EMU_ExecuteBadEntryPointCode; \
} while (0)
#include "../srczz/zz_include.h"
#undef ZZ_MARK_NATIVE
#undef ZZ_MARK_TARGET
#undef ZZ_MARK
}

#define ZZ_MARK_NATIVE(start,end,label,function) extern void function(void);
#define ZZ_MARK_TARGET(start,end,label)
#define ZZ_MARK(start,end)
#include "../srczz/zz_include.h"
#undef ZZ_MARK_NATIVE
#undef ZZ_MARK_TARGET
#undef ZZ_MARK

uint32_t ZZ_Native(uint32_t address)
{
	uint32_t jr_dest;
	switch (address)
	{
#define ZZ_MARK_NATIVE(start,end,label,function) ZZ_MARK_TARGET(start,end,label)
#define ZZ_MARK_TARGET(start,end,label) \
do \
{ \
	case start: \
		goto label; \
} while (0)
#define ZZ_MARK(start,end) do {} while (0)
#include "../srczz/zz_include.h"
#undef ZZ_MARK_NATIVE
#undef ZZ_MARK_TARGET
#undef ZZ_MARK
	default:
		SDL_LogError(LOG_ZZ,"Unrecognized execution address");
		break;
	}
#define ZZ_MARK_NATIVE(start,end,label,function) \
	do \
	{ \
label: \
		EMU_NativeCall((void *)&function); \
		return RA; \
	} while (0)
#define ZZ_MARK_TARGET(start,end,label) do {} while (0)
#define ZZ_MARK(start,end) do {} while (0)
#define ZZ_INCLUDE_CODE
#include "../srczz/zz_include.h"
#undef ZZ_MARK_NATIVE
#undef ZZ_MARK_TARGET
#undef ZZ_MARK
#undef ZZ_INCLUDE_CODE
	SDL_LogCritical(LOG_ZZ,"Reached end of function");
	abort();
	ZZ_FORCEEXIT:
		return jr_dest;
}
