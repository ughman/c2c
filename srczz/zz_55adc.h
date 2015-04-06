#ifdef ZZ_INCLUDE_CODE
ZZ_55ADC:
	SP -= 32;
	EMU_Write32(SP + 24,S2); //+ 0x18
	S2 = A0 << 16;
	V0 = 0x80070000;
	V0 -= 15268;
	S2 = (int32_t)S2 >> 14;
	S2 += V0;
	V0 = A1 << 16;
	V0 = (int32_t)V0 >> 16;
	EMU_Write32(SP + 16,S0); //+ 0x10
	S0 = V0 << 1;
	S0 += V0;
	S0 <<= 2;
	S0 = S0 - V0;
	S0 <<= 4;
	A1 <<= 8;
	A0 |= A1;
	A0 <<= 16;
	EMU_Write32(SP + 28,RA); //+ 0x1C
	EMU_Write32(SP + 20,S1); //+ 0x14
	S1 = EMU_ReadU32(S2);
	A0 = (int32_t)A0 >> 16;
	RA = 0x80055B3C; //ZZ_55ADC_60
	S1 += S0;
	ZZ_CLOCKCYCLES(24,0x80059ED0);
	goto ZZ_59ED0;
ZZ_55ADC_60:
	EMU_Write8(S1 + 20,R0); //+ 0x14
	V0 = EMU_ReadU32(S2);
	S0 += V0;
	V0 = EMU_ReadU32(S0 + 152); //+ 0x98
	V1 = -3;
	V0 &= V1;
	EMU_Write32(S0 + 152,V0); //+ 0x98
	RA = EMU_ReadU32(SP + 28); //+ 0x1C
	S2 = EMU_ReadU32(SP + 24); //+ 0x18
	S1 = EMU_ReadU32(SP + 20); //+ 0x14
	S0 = EMU_ReadU32(SP + 16); //+ 0x10
	SP += 32;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(15);
	ZZ_JUMPREGISTER(0x8005533C,ZZ_5519C_1A0);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80055ADC,0x80055B3C,ZZ_55ADC);
ZZ_MARK_TARGET(0x80055B3C,0x80055B78,ZZ_55ADC_60);
