#ifdef ZZ_INCLUDE_CODE
ZZ_4F090:
	T0 = EMU_ReadU32(A0);
	T3 = EMU_ReadU32(A1);
	T1 = T0 & 0xFFFF;
	T1 <<= 16;
	T1 = (int32_t)T1 >> 16;
	EMU_UMultiply(T1,T3);
	T4 = EMU_ReadU32(A1 + 4); //+ 0x4
	T2 = (int32_t)T0 >> 16;
	T5 = EMU_ReadU32(A1 + 8); //+ 0x8
	T0 = EMU_ReadU32(A0 + 4); //+ 0x4
	V0 = A0;
	T1 = LO;
	T1 = (int32_t)T1 >> 12;
	T1 &= 0xFFFF;
	EMU_UMultiply(T2,T4);
	T2 = LO;
	T2 = (int32_t)T2 >> 12;
	T2 <<= 16;
	T1 |= T2;
	EMU_Write32(A0,T1);
	T1 = T0 & 0xFFFF;
	T1 <<= 16;
	T1 = (int32_t)T1 >> 16;
	EMU_UMultiply(T1,T5);
	T2 = (int32_t)T0 >> 16;
	T0 = EMU_ReadU32(A0 + 8); //+ 0x8
	T1 = LO;
	T1 = (int32_t)T1 >> 12;
	T1 &= 0xFFFF;
	EMU_UMultiply(T2,T3);
	T2 = LO;
	T2 = (int32_t)T2 >> 12;
	T2 <<= 16;
	T1 |= T2;
	EMU_Write32(A0 + 4,T1); //+ 0x4
	T1 = T0 & 0xFFFF;
	T1 <<= 16;
	T1 = (int32_t)T1 >> 16;
	EMU_UMultiply(T1,T4);
	T2 = (int32_t)T0 >> 16;
	T0 = EMU_ReadU32(A0 + 12); //+ 0xC
	T1 = LO;
	T1 = (int32_t)T1 >> 12;
	T1 &= 0xFFFF;
	EMU_UMultiply(T2,T5);
	T2 = LO;
	T2 = (int32_t)T2 >> 12;
	T2 <<= 16;
	T1 |= T2;
	EMU_Write32(A0 + 8,T1); //+ 0x8
	T1 = T0 & 0xFFFF;
	T1 <<= 16;
	T1 = (int32_t)T1 >> 16;
	EMU_UMultiply(T1,T3);
	T2 = (int32_t)T0 >> 16;
	T0 = EMU_ReadU32(A0 + 16); //+ 0x10
	T1 = LO;
	T1 = (int32_t)T1 >> 12;
	T1 &= 0xFFFF;
	EMU_UMultiply(T2,T4);
	T2 = LO;
	T2 = (int32_t)T2 >> 12;
	T2 <<= 16;
	T1 |= T2;
	EMU_Write32(A0 + 12,T1); //+ 0xC
	T1 = T0 & 0xFFFF;
	T1 <<= 16;
	T1 = (int32_t)T1 >> 16;
	EMU_UMultiply(T1,T5);
	T1 = LO;
	T1 = (int32_t)T1 >> 12;
	ZZ_JUMPREGISTER_BEGIN(RA);
	EMU_Write32(A0 + 16,T1); //+ 0x10
	ZZ_CLOCKCYCLES_JR(73);
	ZZ_JUMPREGISTER(0x8001EB08,ZZ_1E9C8_140);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x8004F090,0x8004F1B4,ZZ_4F090);
