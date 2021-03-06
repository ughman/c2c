#ifdef ZZ_INCLUDE_CODE
ZZ_25624:
	SP -= 80;
	EMU_Write32(SP + 64,S6); //+ 0x40
	S6 = EMU_ReadU32(SP + 96); //+ 0x60
	EMU_Write32(SP + 68,S7); //+ 0x44
	S7 = EMU_ReadU32(SP + 100); //+ 0x64
	EMU_Write32(SP + 44,S1); //+ 0x2C
	S1 = A0;
	EMU_Write32(SP + 52,S3); //+ 0x34
	S3 = A1;
	EMU_Write32(SP + 56,S4); //+ 0x38
	S4 = A2;
	EMU_Write32(SP + 60,S5); //+ 0x3C
	S5 = A3;
	EMU_Write32(SP + 48,S2); //+ 0x30
	S2 = 0x2;
	EMU_Write32(SP + 72,FP); //+ 0x48
	FP = EMU_ReadU32(SP + 104); //+ 0x68
	V0 = SP + 32;
	EMU_Write32(SP + 76,RA); //+ 0x4C
	EMU_Write32(SP + 40,S0); //+ 0x28
	EMU_Write32(S1 + 12,S2); //+ 0xC
	EMU_Write32(SP + 24,V0); //+ 0x18
	EMU_Write32(SP + 16,S6); //+ 0x10
	RA = 0x80025688; //ZZ_25624_64
	EMU_Write32(SP + 20,S7); //+ 0x14
	ZZ_CLOCKCYCLES(25,0x80025748);
	goto ZZ_25748;
ZZ_25624_64:
	S0 = V0;
	if (!S0)
	{
		A0 = S1;
		ZZ_CLOCKCYCLES(3,0x80025704);
		goto ZZ_25624_E0;
	}
	A0 = S1;
	A1 = S3;
	A2 = S4;
	A3 = S5;
	V0 = 0x1;
	EMU_Write32(S1 + 12,V0); //+ 0xC
	V0 = SP + 36;
	EMU_Write32(SP + 16,S6); //+ 0x10
	EMU_Write32(SP + 20,S7); //+ 0x14
	RA = 0x800256BC; //ZZ_25624_98
	EMU_Write32(SP + 24,V0); //+ 0x18
	ZZ_CLOCKCYCLES(13,0x80025748);
	goto ZZ_25748;
ZZ_25624_98:
	V1 = V0;
	if ((int32_t)V1 < 0)
	{
		ZZ_CLOCKCYCLES(3,0x800256EC);
		goto ZZ_25624_C8;
	}
	if ((int32_t)S0 < 0)
	{
		V0 = (int32_t)V1 < (int32_t)S0;
		ZZ_CLOCKCYCLES(5,0x800256D8);
		goto ZZ_25624_B4;
	}
	V0 = (int32_t)V1 < (int32_t)S0;
	if (!V0)
	{
		ZZ_CLOCKCYCLES(7,0x80025704);
		goto ZZ_25624_E0;
	}
	ZZ_CLOCKCYCLES(7,0x800256D8);
ZZ_25624_B4:
	V0 = EMU_ReadU32(SP + 36); //+ 0x24
	S0 = V1;
	S2 = 0x1;
	EMU_Write32(SP + 32,V0); //+ 0x20
	ZZ_CLOCKCYCLES(5,0x80025704);
	goto ZZ_25624_E0;
ZZ_25624_C8:
	if ((int32_t)S0 >= 0)
	{
		ZZ_CLOCKCYCLES(2,0x80025704);
		goto ZZ_25624_E0;
	}
	A0 = 0x80010000;
	A0 += 960;
	RA = 0x80025704; //ZZ_25624_E0
	ZZ_CLOCKCYCLES(6,0x800494DC);
	goto ZZ_494DC;
ZZ_25624_E0:
	V1 = EMU_ReadU32(SP + 32); //+ 0x20
	V0 = S0;
	EMU_Write32(S1 + 12,S2); //+ 0xC
	EMU_Write32(FP,V1);
	RA = EMU_ReadU32(SP + 76); //+ 0x4C
	FP = EMU_ReadU32(SP + 72); //+ 0x48
	S7 = EMU_ReadU32(SP + 68); //+ 0x44
	S6 = EMU_ReadU32(SP + 64); //+ 0x40
	S5 = EMU_ReadU32(SP + 60); //+ 0x3C
	S4 = EMU_ReadU32(SP + 56); //+ 0x38
	S3 = EMU_ReadU32(SP + 52); //+ 0x34
	S2 = EMU_ReadU32(SP + 48); //+ 0x30
	S1 = EMU_ReadU32(SP + 44); //+ 0x2C
	S0 = EMU_ReadU32(SP + 40); //+ 0x28
	SP += 80;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(17);
	ZZ_JUMPREGISTER(0x800249B8,ZZ_248CC_EC);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80025624,0x80025688,ZZ_25624);
ZZ_MARK_TARGET(0x80025688,0x800256BC,ZZ_25624_64);
ZZ_MARK_TARGET(0x800256BC,0x800256D8,ZZ_25624_98);
ZZ_MARK_TARGET(0x800256D8,0x800256EC,ZZ_25624_B4);
ZZ_MARK_TARGET(0x800256EC,0x80025704,ZZ_25624_C8);
ZZ_MARK_TARGET(0x80025704,0x80025748,ZZ_25624_E0);
