#ifdef ZZ_INCLUDE_CODE
ZZ_4EC08:
	SP -= 24;
	EMU_Write32(SP + 16,RA); //+ 0x10
	RA = 0x8004EC18; //ZZ_4EC08_10
	A0 = -1;
	ZZ_CLOCKCYCLES(4,0x8004A71C);
	goto ZZ_4A71C;
ZZ_4EC08_10:
	V0 += 240;
	AT = 0x80060000;
	EMU_Write32(AT - 7988,V0); //+ 0xFFFFE0CC
	AT = 0x80060000;
	EMU_Write32(AT - 7984,R0); //+ 0xFFFFE0D0
	RA = EMU_ReadU32(SP + 16); //+ 0x10
	SP += 24;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(9);
	ZZ_JUMPREGISTER(0x8004EAD8,ZZ_4EAC0_18);
	ZZ_JUMPREGISTER(0x8004E010,ZZ_4DFE8_28);
	ZZ_JUMPREGISTER(0x8004E3C4,ZZ_4E398_2C);
	ZZ_JUMPREGISTER(0x8004DDD8,ZZ_4DDAC_2C);
	ZZ_JUMPREGISTER(0x8004DAE4,ZZ_4DA68_7C);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x8004EC08,0x8004EC18,ZZ_4EC08);
ZZ_MARK_TARGET(0x8004EC18,0x8004EC3C,ZZ_4EC08_10);
