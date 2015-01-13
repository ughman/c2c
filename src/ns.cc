#include "ns.h"
#include "emu.h"

int NS_VerifyChecksum(emuptr<struct nspage> nspage)
{
	return nspage->checksum == EMU_Invoke(0x800125F8,1,nspage);
}

uint32_t NS_13164(emuptr<struct nspageinfo> nspageinfo)
{
	int16_t status = nspageinfo->status;
	int32_t unk_28 = nspageinfo->unk_28;
	T0 = 0;
	if (status == 0x3 || status == 0xD)
	{
		if (EMU_ReadU32(0x80068260) && !NS_VerifyChecksum(nspageinfo->page))
		{
			return EMU_Invoke(0x80013148,1,nspageinfo);
		}
		nspageinfo->status = 0x4;
		EMU_Invoke(0x8001254C,1,nspageinfo->page);
		return 0;
	}
	V0 = EMU_ReadU32(0x80067838);
	V0 = EMU_ReadU32(V0 + 1052); //+ 0x41C
	V1 = nspageinfo->pagenum >> 1;
	A2 = ((int32_t)V1 < (int32_t)V0) && !!EMU_ReadU32(0x80068260);
	for (int32_t i = 0;i < unk_28;i++,nspageinfo--)
	{
		if (status != 0x2)
			continue;
		nspageinfo->off_10 = A2;
		if (A2)
		{
			V1 = EMU_ReadU32(0x80067838);
			V0 = nspageinfo->pagenum >> 1;
			V0 <<= 2;
			V0 += V1;
			V0 = EMU_ReadU32(V0 + 1056); //+ 0x420
			V1 = T0 + 32;
			V0 &= 0x3F;
			T0 = V1 - V0;
			nspageinfo->unk_8 = T0;
		}
		if (nspageinfo->status == 0x2)
		{
			nspageinfo->status = 0x3;
		}
		else
		{
			nspageinfo->status = 0xD;
			if (A2)
			{
				V1 = EMU_ReadU32(0x80067838);
				V0 = nspageinfo->pagenum >> 1;
				V0 <<= 2;
				V0 += V1;
				V0 = EMU_ReadU32(V0 + 1056); //+ 0x420
				A0 = nspageinfo->unk_8;
				V1 = (uint32_t)nspageinfo->page;
				V0 &= 0x3F;
				V0 += A0;
				V0 <<= 11;
				V1 += V0;
				nspageinfo->nextpage = (emuptr<struct nspage>)V1;
			}
			else
			{
				nspageinfo->nextpage = nspageinfo[1].page;
			}
			nspageinfo->nextpage->magic = 0x8765;
		}
	}
	// BUG :: The game's original implementation of this function
	// returned an undefined value if the loop body was not executed
	// at least once (register $A3)
	return (uint32_t)(nspageinfo + 1);
}
