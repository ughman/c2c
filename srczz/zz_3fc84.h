#ifdef ZZ_INCLUDE_CODE
ZZ_3FC84:
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
		ZZ_CLOCKCYCLES(14,0x8003FD04);
		goto ZZ_3FC84_80;
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
	ZZ_CLOCKCYCLES(32,0x8003FD04);
ZZ_3FC84_80:
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
	ZZ_JUMPREGISTER(0x8003F8C0,ZZ_3F834_8C);
	ZZ_JUMPREGISTER(0x8003F9C8,ZZ_3F834_194);
	ZZ_JUMPREGISTER(0x8003FAD0,ZZ_3F834_29C);
	ZZ_JUMPREGISTER(0x8003F8CC,ZZ_3F834_98);
	ZZ_JUMPREGISTER(0x8003F9D4,ZZ_3F834_1A0);
	ZZ_JUMPREGISTER(0x8003FADC,ZZ_3F834_2A8);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x8003FC84,0x8003FD04,ZZ_3FC84);
ZZ_MARK_TARGET(0x8003FD04,0x8003FDBC,ZZ_3FC84_80);
