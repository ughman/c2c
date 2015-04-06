#ifdef ZZ_INCLUDE_CODE
ZZ_31128:
	A2 = A0;
	A3 = EMU_ReadU32(A1);
	A0 = EMU_ReadU32(A2 + 12); //+ 0xC
	V1 = A3 << 8;
	V1 = (int32_t)V1 < (int32_t)A0;
	if (!V1)
	{
		V0 = R0;
		ZZ_CLOCKCYCLES(7,0x800311C4);
		goto ZZ_31128_9C;
	}
	V0 = R0;
	T0 = EMU_ReadU32(A1 + 4); //+ 0x4
	A0 = EMU_ReadU32(A2 + 16); //+ 0x10
	V1 = T0 << 8;
	V1 = (int32_t)V1 < (int32_t)A0;
	if (!V1)
	{
		ZZ_CLOCKCYCLES(13,0x800311C4);
		goto ZZ_31128_9C;
	}
	T1 = EMU_ReadU32(A1 + 8); //+ 0x8
	A0 = EMU_ReadU32(A2 + 20); //+ 0x14
	V1 = T1 << 8;
	V1 = (int32_t)V1 < (int32_t)A0;
	if (!V1)
	{
		ZZ_CLOCKCYCLES(19,0x800311C4);
		goto ZZ_31128_9C;
	}
	V1 = EMU_ReadU32(A1 + 12); //+ 0xC
	A0 = EMU_ReadU32(A2);
	V1 += A3;
	V1 <<= 8;
	V1 = (int32_t)V1 < (int32_t)A0;
	if (V1)
	{
		ZZ_CLOCKCYCLES(26,0x800311C4);
		goto ZZ_31128_9C;
	}
	V1 = EMU_ReadU32(A1 + 16); //+ 0x10
	A0 = EMU_ReadU32(A2 + 4); //+ 0x4
	V1 += T0;
	V1 <<= 8;
	V1 = (int32_t)V1 < (int32_t)A0;
	if (V1)
	{
		ZZ_CLOCKCYCLES(33,0x800311C4);
		goto ZZ_31128_9C;
	}
	V0 = EMU_ReadU32(A1 + 20); //+ 0x14
	V1 = EMU_ReadU32(A2 + 8); //+ 0x8
	V0 += T1;
	V0 <<= 8;
	V0 = (int32_t)V0 < (int32_t)V1;
	V0 ^= 0x1;
	ZZ_CLOCKCYCLES(39,0x800311C4);
ZZ_31128_9C:
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(2);
	ZZ_JUMPREGISTER(0x80029934,ZZ_297AC_188);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80031128,0x800311C4,ZZ_31128);
ZZ_MARK_TARGET(0x800311C4,0x800311CC,ZZ_31128_9C);
