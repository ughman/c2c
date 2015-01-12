#include "ns.h"
#include "emu.h"

int NS_VerifyChecksum(emuptr<struct nspage> nspage)
{
	return nspage->checksum == EMU_Invoke(0x800125F8,1,nspage);
}
