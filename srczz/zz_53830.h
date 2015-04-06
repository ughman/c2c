#ifdef ZZ_INCLUDE_CODE
ZZ_53830:
	SP -= 48;
	EMU_Write32(SP + 40,S4); //+ 0x28
	S4 = A0 << 16;
	S4 = (int32_t)S4 >> 16;
	V1 = S4 << 2;
	EMU_Write32(SP + 36,S3); //+ 0x24
	S3 = A1 << 16;
	S3 = (int32_t)S3 >> 16;
	V0 = S3 << 1;
	V0 += S3;
	V0 <<= 2;
	V0 = V0 - S3;
	V0 <<= 4;
	A1 <<= 8;
	A0 |= A1;
	A0 <<= 16;
	A0 = (int32_t)A0 >> 16;
	EMU_Write32(SP + 24,S0); //+ 0x18
	S0 = A2;
	EMU_Write32(SP + 44,RA); //+ 0x2C
	EMU_Write32(SP + 32,S2); //+ 0x20
	EMU_Write32(SP + 28,S1); //+ 0x1C
	AT = 0x80070000;
	AT += V1;
	S1 = EMU_ReadU32(AT - 15268); //+ 0xFFFFC45C
	A3 = S0 & 0xFF;
	S1 += V0;
	S2 = EMU_ReadU8(S1 + 23); //+ 0x17
	A1 = EMU_ReadU8(S1 + 38); //+ 0x26
	V0 = S1 + S2;
	V1 = EMU_ReadU8(V0 + 55); //+ 0x37
	V0 = EMU_ReadU8(V0 + 39); //+ 0x27
	A2 = V1;
	RA = 0x800538BC; //ZZ_53830_8C
	EMU_Write32(SP + 16,V0); //+ 0x10
	ZZ_CLOCKCYCLES(35,0x8005A020);
	goto ZZ_5A020;
ZZ_53830_8C:
	A0 = S4;
	A1 = S3;
	S2 <<= 1;
	S2 += S1;
	S0 &= 0xFF;
	RA = 0x800538D8; //ZZ_53830_A8
	EMU_Write16(S2 + 96,S0); //+ 0x60
	ZZ_CLOCKCYCLES(7,0x800545DC);
	goto ZZ_545DC;
ZZ_53830_A8:
	EMU_Write32(S1 + 144,V0); //+ 0x90
	RA = EMU_ReadU32(SP + 44); //+ 0x2C
	S4 = EMU_ReadU32(SP + 40); //+ 0x28
	S3 = EMU_ReadU32(SP + 36); //+ 0x24
	S2 = EMU_ReadU32(SP + 32); //+ 0x20
	S1 = EMU_ReadU32(SP + 28); //+ 0x1C
	S0 = EMU_ReadU32(SP + 24); //+ 0x18
	SP += 48;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(10);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80053830,0x800538BC,ZZ_53830);
ZZ_MARK_TARGET(0x800538BC,0x800538D8,ZZ_53830_8C);
ZZ_MARK_TARGET(0x800538D8,0x80053900,ZZ_53830_A8);
