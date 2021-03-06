#ifdef ZZ_INCLUDE_CODE
ZZ_24038:
	A0 = 0x80060000;
	A0 = EMU_ReadU32(A0 + 2932); //+ 0xB74
	A2 = 0x80060000;
	A2 = EMU_ReadU32(A2 + 2936); //+ 0xB78
	SP -= 56;
	A1 = 0x16E;
	V0 = 0x3;
	EMU_Write32(SP + 20,V0); //+ 0x14
	V0 = SP + 40;
	A3 = R0;
	EMU_Write32(SP + 48,RA); //+ 0x30
	EMU_Write32(SP + 16,R0); //+ 0x10
	EMU_Write32(SP + 24,V0); //+ 0x18
	EMU_Write32(SP + 28,R0); //+ 0x1C
	RA = 0x80024078; //ZZ_24038_40
	EMU_Write32(SP + 32,R0); //+ 0x20
	ZZ_CLOCKCYCLES(16,0x80031DF4);
	goto ZZ_31DF4;
ZZ_24038_40:
	if (V0)
	{
		ZZ_CLOCKCYCLES(2,0x80024088);
		goto ZZ_24038_50;
	}
	V0 = R0;
	ZZ_CLOCKCYCLES(4,0x800240C4);
	goto ZZ_24038_8C;
ZZ_24038_50:
	A2 = 0x80060000;
	A2 = EMU_ReadU32(A2 - 17180); //+ 0xFFFFBCE4
	A0 = EMU_ReadS16(V0);
	if (!A2)
	{
		ZZ_CLOCKCYCLES(5,0x800240C0);
		goto ZZ_24038_88;
	}
	A1 = EMU_ReadS16(V0 + 2); //+ 0x2
	V0 = 0x400;
	if (A2 != V0)
	{
		ZZ_CLOCKCYCLES(9,0x800240B4);
		goto ZZ_24038_7C;
	}
	A0 = A1;
	ZZ_CLOCKCYCLES(11,0x800240C0);
	goto ZZ_24038_88;
ZZ_24038_7C:
	RA = 0x800240BC; //ZZ_24038_84
	A2 = (int32_t)A2 >> 2;
	ZZ_CLOCKCYCLES(2,0x800315D8);
	goto ZZ_315D8;
ZZ_24038_84:
	A0 = V0;
	ZZ_CLOCKCYCLES(1,0x800240C0);
ZZ_24038_88:
	V0 = A0;
	ZZ_CLOCKCYCLES(1,0x800240C4);
ZZ_24038_8C:
	RA = EMU_ReadU32(SP + 48); //+ 0x30
	SP += 56;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(4);
	ZZ_JUMPREGISTER(0x80023664,ZZ_23424_240);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80024038,0x80024078,ZZ_24038);
ZZ_MARK_TARGET(0x80024078,0x80024088,ZZ_24038_40);
ZZ_MARK_TARGET(0x80024088,0x800240B4,ZZ_24038_50);
ZZ_MARK_TARGET(0x800240B4,0x800240BC,ZZ_24038_7C);
ZZ_MARK_TARGET(0x800240BC,0x800240C0,ZZ_24038_84);
ZZ_MARK_TARGET(0x800240C0,0x800240C4,ZZ_24038_88);
ZZ_MARK_TARGET(0x800240C4,0x800240D4,ZZ_24038_8C);
