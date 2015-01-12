#ifndef H_NS_H
#define H_NS_H

#include <stdint.h>
#include "emu.h"

#ifdef __cplusplus
extern "C" {
#endif

struct nspage
{
	uint16_t magic;
	uint16_t type;
	uint32_t pagenum;
	uint32_t entrycount;
	uint32_t checksum;
};

extern int NS_VerifyChecksum(EMUPTR(struct nspage) nspage);

#ifdef __cplusplus
}
#endif

#endif
