#ifdef ZZ_INCLUDE_CODE
ZZ_501A0:
	SP -= 24;
	EMU_Write32(SP + 16,S0); //+ 0x10
	EMU_Write32(SP + 20,RA); //+ 0x14
	RA = 0x800501B4; //ZZ_501A0_14
	S0 = A0;
	ZZ_CLOCKCYCLES(5,0x8004A910);
	goto ZZ_4A910;
ZZ_501A0_14:
	RA = 0x800501BC; //ZZ_501A0_1C
	A0 = S0;
	ZZ_CLOCKCYCLES(2,0x8004F590);
	goto ZZ_4F590;
ZZ_501A0_1C:
	if (S0)
	{
		A0 = 0xC000;
		ZZ_CLOCKCYCLES(2,0x800501E0);
		goto ZZ_501A0_40;
	}
	A0 = 0xC000;
	V1 = 23;
	V0 = 0x80060000;
	V0 -= 5310;
	ZZ_CLOCKCYCLES(5,0x800501D0);
ZZ_501A0_30:
	EMU_Write16(V0,A0);
	V1 -= 1;
	if ((int32_t)V1 >= 0)
	{
		V0 -= 2;
		ZZ_CLOCKCYCLES(4,0x800501D0);
		goto ZZ_501A0_30;
	}
	V0 -= 2;
	ZZ_CLOCKCYCLES(4,0x800501E0);
ZZ_501A0_40:
	RA = 0x800501E8; //ZZ_501A0_48
	ZZ_CLOCKCYCLES(2,0x80050288);
	goto ZZ_50288;
ZZ_501A0_48:
	A0 = 209;
	V0 = 0x80060000;
	V0 -= 5380;
	A1 = 0x80060000;
	A1 = EMU_ReadU32(A1 - 4264); //+ 0xFFFFEF58
	AT = 0x80060000;
	EMU_Write32(AT - 5396,R0); //+ 0xFFFFEAEC
	AT = 0x80060000;
	EMU_Write32(AT - 5392,R0); //+ 0xFFFFEAF0
	EMU_Write32(V0,R0);
	EMU_Write16(V0 + 4,R0); //+ 0x4
	EMU_Write16(V0 + 6,R0); //+ 0x6
	EMU_Write32(V0 + 8,R0); //+ 0x8
	EMU_Write32(V0 + 12,R0); //+ 0xC
	AT = 0x80060000;
	EMU_Write32(AT - 5388,A1); //+ 0xFFFFEAF4
	RA = 0x80050230; //ZZ_501A0_90
	A2 = R0;
	ZZ_CLOCKCYCLES(18,0x8004FE9C);
	goto ZZ_4FE9C;
ZZ_501A0_90:
	AT = 0x80060000;
	EMU_Write32(AT - 5432,R0); //+ 0xFFFFEAC8
	AT = 0x80060000;
	EMU_Write32(AT - 5428,R0); //+ 0xFFFFEACC
	AT = 0x80060000;
	EMU_Write32(AT - 5424,R0); //+ 0xFFFFEAD0
	AT = 0x80060000;
	EMU_Write32(AT - 5400,R0); //+ 0xFFFFEAE8
	AT = 0x80060000;
	EMU_Write32(AT - 5500,R0); //+ 0xFFFFEA84
	AT = 0x80060000;
	EMU_Write32(AT - 5404,R0); //+ 0xFFFFEAE4
	AT = 0x80060000;
	EMU_Write32(AT - 5360,R0); //+ 0xFFFFEB10
	AT = 0x80060000;
	EMU_Write32(AT - 5364,R0); //+ 0xFFFFEB0C
	AT = 0x80060000;
	EMU_Write32(AT - 5308,R0); //+ 0xFFFFEB44
	RA = EMU_ReadU32(SP + 20); //+ 0x14
	S0 = EMU_ReadU32(SP + 16); //+ 0x10
	ZZ_JUMPREGISTER_BEGIN(RA);
	SP += 24;
	ZZ_CLOCKCYCLES_JR(22);
	ZZ_JUMPREGISTER(0x80053004,ZZ_52FF4_10);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x800501A0,0x800501B4,ZZ_501A0);
ZZ_MARK_TARGET(0x800501B4,0x800501BC,ZZ_501A0_14);
ZZ_MARK_TARGET(0x800501BC,0x800501D0,ZZ_501A0_1C);
ZZ_MARK_TARGET(0x800501D0,0x800501E0,ZZ_501A0_30);
ZZ_MARK_TARGET(0x800501E0,0x800501E8,ZZ_501A0_40);
ZZ_MARK_TARGET(0x800501E8,0x80050230,ZZ_501A0_48);
ZZ_MARK_TARGET(0x80050230,0x80050288,ZZ_501A0_90);
