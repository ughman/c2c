#ifdef ZZ_INCLUDE_CODE
ZZ_30FE4:
	T0 = EMU_ReadU32(A0);
	T2 = EMU_ReadU32(A1);
	V1 = T0 << 8;
	V1 = (int32_t)T2 < (int32_t)V1;
	if (V1)
	{
		V0 = R0;
		ZZ_CLOCKCYCLES(6,0x80031078);
		goto ZZ_30FE4_94;
	}
	V0 = R0;
	A2 = EMU_ReadU32(A0 + 4); //+ 0x4
	T1 = EMU_ReadU32(A1 + 4); //+ 0x4
	V1 = A2 << 8;
	V1 = (int32_t)T1 < (int32_t)V1;
	if (V1)
	{
		ZZ_CLOCKCYCLES(12,0x80031078);
		goto ZZ_30FE4_94;
	}
	A3 = EMU_ReadU32(A0 + 8); //+ 0x8
	A1 = EMU_ReadU32(A1 + 8); //+ 0x8
	V1 = A3 << 8;
	V1 = (int32_t)A1 < (int32_t)V1;
	if (V1)
	{
		ZZ_CLOCKCYCLES(18,0x80031078);
		goto ZZ_30FE4_94;
	}
	V1 = EMU_ReadU32(A0 + 12); //+ 0xC
	V1 += T0;
	V1 <<= 8;
	V1 = (int32_t)T2 < (int32_t)V1;
	if (!V1)
	{
		ZZ_CLOCKCYCLES(25,0x80031078);
		goto ZZ_30FE4_94;
	}
	V1 = EMU_ReadU32(A0 + 16); //+ 0x10
	V1 += A2;
	V1 <<= 8;
	V1 = (int32_t)T1 < (int32_t)V1;
	if (!V1)
	{
		ZZ_CLOCKCYCLES(32,0x80031078);
		goto ZZ_30FE4_94;
	}
	V0 = EMU_ReadU32(A0 + 20); //+ 0x14
	V0 += A3;
	V0 <<= 8;
	V0 = (int32_t)A1 < (int32_t)V0;
	ZZ_CLOCKCYCLES(37,0x80031078);
ZZ_30FE4_94:
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(2);
	ZZ_JUMPREGISTER(0x80031094,ZZ_31080_14);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80030FE4,0x80031078,ZZ_30FE4);
ZZ_MARK_TARGET(0x80031078,0x80031080,ZZ_30FE4_94);
