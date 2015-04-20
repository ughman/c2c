#ifdef ZZ_INCLUDE_CODE
ZZ_451EC:
	SP -= 64;
	EMU_Write32(SP + 16,S0); //+ 0x10
	EMU_Write32(SP + 20,S1); //+ 0x14
	EMU_Write32(SP + 24,S2); //+ 0x18
	EMU_Write32(SP + 28,S3); //+ 0x1C
	EMU_Write32(SP + 32,S4); //+ 0x20
	EMU_Write32(SP + 36,S5); //+ 0x24
	EMU_Write32(SP + 40,S6); //+ 0x28
	EMU_Write32(SP + 44,S7); //+ 0x2C
	EMU_Write32(SP + 48,T8); //+ 0x30
	EMU_Write32(SP + 52,T9); //+ 0x34
	EMU_Write32(SP + 56,GP); //+ 0x38
	EMU_Write32(SP + 60,FP); //+ 0x3C
	V1 = 0x1F800000;
	EMU_Write32(V1,SP);
	SP = A0;
	FP = A1;
	GTE_SetRegister(GTE_CREG_TRX,R0);
	GTE_SetRegister(GTE_CREG_TRY,R0);
	GTE_SetRegister(GTE_CREG_TRZ,R0);
	GTE_SetRegister(GTE_DREG_VXY2,R0);
	T8 = 256;
	GTE_SetRegister(GTE_DREG_VZ2,R0);
	S7 = EMU_ReadU32(FP + 8); //+ 0x8
	A0 = EMU_ReadU32(A2 + 12); //+ 0xC
	T0 = EMU_ReadU32(A2 + 84); //+ 0x54
	T1 = EMU_ReadU32(A2 + 88); //+ 0x58
	T2 = EMU_ReadU32(A2 + 92); //+ 0x5C
	T3 = EMU_ReadU32(A2 + 96); //+ 0x60
	T4 = EMU_ReadU32(A2 + 100); //+ 0x64
	T5 = EMU_ReadU32(A2 + 104); //+ 0x68
	S5 = EMU_ReadU32(A2 + 108); //+ 0x6C
	S3 = EMU_ReadU32(A2 + 112); //+ 0x70
	T8 = EMU_ReadU32(A2 + 116); //+ 0x74
	S1 = 0xFFFE0000;
	S1 |= 0xFFFF;
	S2 = 0xFFF0000;
	S2 |= 0x1FFF;
	S3 = EMU_CheckedAdd(S3,2048);
	S3 <<= 16;
	S3 |= 0x1000;
	T8 <<= 2;
	S4 = FP + T8;
	T0 &= S1;
	T2 &= S1;
	T8 = EMU_ReadU32(A0 + 20); //+ 0x14
	T9 = EMU_ReadU32(A0 + 24); //+ 0x18
	A0 = EMU_ReadU32(A0 + 28); //+ 0x1C
	T8 &= 0xFFFF;
	T9 <<= 16;
	T8 |= T9;
	T8 &= S1;
	T0 = T0 - T8;
	T1 = T1 - A0;
	T2 = T2 - T8;
	T3 = T3 - A0;
	T0 &= S1;
	T2 &= S1;
	T7 = T0 - T2;
	S0 = T1 - T3;
	AT = 0x30120000;
	AT |= 0x5400;
	S6 = 0x49350000;
	S6 |= 0x83FE;
	T8 = 0x52000000;
	T4 |= T8;
	ZZ_CLOCKCYCLES(67,0x80045440);
	goto ZZ_451EC_254;
