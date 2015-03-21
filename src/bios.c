#include "bios.h"
#include <stdio.h>
#include <stdlib.h>
#include "pcsx.h"
#include "emu.h"
#include "cop0.h"

int32_t BIOS_AToI(uint32_t str)
{
	return atoi(EMU_Pointer(str));
}

uint32_t BIOS_StrCat(uint32_t dest,uint32_t src)
{
	uint32_t len;
	uint32_t i = 0;
	uint8_t c = 1;
	for (len = 0;EMU_ReadU8(dest + len);len++);
	while (c)
	{
		EMU_Write8(dest + len + i,c = EMU_ReadU8(src + i));
		i++;
	}
	return dest;
}

int32_t BIOS_StrCmp(uint32_t str1,uint32_t str2)
{
	uint32_t i = 0;
	while (1)
	{
		int8_t c1 = EMU_ReadS8(str1 + i);
		int8_t c2 = EMU_ReadS8(str2 + i);
		if (c1 != c2)
			return c1 - c2;
		else if (c1 == 0)
			return 0;
		i++;
	}
}

int32_t BIOS_StrNCmp(uint32_t str1,uint32_t str2,uint32_t maxlen)
{
	uint32_t i = 0;
	while (i < maxlen)
	{
		int8_t c1 = EMU_ReadS8(str1 + i);
		int8_t c2 = EMU_ReadS8(str2 + i);
		if (c1 != c2)
			return c1 - c2;
		else if (c1 == 0)
			return 0;
		i++;
	}
	return 0;
}

uint32_t BIOS_StrCpy(uint32_t dest,uint32_t src)
{
	uint32_t i = 0;
	uint8_t c = 1;
	while (c)
	{
		EMU_Write8(dest + i,c = EMU_ReadU8(src + i));
		i++;
	}
	return dest;
}

uint32_t BIOS_StrLen(uint32_t str)
{
	uint32_t len;
	for (len = 0;EMU_ReadU8(str + len);len++);
	return len;
}

uint32_t BIOS_BCopy(uint32_t src,uint32_t dest,int32_t len)
{
	if (!src)
		return src;
	if (len < 0)
		return src;
	for (uint32_t i = 0;i < len;i++)
		EMU_Write8(dest + i,EMU_ReadU8(src + i));
	return src;
}

void BIOS_BZero(uint32_t dest,uint32_t len)
{
	BIOS_MemSet(dest,0,len);
}

uint32_t BIOS_MemCpy(uint32_t dest,uint32_t src,int32_t len)
{
	if (!dest)
		return dest;
	if (len < 0)
		return dest;
	for (uint32_t i = 0;i < len;i++)
		EMU_Write8(dest + i,EMU_ReadU8(src + i));
	return dest;
}

uint32_t BIOS_MemSet(uint32_t dest,uint8_t value,int32_t len)
{
	if (!dest)
		return dest;
	if (len < 0)
		return dest;
	for (uint32_t i = 0;i < len;i++)
		EMU_Write8(dest + i,value);
	return dest;
}

uint32_t BIOS_MemChr(uint32_t str,uint8_t value,uint32_t len)
{
	for (uint32_t i = 0;i < len;i++)
	{
		if (EMU_ReadU8(str + i) == value)
			return str + i;
	}
	return 0;
}

#define BIOS_MAXEVENTS 16

static struct biosevent
{
	int allocated;
	int enabled;
	int busy;
	uint32_t evclass;
	uint32_t spec;
	uint32_t mode;
	uint32_t func;
} events[BIOS_MAXEVENTS];

void BIOS_DeliverEvent(uint32_t evclass,uint32_t spec)
{
	for (int i = 0;i < BIOS_MAXEVENTS;i++)
	{
		struct biosevent *event = &events[i];
		if (!event->enabled)
			continue;
		if (event->evclass != evclass)
			continue;
		if (event->spec != spec)
			continue;
		if (event->mode == 0x1000)
			EMU_Invoke(event->func,0);
		else
			event->busy = 0;
	}
}

uint32_t BIOS_OpenEvent(uint32_t evclass,uint32_t spec,uint32_t mode,uint32_t func)
{
	for (int i = 0;i < BIOS_MAXEVENTS;i++)
	{
		struct biosevent *event = &events[i];
		if (!event->allocated)
		{
			event->allocated = 1;
			event->busy = 1;
			event->evclass = evclass;
			event->spec = spec;
			event->mode = mode;
			event->func = func;
			return i;
		}
	}
	abort();
}

int BIOS_TestEvent(uint32_t event)
{
	if (event >= BIOS_MAXEVENTS)
		abort();
	if (!events[event].enabled)
		return 0;
	if (events[event].busy)
		return 0;
	events[event].busy = 1;
	return 1;
}

int BIOS_EnableEvent(uint32_t event)
{
	if (event >= BIOS_MAXEVENTS)
		abort();
	events[event].enabled = 1;
	return 1;
}

#define CASE_METHOD(id,name) case id: EMU_NativeCall((void *)name); return RA

uint32_t BIOS_Execute(uint32_t address)
{
	switch (address)
	{
	case 0xA0:
		switch (T1)
		{
		CASE_METHOD(0x10,BIOS_AToI);
		CASE_METHOD(0x15,BIOS_StrCat);
		CASE_METHOD(0x17,BIOS_StrCmp);
		CASE_METHOD(0x18,BIOS_StrNCmp);
		CASE_METHOD(0x19,BIOS_StrCpy);
		CASE_METHOD(0x1B,BIOS_StrLen);
		CASE_METHOD(0x27,BIOS_BCopy);
		CASE_METHOD(0x28,BIOS_BZero);
		CASE_METHOD(0x2A,BIOS_MemCpy);
		CASE_METHOD(0x2B,BIOS_MemSet);
		CASE_METHOD(0x2E,BIOS_MemChr);
		default:
			fprintf(stderr,"Unrecognized BIOS(A0) method: %i:%s\n",T1,PCSX_A0Name(T1));
			return PCSX_HLEA0();
		}
		break;
	case 0xB0:
		switch (T1)
		{
		CASE_METHOD(0x7,BIOS_DeliverEvent);
		CASE_METHOD(0x8,BIOS_OpenEvent);
		CASE_METHOD(0xB,BIOS_TestEvent);
		CASE_METHOD(0xC,BIOS_EnableEvent);
		case 0x17:
			EMU_LoadRegisters();
			PCSX_ExecuteCOP(0,16 << 21);
			return COP0_GetRegister(14);
		default:
			fprintf(stderr,"Unrecognized BIOS(B0) method: %i:%s\n",T1,PCSX_B0Name(T1));
			return PCSX_HLEB0();
		}
		break;
	case 0xC0:
		switch (T1)
		{
		default:
			fprintf(stderr,"Unrecognized BIOS(C0) method: %i:%s\n",T1,PCSX_C0Name(T1));
			return PCSX_HLEC0();
		}
		break;
	default:
		fprintf(stderr,"Invalid BIOS routine class.\n");
		abort();
		break;
	}
}

#undef CASE_METHOD
