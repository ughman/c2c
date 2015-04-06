#ifdef ZZ_INCLUDE_CODE
ZZ_187FC:
	T2 = EMU_ReadU32(SP + 16); //+ 0x10
	T0 = A0;
	V1 = EMU_ReadU32(T2 + 16); //+ 0x10
	A0 = EMU_ReadU16(T2);
	T4 = EMU_ReadU32(SP + 20); //+ 0x14
	T3 = EMU_ReadU32(SP + 24); //+ 0x18
	V1 <<= 16;
	A3 = A0 | V1;
	GTE_SetRegister(GTE_DREG_VXY0,A3);
	T5 = R0;
	GTE_SetRegister(GTE_DREG_VZ0,T5);
	V0 = EMU_ReadU16(T2 + 12); //+ 0xC
	A3 = V0 | V1;
	GTE_SetRegister(GTE_DREG_VXY1,A3);
	GTE_SetRegister(GTE_DREG_VZ1,T5);
	V0 = EMU_ReadU32(T2 + 4); //+ 0x4
	V0 <<= 16;
	A3 = A0 | V0;
	GTE_SetRegister(GTE_DREG_VXY2,A3);
	GTE_SetRegister(GTE_DREG_VZ2,T5);
	GTE_RotateTranslateProjectTriple();
	A3 = GTE_GetRegister(GTE_CREG_FLAG);
	if ((int32_t)A3 < 0)
	{
		ZZ_CLOCKCYCLES(27,0x80018AE0);
		goto ZZ_187FC_2E4;
	}
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 + 14064); //+ 0x36F0
	A0 = EMU_ReadU32(V0 + 8); //+ 0x8
	V1 = A0 + 52;
	T1 = A0;
	if (!T3)
	{
		EMU_Write32(V0 + 8,V1); //+ 0x8
		ZZ_CLOCKCYCLES(36,0x800189E0);
		goto ZZ_187FC_1E4;
	}
	EMU_Write32(V0 + 8,V1); //+ 0x8
	V1 = EMU_ReadU8(A1);
	V0 = EMU_ReadS16(T0 + 40); //+ 0x28
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 4,V0); //+ 0x4
	V1 = EMU_ReadU8(A1 + 1); //+ 0x1
	V0 = EMU_ReadS16(T0 + 42); //+ 0x2A
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 5,V0); //+ 0x5
	V1 = EMU_ReadU8(A1 + 2); //+ 0x2
	V0 = EMU_ReadS16(T0 + 44); //+ 0x2C
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 6,V0); //+ 0x6
	V1 = EMU_ReadU8(A1);
	V0 = EMU_ReadS16(T0 + 46); //+ 0x2E
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 16,V0); //+ 0x10
	V1 = EMU_ReadU8(A1 + 1); //+ 0x1
	V0 = EMU_ReadS16(T0 + 48); //+ 0x30
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 17,V0); //+ 0x11
	V1 = EMU_ReadU8(A1 + 2); //+ 0x2
	V0 = EMU_ReadS16(T0 + 50); //+ 0x32
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 18,V0); //+ 0x12
	V1 = EMU_ReadU8(A1);
	V0 = EMU_ReadS16(T0 + 52); //+ 0x34
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 28,V0); //+ 0x1C
	V1 = EMU_ReadU8(A1 + 1); //+ 0x1
	V0 = EMU_ReadS16(T0 + 54); //+ 0x36
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 29,V0); //+ 0x1D
	V1 = EMU_ReadU8(A1 + 2); //+ 0x2
	V0 = EMU_ReadS16(T0 + 56); //+ 0x38
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 30,V0); //+ 0x1E
	V1 = EMU_ReadU8(A1);
	V0 = EMU_ReadS16(T0 + 58); //+ 0x3A
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 40,V0); //+ 0x28
	V1 = EMU_ReadU8(A1 + 1); //+ 0x1
	V0 = EMU_ReadS16(T0 + 60); //+ 0x3C
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 41,V0); //+ 0x29
	V1 = EMU_ReadU8(A1 + 2); //+ 0x2
	V0 = EMU_ReadS16(T0 + 62); //+ 0x3E
	EMU_SMultiply(V1,V0);
	T5 = LO;
	V0 = (int32_t)T5 >> 7;
	EMU_Write8(T1 + 42,V0); //+ 0x2A
	ZZ_CLOCKCYCLES(121,0x800189F8);
	goto ZZ_187FC_1FC;
