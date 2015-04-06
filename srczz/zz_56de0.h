#ifdef ZZ_INCLUDE_CODE
ZZ_56DE0:
	SP -= 32;
	EMU_Write32(SP + 20,S1); //+ 0x14
	S1 = A2;
	EMU_Write32(SP + 16,S0); //+ 0x10
	A0 <<= 16;
	A0 = (int32_t)A0 >> 16;
	EMU_Write32(SP + 24,RA); //+ 0x18
	AT = 0x80070000;
	AT += A0;
	V1 = EMU_ReadU8(AT - 26596); //+ 0xFFFF981C
	V0 = 1;
	if (V1 == V0)
	{
		S0 = A3;
		ZZ_CLOCKCYCLES(13,0x80056E1C);
		goto ZZ_56DE0_3C;
	}
	S0 = A3;
	V0 = -1;
	ZZ_CLOCKCYCLES(15,0x80057004);
	goto ZZ_56DE0_224;
ZZ_56DE0_3C:
	A1 <<= 16;
	RA = 0x80056E28; //ZZ_56DE0_48
	A1 = (int32_t)A1 >> 16;
	ZZ_CLOCKCYCLES(3,0x8005A59C);
	goto ZZ_5A59C;
ZZ_56DE0_48:
	V1 = 0x80070000;
	V1 = EMU_ReadU8(V1 - 26621); //+ 0xFFFF9803
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V1 <<= 4;
	V1 += S1;
	V1 <<= 16;
	V1 = (int32_t)V1 >> 11;
	V0 += V1;
	V0 = EMU_ReadU8(V0);
	EMU_Write8(S0,V0);
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 1); //+ 0x1
	EMU_Write8(S0 + 1,V0); //+ 0x1
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 2); //+ 0x2
	EMU_Write8(S0 + 2,V0); //+ 0x2
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 3); //+ 0x3
	EMU_Write8(S0 + 3,V0); //+ 0x3
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 4); //+ 0x4
	EMU_Write8(S0 + 4,V0); //+ 0x4
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 5); //+ 0x5
	EMU_Write8(S0 + 5,V0); //+ 0x5
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 7); //+ 0x7
	EMU_Write8(S0 + 7,V0); //+ 0x7
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 6); //+ 0x6
	EMU_Write8(S0 + 6,V0); //+ 0x6
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 8); //+ 0x8
	EMU_Write8(S0 + 8,V0); //+ 0x8
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 9); //+ 0x9
	EMU_Write8(S0 + 9,V0); //+ 0x9
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 10); //+ 0xA
	EMU_Write8(S0 + 10,V0); //+ 0xA
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 11); //+ 0xB
	EMU_Write8(S0 + 11,V0); //+ 0xB
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 12); //+ 0xC
	EMU_Write8(S0 + 12,V0); //+ 0xC
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V0 += V1;
	V0 = EMU_ReadU8(V0 + 13); //+ 0xD
	EMU_Write8(S0 + 13,V0); //+ 0xD
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	V1 += V0;
	V0 = EMU_ReadU16(V1 + 16); //+ 0x10
	EMU_Write16(S0 + 16,V0); //+ 0x10
	V0 = EMU_ReadU16(V1 + 18); //+ 0x12
	EMU_Write16(S0 + 18,V0); //+ 0x12
	V0 = EMU_ReadU16(V1 + 20); //+ 0x14
	EMU_Write16(S0 + 20,V0); //+ 0x14
	V1 = EMU_ReadU16(V1 + 22); //+ 0x16
	V0 = R0;
	EMU_Write16(S0 + 22,V1); //+ 0x16
	ZZ_CLOCKCYCLES(119,0x80057004);
ZZ_56DE0_224:
	RA = EMU_ReadU32(SP + 24); //+ 0x18
	S1 = EMU_ReadU32(SP + 20); //+ 0x14
	S0 = EMU_ReadU32(SP + 16); //+ 0x10
	SP += 32;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(6);
	ZZ_JUMPREGISTER(0x80053538,ZZ_53408_130);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80056DE0,0x80056E1C,ZZ_56DE0);
ZZ_MARK_TARGET(0x80056E1C,0x80056E28,ZZ_56DE0_3C);
ZZ_MARK_TARGET(0x80056E28,0x80057004,ZZ_56DE0_48);
ZZ_MARK_TARGET(0x80057004,0x8005701C,ZZ_56DE0_224);