ZZ_451EC_10C:
	T9 = S6 << 24;
	S6 >>= 8;
	A3 = AT + S6;
	AT >>= 8;
	AT |= T9;
	T9 = AT >> 8;
	A3 += T9;
	A3 <<= 24;
	S6 |= A3;
	T9 = S6 << 24;
	S6 >>= 8;
	V0 = AT + S6;
	AT >>= 8;
	AT |= T9;
	T9 = AT >> 8;
	V0 += T9;
	V0 <<= 24;
	S6 |= V0;
	T9 = S6 << 24;
	S6 >>= 8;
	T8 = AT + S6;
	AT >>= 8;
	AT |= T9;
	T9 = AT >> 8;
	T8 += T9;
	T8 <<= 24;
	S6 |= T8;
	A3 >>= 19;
	V0 >>= 4;
	A3 |= V0;
	A2 = A3 + T0;
	A3 += T2;
	A2 &= S2;
	A3 &= S2;
	T9 = A2 - A3;
	if (T9 != T7)
	{
		A2 = A2 - S3;
		ZZ_CLOCKCYCLES(37,0x80045440);
		goto ZZ_451EC_254;
	}
	A2 = A2 - S3;
	A3 = A3 - S3;
	A2 &= S1;
	A3 &= S1;
	GTE_SetRegister(GTE_DREG_VXY0,A2);
	GTE_SetRegister(GTE_DREG_VXY1,A3);
	T8 >>= 18;
	A0 = T8 + T1;
	A1 = T8 + T3;
	A0 &= 0x1FFF;
	A1 &= 0x1FFF;
	T8 = A0 - A1;
	if (T8 != S0)
	{
		A0 = EMU_CheckedAdd(A0,-7168);
		ZZ_CLOCKCYCLES(50,0x80045440);
		goto ZZ_451EC_254;
	}
	A0 = EMU_CheckedAdd(A0,-7168);
	A1 = EMU_CheckedAdd(A1,-7168);
	GTE_SetRegister(GTE_DREG_VZ0,A0);
	GTE_SetRegister(GTE_DREG_VZ1,A1);
	A2 = S7 << 8;
	A2 >>= 8;
	GTE_RotateTranslateProjectTriple();
	T8 = EMU_ReadU32(S4 + 24); //+ 0x18
	EMU_Write32(S7 + 4,T4); //+ 0x4
	T9 = 0x4000000;
	T8 |= T9;
	EMU_Write32(S7,T8);
	A3 = 0x1010000;
	A3 |= 0x200;
	T8 = GTE_GetRegister(GTE_CREG_FLAG);
	T9 = GTE_GetRegister(GTE_DREG_SXY0);
	A0 = GTE_GetRegister(GTE_DREG_SXY1);
	T8 <<= 13;
	if ((int32_t)T8 < 0)
	{
		A1 = T9 & A0;
		ZZ_CLOCKCYCLES(69,0x80045440);
		goto ZZ_451EC_254;
	}
	A1 = T9 & A0;
	T9 = T9 - A3;
	A0 = A0 - A3;
	T8 = ~(T9 | A0);
	T8 |= A1;
	if ((int32_t)T8 < 0)
	{
		T8 <<= 16;
		ZZ_CLOCKCYCLES(75,0x80045440);
		goto ZZ_451EC_254;
	}
	T8 <<= 16;
	if ((int32_t)T8 < 0)
	{
		ZZ_CLOCKCYCLES(77,0x80045440);
		goto ZZ_451EC_254;
	}
	EMU_Write32(S7 + 12,T5); //+ 0xC
	EMU_Write32(S7 + 8,GTE_GetRegister(GTE_DREG_SXY0)); //+ 0x8
	EMU_Write32(S7 + 16,GTE_GetRegister(GTE_DREG_SXY1)); //+ 0x10
	EMU_Write32(S4 + 24,A2); //+ 0x18
	S7 = EMU_CheckedAdd(S7,20);
	ZZ_CLOCKCYCLES(82,0x80045440);
ZZ_451EC_254:
	if ((int32_t)SP >= 0)
	{
		SP = EMU_CheckedAdd(SP,-1);
		ZZ_CLOCKCYCLES(2,0x800452F8);
		goto ZZ_451EC_10C;
	}
	SP = EMU_CheckedAdd(SP,-1);
	T9 = 0x2000000;
	EMU_Write32(S7 + 4,S5); //+ 0x4
	EMU_Write32(S7 + 8,R0); //+ 0x8
	T8 = EMU_ReadU32(S4 + 24); //+ 0x18
	A1 = S7 << 8;
	T8 |= T9;
	EMU_Write32(S7,T8);
	A1 >>= 8;
	EMU_Write32(S4 + 24,A1); //+ 0x18
	S7 = EMU_CheckedAdd(S7,12);
	SP = EMU_ReadU32(V1);
	EMU_Write32(FP + 8,S7); //+ 0x8
	FP = EMU_ReadU32(SP + 60); //+ 0x3C
	GP = EMU_ReadU32(SP + 56); //+ 0x38
	T9 = EMU_ReadU32(SP + 52); //+ 0x34
	T8 = EMU_ReadU32(SP + 48); //+ 0x30
	S7 = EMU_ReadU32(SP + 44); //+ 0x2C
	S6 = EMU_ReadU32(SP + 40); //+ 0x28
	S5 = EMU_ReadU32(SP + 36); //+ 0x24
	S4 = EMU_ReadU32(SP + 32); //+ 0x20
	S3 = EMU_ReadU32(SP + 28); //+ 0x1C
	S2 = EMU_ReadU32(SP + 24); //+ 0x18
	S1 = EMU_ReadU32(SP + 20); //+ 0x14
	S0 = EMU_ReadU32(SP + 16); //+ 0x10
	ZZ_JUMPREGISTER_BEGIN(RA);
	SP += 64;
	ZZ_CLOCKCYCLES_JR(28);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x800451EC,0x800452F8,ZZ_451EC);
ZZ_MARK_TARGET(0x800452F8,0x80045440,ZZ_451EC_10C);
ZZ_MARK_TARGET(0x80045440,0x800454B0,ZZ_451EC_254);
