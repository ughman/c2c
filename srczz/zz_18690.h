#ifdef ZZ_INCLUDE_CODE
ZZ_18690:
	T2 = A0;
	V1 = EMU_ReadU32(A3 + 16); //+ 0x10
	A0 = EMU_ReadU16(A3);
	T3 = EMU_ReadU32(SP + 16); //+ 0x10
	V1 <<= 16;
	A2 = A0 | V1;
	GTE_SetRegister(GTE_DREG_VXY0,A2);
	T4 = R0;
	GTE_SetRegister(GTE_DREG_VZ0,T4);
	V0 = EMU_ReadU16(A3 + 12); //+ 0xC
	A2 = V0 | V1;
	GTE_SetRegister(GTE_DREG_VXY1,A2);
	GTE_SetRegister(GTE_DREG_VZ1,T4);
	V0 = EMU_ReadU32(A3 + 4); //+ 0x4
	V0 <<= 16;
	A2 = A0 | V0;
	GTE_SetRegister(GTE_DREG_VXY2,A2);
	GTE_SetRegister(GTE_DREG_VZ2,T4);
	GTE_RotateTranslateProjectTriple();
	A2 = GTE_GetRegister(GTE_CREG_FLAG);
	if ((int32_t)A2 < 0)
	{
		ZZ_CLOCKCYCLES(25,0x800187F4);
		goto ZZ_18690_164;
	}
	V1 = 0x80060000;
	V1 = EMU_ReadU32(V1 + 14064); //+ 0x36F0
	A0 = EMU_ReadU32(V1 + 8); //+ 0x8
	V0 = A0 + 40;
	EMU_Write32(V1 + 8,V0); //+ 0x8
	V0 = EMU_ReadU32(T2);
	T1 = A0;
	EMU_Write32(A0 + 4,V0); //+ 0x4
	T0 = GTE_GetRegister(GTE_DREG_SZ1);
	A2 = GTE_GetRegister(GTE_DREG_SZ2);
	EMU_Write32(T1 + 24,GTE_GetRegister(GTE_DREG_SXY2)); //+ 0x18
	T0 += A2;
	A2 = GTE_GetRegister(GTE_DREG_SZ3);
	EMU_Write32(T1 + 16,GTE_GetRegister(GTE_DREG_SXY1)); //+ 0x10
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 + 2844); //+ 0xB1C
	A0 = A1 + 2048;
	V1 = V0 >> 31;
	V0 += V1;
	V0 = (int32_t)V0 >> 1;
	A0 = A0 - V0;
	V0 = T0 + A2;
	V0 >>= 5;
	T0 = A0 - V0;
	V0 = (int32_t)T0 < 2047;
	if (!V0)
	{
		ZZ_CLOCKCYCLES(54,0x8001877C);
		goto ZZ_18690_EC;
	}
	if ((int32_t)T0 < 0)
	{
		A1 = T3;
		ZZ_CLOCKCYCLES(56,0x80018780);
		goto ZZ_18690_F0;
	}
	A1 = T3;
	V0 = T0 << 2;
	A1 += V0;
	ZZ_CLOCKCYCLES(59,0x80018780);
	goto ZZ_18690_F0;
ZZ_18690_EC:
	A1 = T3 + 8188;
	ZZ_CLOCKCYCLES(1,0x80018780);
ZZ_18690_F0:
	V1 = EMU_ReadU32(A1);
	A0 = 0xFF0000;
	A0 |= 0xFFFF;
	V0 = 0x9000000;
	A0 &= T1;
	V1 |= V0;
	EMU_Write32(T1,V1);
	EMU_Write32(A1,A0);
	V0 = EMU_ReadU32(A3 + 4); //+ 0x4
	V1 = EMU_ReadU16(A3 + 12); //+ 0xC
	V0 <<= 16;
	A2 = V1 | V0;
	EMU_Write32(T1 + 8,GTE_GetRegister(GTE_DREG_SXY0)); //+ 0x8
	GTE_SetRegister(GTE_DREG_VXY0,A2);
	T4 = R0;
	GTE_SetRegister(GTE_DREG_VZ0,T4);
	GTE_RotateTranslateProjectSingle();
	V0 = EMU_ReadU32(T2 + 4); //+ 0x4
	EMU_Write32(T1 + 12,V0); //+ 0xC
	V0 = EMU_ReadU32(T2 + 8); //+ 0x8
	EMU_Write32(T1 + 20,V0); //+ 0x14
	V0 = EMU_ReadU32(T2 + 12); //+ 0xC
	EMU_Write16(T1 + 28,V0); //+ 0x1C
	V0 >>= 16;
	EMU_Write16(T1 + 36,V0); //+ 0x24
	EMU_Write32(T1 + 32,GTE_GetRegister(GTE_DREG_SXY2)); //+ 0x20
	ZZ_CLOCKCYCLES(29,0x800187F4);
ZZ_18690_164:
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(2);
	ZZ_JUMPREGISTER(0x8001BE84,ZZ_1B974_510);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80018690,0x8001877C,ZZ_18690);
ZZ_MARK_TARGET(0x8001877C,0x80018780,ZZ_18690_EC);
ZZ_MARK_TARGET(0x80018780,0x800187F4,ZZ_18690_F0);
ZZ_MARK_TARGET(0x800187F4,0x800187FC,ZZ_18690_164);
