#ifdef ZZ_INCLUDE_CODE
ZZ_563F0:
	SP -= 24;
	T0 = A0 << 16;
	V0 = 0x80070000;
	V0 -= 15268;
	T0 = (int32_t)T0 >> 14;
	T0 += V0;
	V0 = A1 << 16;
	V0 = (int32_t)V0 >> 16;
	V1 = V0 << 1;
	V1 += V0;
	V1 <<= 2;
	V1 = V1 - V0;
	EMU_Write32(SP + 20,RA); //+ 0x14
	EMU_Write32(SP + 16,S0); //+ 0x10
	V0 = EMU_ReadU32(T0);
	V1 <<= 4;
	S0 = V0 + V1;
	V0 = EMU_ReadU32(S0 + 152); //+ 0x98
	A2 = -2;
	V0 &= A2;
	EMU_Write32(S0 + 152,V0); //+ 0x98
	A2 = EMU_ReadU32(T0);
	A2 += V1;
	V0 = EMU_ReadU32(A2 + 152); //+ 0x98
	A3 = -3;
	V0 &= A3;
	EMU_Write32(A2 + 152,V0); //+ 0x98
	A2 = EMU_ReadU32(T0);
	A1 <<= 8;
	A2 += V1;
	V0 = EMU_ReadU32(A2 + 152); //+ 0x98
	A3 = -9;
	V0 &= A3;
	EMU_Write32(A2 + 152,V0); //+ 0x98
	A2 = EMU_ReadU32(T0);
	A0 |= A1;
	A2 += V1;
	V0 = EMU_ReadU32(A2 + 152); //+ 0x98
	A3 = -1025;
	V0 &= A3;
	EMU_Write32(A2 + 152,V0); //+ 0x98
	V0 = EMU_ReadU32(T0);
	A0 <<= 16;
	V1 += V0;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A0 = (int32_t)A0 >> 16;
	V0 |= 0x4;
	RA = 0x800564B8; //ZZ_563F0_C8
	EMU_Write32(V1 + 152,V0); //+ 0x98
	ZZ_CLOCKCYCLES(50,0x80059ED0);
	goto ZZ_59ED0;
ZZ_563F0_C8:
	RA = 0x800564C0; //ZZ_563F0_D0
	ZZ_CLOCKCYCLES(2,0x8005729C);
	goto ZZ_5729C;
ZZ_563F0_D0:
	A3 = R0;
	T2 = 64;
	T1 = 127;
	V0 = EMU_ReadU32(S0 + 132); //+ 0x84
	V1 = EMU_ReadU32(S0 + 140); //+ 0x8C
	A0 = EMU_ReadU16(S0 + 86); //+ 0x56
	A1 = EMU_ReadU32(S0 + 4); //+ 0x4
	A2 = EMU_ReadU32(S0 + 4); //+ 0x4
	T0 = S0;
	EMU_Write8(S0 + 20,R0); //+ 0x14
	EMU_Write32(S0 + 136,R0); //+ 0x88
	EMU_Write8(S0 + 28,R0); //+ 0x1C
	EMU_Write8(S0 + 24,R0); //+ 0x18
	EMU_Write8(S0 + 25,R0); //+ 0x19
	EMU_Write8(S0 + 30,R0); //+ 0x1E
	EMU_Write8(S0 + 26,R0); //+ 0x1A
	EMU_Write8(S0 + 27,R0); //+ 0x1B
	EMU_Write8(S0 + 31,R0); //+ 0x1F
	EMU_Write8(S0 + 23,R0); //+ 0x17
	EMU_Write8(S0 + 33,R0); //+ 0x21
	EMU_Write8(S0 + 28,R0); //+ 0x1C
	EMU_Write8(S0 + 29,R0); //+ 0x1D
	EMU_Write8(S0 + 21,R0); //+ 0x15
	EMU_Write8(S0 + 22,R0); //+ 0x16
	EMU_Write32(S0 + 144,V0); //+ 0x90
	EMU_Write32(S0 + 148,V1); //+ 0x94
	EMU_Write16(S0 + 84,A0); //+ 0x54
	EMU_Write32(S0,A1);
	EMU_Write32(S0 + 8,A2); //+ 0x8
	ZZ_CLOCKCYCLES(29,0x80056534);
ZZ_563F0_144:
	V0 = S0 + A3;
	EMU_Write8(V0 + 55,A3); //+ 0x37
	EMU_Write8(V0 + 39,T2); //+ 0x27
	EMU_Write16(T0 + 96,T1); //+ 0x60
	A3 += 1;
	V0 = (int32_t)A3 < 16;
	if (V0)
	{
		T0 += 2;
		ZZ_CLOCKCYCLES(8,0x80056534);
		goto ZZ_563F0_144;
	}
	T0 += 2;
	V0 = 127;
	EMU_Write16(S0 + 92,V0); //+ 0x5C
	EMU_Write16(S0 + 94,V0); //+ 0x5E
	RA = EMU_ReadU32(SP + 20); //+ 0x14
	S0 = EMU_ReadU32(SP + 16); //+ 0x10
	SP += 24;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(16);
	ZZ_JUMPREGISTER(0x800565B8,ZZ_5659C_1C);
	ZZ_JUMPREGISTER(0x8005538C,ZZ_5519C_1F0);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x800563F0,0x800564B8,ZZ_563F0);
ZZ_MARK_TARGET(0x800564B8,0x800564C0,ZZ_563F0_C8);
ZZ_MARK_TARGET(0x800564C0,0x80056534,ZZ_563F0_D0);
ZZ_MARK_TARGET(0x80056534,0x80056574,ZZ_563F0_144);
