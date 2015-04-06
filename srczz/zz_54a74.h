#ifdef ZZ_INCLUDE_CODE
ZZ_54A74:
	SP -= 32;
	EMU_Write32(SP + 20,S1); //+ 0x14
	S1 = A0 << 16;
	V0 = 0x80070000;
	V0 -= 15268;
	S1 = (int32_t)S1 >> 14;
	S1 += V0;
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
	EMU_Write32(SP + 24,RA); //+ 0x18
	A2 = EMU_ReadU32(S1);
	A0 = (int32_t)A0 >> 16;
	A2 += S0;
	A1 = A2 + 92;
	RA = 0x80054AD8; //ZZ_54A74_64
	A2 += 94;
	ZZ_CLOCKCYCLES(25,0x80059DDC);
	goto ZZ_59DDC;
ZZ_54A74_64:
	V1 = EMU_ReadU32(S1);
	V1 += S0;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A0 = -2;
	V0 &= A0;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	V1 = EMU_ReadU32(S1);
	V1 += S0;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A0 = -9;
	V0 &= A0;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	V0 = EMU_ReadU32(S1);
	S0 += V0;
	V0 = EMU_ReadU32(S0 + 152); //+ 0x98
	V0 |= 0x2;
	EMU_Write32(S0 + 152,V0); //+ 0x98
	RA = EMU_ReadU32(SP + 24); //+ 0x18
	S1 = EMU_ReadU32(SP + 20); //+ 0x14
	S0 = EMU_ReadU32(SP + 16); //+ 0x10
	SP += 32;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(27);
	ZZ_JUMPREGISTER(0x80054B88,ZZ_54B6C_1C);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80054A74,0x80054AD8,ZZ_54A74);
ZZ_MARK_TARGET(0x80054AD8,0x80054B44,ZZ_54A74_64);
