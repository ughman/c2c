#ifdef ZZ_INCLUDE_CODE
ZZ_125F8:
	T0 = A0;
	A1 = 0x12340000;
	T1 = EMU_ReadU32(T0 + 12); //+ 0xC
	A1 |= 0x5678;
	A3 = T0;
	A2 = 0x3FFF;
	EMU_Write32(T0 + 12,R0); //+ 0xC
	ZZ_CLOCKCYCLES(7,0x80012614);
ZZ_125F8_1C:
	A0 = EMU_ReadU32(A3);
	A3 += 4;
	A2 -= 1;
	V0 = A0 & 0xFF;
	A1 += V0;
	V1 = A1 << 3;
	V0 = A1 >> 29;
	A1 = V1 | V0;
	V0 = A0 >> 8;
	V0 &= 0xFF;
	A1 += V0;
	V1 = A1 << 3;
	V0 = A1 >> 29;
	A1 = V1 | V0;
	V0 = A0 >> 16;
	V0 &= 0xFF;
	A1 += V0;
	V1 = A1 << 3;
	V0 = A1 >> 29;
	A1 = V1 | V0;
	A0 >>= 24;
	A1 += A0;
	V1 = A1 << 3;
	V0 = A1 >> 29;
	if ((int32_t)A2 >= 0)
	{
		A1 = V1 | V0;
		ZZ_CLOCKCYCLES(26,0x80012614);
		goto ZZ_125F8_1C;
	}
	A1 = V1 | V0;
	EMU_Write32(T0 + 12,T1); //+ 0xC
	ZZ_JUMPREGISTER_BEGIN(RA);
	V0 = A1;
	ZZ_CLOCKCYCLES_JR(29);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x800125F8,0x80012614,ZZ_125F8);
ZZ_MARK_TARGET(0x80012614,0x80012688,ZZ_125F8_1C);
