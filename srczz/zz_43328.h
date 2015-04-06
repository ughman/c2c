#ifdef ZZ_INCLUDE_CODE
ZZ_43328:
	V0 = 192;
	T8 = (int32_t)T1 >> 16;
	EMU_SMultiply(V0,T8);
	T9 = (int32_t)T2 >> 16;
	A1 = (int32_t)T3 >> 16;
	A2 = T3 << 16;
	T4 = EMU_CheckedSubtract(R0,T4);
	T8 = LO;
	A0 = T2 << 16;
	A0 = (int32_t)A0 >> 16;
	EMU_SMultiply(V0,T9);
	T1 &= 0xFFFF;
	T8 = (int32_t)T8 >> 8;
	T8 = EMU_CheckedSubtract(R0,T8);
	A1 = EMU_CheckedSubtract(R0,A1);
	A2 = EMU_CheckedSubtract(R0,A2);
	T9 = LO;
	T8 <<= 16;
	T1 |= T8;
	EMU_SMultiply(V0,A0);
	T9 = (int32_t)T9 >> 8;
	T9 = EMU_CheckedSubtract(R0,T9);
	T9 <<= 16;
	A1 <<= 16;
	A2 >>= 16;
	T3 = A2 | A1;
	A0 = LO;
	A0 = (int32_t)A0 >> 8;
	A0 = EMU_CheckedSubtract(R0,A0);
	A0 &= 0xFFFF;
	T2 = A0 | T9;
	ZZ_CLOCKCYCLES(32,0x80043310);
	goto ZZ_4330C_4;
#endif
ZZ_MARK_TARGET(0x80043328,0x800433A8,ZZ_43328);
