#ifdef ZZ_INCLUDE_CODE
	ZZ_CLOCKCYCLES(2,0x800433B0);
ZZ_433B0:
	T7 = EMU_ReadU32(GP + 104); //+ 0x68
	EMU_Write32(V1 + 252,T6); //+ 0xFC
	T5 = (int32_t)T5 >> 8;
	T6 = (int32_t)T6 >> 8;
	T7 = (int32_t)T7 >> 8;
	T8 = EMU_ReadU32(V1 + 52); //+ 0x34
	T9 = EMU_ReadU32(V1 + 56); //+ 0x38
	T5 = T5 - T8;
	T8 = EMU_ReadU32(V1 + 60); //+ 0x3C
	T6 = T6 - T9;
	T7 = T7 - T8;
	T0 = EMU_ReadS16(A0);
	EMU_SMultiply(T5,T0);
	T1 = EMU_ReadS16(A0 + 2); //+ 0x2
	T8 = LO;
	T9 = HI;
	T0 = EMU_ReadS16(A0 + 4); //+ 0x4
	T8 >>= 12;
	EMU_SMultiply(T6,T1);
	T9 <<= 20;
	T2 = T8 | T9;
	T8 = LO;
	T9 = HI;
	T1 = EMU_ReadS16(A0 + 6); //+ 0x6
	T8 >>= 12;
	EMU_SMultiply(T7,T0);
	T9 <<= 20;
	T8 |= T9;
	T2 += T8;
	T8 = LO;
	T9 = HI;
	T0 = EMU_ReadS16(A0 + 8); //+ 0x8
	T8 >>= 12;
	EMU_SMultiply(T5,T1);
	T9 <<= 20;
	T8 |= T9;
	T2 += T8;
	GTE_SetRegister(GTE_CREG_TRX,T2);
	T8 = LO;
	T9 = HI;
	T1 = EMU_ReadS16(A0 + 10); //+ 0xA
	T8 >>= 12;
	EMU_SMultiply(T6,T0);
	T9 <<= 20;
	T2 = T8 | T9;
	T8 = LO;
	T9 = HI;
	T0 = EMU_ReadS16(A0 + 12); //+ 0xC
	T8 >>= 12;
	EMU_SMultiply(T7,T1);
	T9 <<= 20;
	T8 |= T9;
	T2 += T8;
	T8 = LO;
	T9 = HI;
	T1 = EMU_ReadS16(A0 + 14); //+ 0xE
	T8 >>= 12;
	EMU_SMultiply(T5,T0);
	T9 <<= 20;
	T8 |= T9;
	T2 += T8;
	GTE_SetRegister(GTE_CREG_TRY,T2);
	T8 = LO;
	T9 = HI;
	T0 = EMU_ReadS16(A0 + 16); //+ 0x10
	T8 >>= 12;
	EMU_SMultiply(T6,T1);
	T9 <<= 20;
	T2 = T8 | T9;
	T8 = LO;
	T9 = HI;
	T8 >>= 12;
	T9 <<= 20;
	EMU_SMultiply(T7,T0);
	T8 |= T9;
	T2 += T8;
	T8 = LO;
	T9 = HI;
	T8 >>= 12;
	T9 <<= 20;
	T8 |= T9;
	T7 = T2 + T8;
	GTE_SetRegister(GTE_CREG_TRZ,T7);
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(86);
	ZZ_JUMPREGISTER(0x800446F0,ZZ_446A8_48);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x800433B0,0x80043508,ZZ_433B0);
