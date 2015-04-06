#ifdef ZZ_INCLUDE_CODE
ZZ_418E4:
	A1 = EMU_ReadU32(T9);
	A2 = EMU_ReadU32(A0);
	A3 = 0xFFFF0000;
	A1 &= A3;
	A3 = EMU_ReadU32(V1 + 296); //+ 0x128
	A2 = A2 - A1;
	A2 = (int32_t)A2 >> 16;
	EMU_Write16(T8 + 2,A3); //+ 0x2
	A3 <<= 16;
	A3 = A3 - A1;
	A1 = EMU_ReadU32(V1 + 112); //+ 0x70
	EMU_SDivide(A3,A2);
	if (!A1)
	{
		A3 = LO;
		ZZ_CLOCKCYCLES(14,0x80041964);
		goto ZZ_418E4_80;
	}
	A3 = LO;
	A1 = EMU_ReadU8(T9 + 12); //+ 0xC
	A2 = EMU_ReadU8(A0 + 12); //+ 0xC
	A2 = A2 - A1;
	EMU_SMultiply(A2,A3);
	A2 = LO;
	A2 = (int32_t)A2 >> 16;
	A2 = EMU_CheckedAdd(A2,A1);
	EMU_Write8(T8 + 12,A2); //+ 0xC
	A1 = EMU_ReadU8(T9 + 13); //+ 0xD
	A2 = EMU_ReadU8(A0 + 13); //+ 0xD
	A2 = A2 - A1;
	EMU_SMultiply(A2,A3);
	A2 = LO;
	A2 = (int32_t)A2 >> 16;
	A2 = EMU_CheckedAdd(A2,A1);
	EMU_Write8(T8 + 13,A2); //+ 0xD
	ZZ_CLOCKCYCLES(32,0x80041964);
ZZ_418E4_80:
	A1 = EMU_ReadS16(T9);
	A2 = EMU_ReadS16(A0);
	A2 = A2 - A1;
	EMU_SMultiply(A2,A3);
	A2 = LO;
	A2 = (int32_t)A2 >> 16;
	A2 = EMU_CheckedAdd(A2,A1);
	EMU_Write16(T8,A2);
	A1 = EMU_ReadU32(T9 + 4); //+ 0x4
	A2 = EMU_ReadU32(A0 + 4); //+ 0x4
	A2 = A2 - A1;
	EMU_SMultiply(A2,A3);
	A2 = LO;
	A2 = (int32_t)A2 >> 16;
	A2 = EMU_CheckedAdd(A2,A1);
	EMU_Write32(T8 + 4,A2); //+ 0x4
	A1 = EMU_ReadU8(T9 + 8); //+ 0x8
	A2 = EMU_ReadU8(A0 + 8); //+ 0x8
	A2 = A2 - A1;
	EMU_SMultiply(A2,A3);
	A2 = LO;
	A2 = (int32_t)A2 >> 16;
	A2 = EMU_CheckedAdd(A2,A1);
	EMU_Write8(T8 + 8,A2); //+ 0x8
	A1 = EMU_ReadU8(T9 + 9); //+ 0x9
	A2 = EMU_ReadU8(A0 + 9); //+ 0x9
	A2 = A2 - A1;
	EMU_SMultiply(A2,A3);
	A2 = LO;
	A2 = (int32_t)A2 >> 16;
	A2 = EMU_CheckedAdd(A2,A1);
	EMU_Write8(T8 + 9,A2); //+ 0x9
	A1 = EMU_ReadU8(T9 + 10); //+ 0xA
	A2 = EMU_ReadU8(A0 + 10); //+ 0xA
	A2 = A2 - A1;
	EMU_SMultiply(A2,A3);
	A2 = LO;
	A2 = (int32_t)A2 >> 16;
	A2 = EMU_CheckedAdd(A2,A1);
	ZZ_JUMPREGISTER_BEGIN(RA);
	EMU_Write8(T8 + 10,A2); //+ 0xA
	ZZ_CLOCKCYCLES_JR(46);
	ZZ_JUMPREGISTER(0x8004153C,ZZ_414B0_8C);
	ZZ_JUMPREGISTER(0x80041638,ZZ_414B0_188);
	ZZ_JUMPREGISTER(0x80041730,ZZ_414B0_280);
	ZZ_JUMPREGISTER(0x80041548,ZZ_414B0_98);
	ZZ_JUMPREGISTER(0x80041644,ZZ_414B0_194);
	ZZ_JUMPREGISTER(0x8004173C,ZZ_414B0_28C);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x800418E4,0x80041964,ZZ_418E4);
ZZ_MARK_TARGET(0x80041964,0x80041A1C,ZZ_418E4_80);
