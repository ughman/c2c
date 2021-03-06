#ifdef ZZ_INCLUDE_CODE
ZZ_29A74:
	SP -= 32;
	EMU_Write32(SP + 16,S0); //+ 0x10
	S0 = A0;
	EMU_Write32(SP + 24,RA); //+ 0x18
	EMU_Write32(SP + 20,S1); //+ 0x14
	V0 = EMU_ReadU16(S0 + 2); //+ 0x2
	V0 &= 0x1;
	if (V0)
	{
		S1 = A2;
		ZZ_CLOCKCYCLES(10,0x80029ABC);
		goto ZZ_29A74_48;
	}
	S1 = A2;
	A2 = EMU_ReadU16(S0);
	A0 = S0 + 4;
	RA = 0x80029AAC; //ZZ_29A74_38
	A1 = S1 + 4;
	ZZ_CLOCKCYCLES(14,0x8003BBD8);
	goto ZZ_3BBD8;
ZZ_29A74_38:
	V1 = EMU_ReadU16(S0);
	V0 = S1;
	EMU_Write16(V0,V1);
	ZZ_CLOCKCYCLES(4,0x80029AE0);
	goto ZZ_29A74_6C;
ZZ_29A74_48:
	if (!A3)
	{
		A0 = S0;
		ZZ_CLOCKCYCLES(2,0x80029AD4);
		goto ZZ_29A74_60;
	}
	A0 = S0;
	RA = 0x80029ACC; //ZZ_29A74_58
	A2 = S1;
	ZZ_CLOCKCYCLES(4,0x8003B0EC);
	goto ZZ_3B0EC;
ZZ_29A74_58:
	V0 = S1;
	ZZ_CLOCKCYCLES(2,0x80029AE0);
	goto ZZ_29A74_6C;
ZZ_29A74_60:
	RA = 0x80029ADC; //ZZ_29A74_68
	A2 = S1;
	ZZ_CLOCKCYCLES(2,0x8003B4E4);
	goto ZZ_3B4E4;
ZZ_29A74_68:
	V0 = S1;
	ZZ_CLOCKCYCLES(1,0x80029AE0);
ZZ_29A74_6C:
	RA = EMU_ReadU32(SP + 24); //+ 0x18
	S1 = EMU_ReadU32(SP + 20); //+ 0x14
	S0 = EMU_ReadU32(SP + 16); //+ 0x10
	SP += 32;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(6);
	ZZ_JUMPREGISTER(0x8002065C,ZZ_20304_358);
	ZZ_JUMPREGISTER(0x800206A4,ZZ_20304_3A0);
	ZZ_JUMPREGISTER(0x80020714,ZZ_20304_410);
	ZZ_JUMPREGISTER(0x8002075C,ZZ_20304_458);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80029A74,0x80029AAC,ZZ_29A74);
ZZ_MARK_TARGET(0x80029AAC,0x80029ABC,ZZ_29A74_38);
ZZ_MARK_TARGET(0x80029ABC,0x80029ACC,ZZ_29A74_48);
ZZ_MARK_TARGET(0x80029ACC,0x80029AD4,ZZ_29A74_58);
ZZ_MARK_TARGET(0x80029AD4,0x80029ADC,ZZ_29A74_60);
ZZ_MARK_TARGET(0x80029ADC,0x80029AE0,ZZ_29A74_68);
ZZ_MARK_TARGET(0x80029AE0,0x80029AF8,ZZ_29A74_6C);