ZZ_187FC_1E4:
	V0 = EMU_ReadU32(A1);
	EMU_Write32(T1 + 4,V0); //+ 0x4
	EMU_Write32(T1 + 16,V0); //+ 0x10
	EMU_Write32(T1 + 28,V0); //+ 0x1C
	EMU_Write32(T1 + 40,V0); //+ 0x28
	ZZ_CLOCKCYCLES(6,0x800189F8);
ZZ_187FC_1FC:
	T0 = GTE_GetRegister(GTE_DREG_SZ1);
	V0 = EMU_ReadU8(A1 + 3); //+ 0x3
	V0 |= 0x3C;
	EMU_Write8(T1 + 7,V0); //+ 0x7
	A3 = GTE_GetRegister(GTE_DREG_SZ2);
	EMU_Write32(T1 + 32,GTE_GetRegister(GTE_DREG_SXY2)); //+ 0x20
	T0 += A3;
	A3 = GTE_GetRegister(GTE_DREG_SZ3);
	EMU_Write32(T1 + 20,GTE_GetRegister(GTE_DREG_SXY1)); //+ 0x14
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 + 2844); //+ 0xB1C
	A0 = A2 + 2048;
	V1 = V0 >> 31;
	V0 += V1;
	V0 = (int32_t)V0 >> 1;
	A0 = A0 - V0;
	V0 = T0 + A3;
	V0 >>= 5;
	T0 = A0 - V0;
	V0 = (int32_t)T0 < 2047;
	if (!V0)
	{
		ZZ_CLOCKCYCLES(23,0x80018A68);
		goto ZZ_187FC_26C;
	}
	if ((int32_t)T0 < 0)
	{
		A2 = T4;
		ZZ_CLOCKCYCLES(25,0x80018A6C);
		goto ZZ_187FC_270;
	}
	A2 = T4;
	V0 = T0 << 2;
	A2 += V0;
	ZZ_CLOCKCYCLES(28,0x80018A6C);
	goto ZZ_187FC_270;
ZZ_187FC_26C:
	A2 = T4 + 8188;
	ZZ_CLOCKCYCLES(1,0x80018A6C);
ZZ_187FC_270:
	V1 = EMU_ReadU32(A2);
	A0 = 0xFF0000;
	A0 |= 0xFFFF;
	V0 = 0xC000000;
	A0 &= T1;
	V1 |= V0;
	EMU_Write32(T1,V1);
	EMU_Write32(A2,A0);
	V0 = EMU_ReadU32(T2 + 4); //+ 0x4
	V1 = EMU_ReadU16(T2 + 12); //+ 0xC
	V0 <<= 16;
	A3 = V1 | V0;
	EMU_Write32(T1 + 8,GTE_GetRegister(GTE_DREG_SXY0)); //+ 0x8
	GTE_SetRegister(GTE_DREG_VXY0,A3);
	T5 = R0;
	GTE_SetRegister(GTE_DREG_VZ0,T5);
	GTE_RotateTranslateProjectSingle();
	V0 = EMU_ReadU32(A1 + 4); //+ 0x4
	EMU_Write32(T1 + 12,V0); //+ 0xC
	V0 = EMU_ReadU32(A1 + 8); //+ 0x8
	EMU_Write32(T1 + 24,V0); //+ 0x18
	V0 = EMU_ReadU32(A1 + 12); //+ 0xC
	EMU_Write16(T1 + 36,V0); //+ 0x24
	V0 >>= 16;
	EMU_Write16(T1 + 48,V0); //+ 0x30
	EMU_Write32(T1 + 44,GTE_GetRegister(GTE_DREG_SXY2)); //+ 0x2C
	ZZ_CLOCKCYCLES(29,0x80018AE0);
ZZ_187FC_2E4:
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(2);
	ZZ_JUMPREGISTER(0x8001BDD8,ZZ_1B974_464);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x800187FC,0x800189E0,ZZ_187FC);
ZZ_MARK_TARGET(0x800189E0,0x800189F8,ZZ_187FC_1E4);
ZZ_MARK_TARGET(0x800189F8,0x80018A68,ZZ_187FC_1FC);
ZZ_MARK_TARGET(0x80018A68,0x80018A6C,ZZ_187FC_26C);
ZZ_MARK_TARGET(0x80018A6C,0x80018AE0,ZZ_187FC_270);
ZZ_MARK_TARGET(0x80018AE0,0x80018AE8,ZZ_187FC_2E4);
