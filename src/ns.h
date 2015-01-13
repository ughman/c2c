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

struct nspageinfo
{
	EMUPTR(struct nspage) page;
	int16_t status;
	uint16_t off_6;
	int16_t unk_8;
	uint16_t off_10;
	uint32_t off_12;
	EMUPTR(struct nspage) nextpage;
	int32_t pagenum;
	uint32_t off_24;
	int32_t unk_28;
	uint32_t off_32;
	uint32_t off_36;
	uint32_t off_40;
};

extern int NS_VerifyChecksum(EMUPTR(struct nspage) nspage);

extern uint32_t NS_13164(EMUPTR(struct nspageinfo) nspageinfo);

#ifdef __cplusplus
}
#endif

#endif
