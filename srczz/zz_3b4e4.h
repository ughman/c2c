#ifdef ZZ_INCLUDE_CODE
ZZ_3B4E4:
	AT = 0x1F800000;
	EMU_Write32(AT,S0);
	EMU_Write32(AT + 4,S1); //+ 0x4
	EMU_Write32(AT + 8,S2); //+ 0x8
	EMU_Write32(AT + 12,S3); //+ 0xC
	EMU_Write32(AT + 16,S4); //+ 0x10
	EMU_Write32(AT + 20,S5); //+ 0x14
	EMU_Write32(AT + 24,S6); //+ 0x18
	EMU_Write32(AT + 28,S7); //+ 0x1C
	EMU_Write32(AT + 32,T8); //+ 0x20
	EMU_Write32(AT + 36,T9); //+ 0x24
	EMU_Write32(AT + 40,K0); //+ 0x28
	EMU_Write32(AT + 44,K1); //+ 0x2C
	EMU_Write32(AT + 48,GP); //+ 0x30
	EMU_Write32(AT + 52,SP); //+ 0x34
	EMU_Write32(AT + 56,FP); //+ 0x38
	EMU_Write32(AT + 60,RA); //+ 0x3C
	S6 = 0xFFFF;
	RA = 0x80040000;
	RA -= 18268;
	AT = EMU_ReadU16(A0);
	AT = EMU_CheckedAdd(AT,-1);
	AT <<= 1;
	AT += 4;
	T6 = EMU_CheckedAdd(A0,AT);
	AT = EMU_ReadU16(A0 + 6); //+ 0x6
	AT <<= 1;
	AT += 4;
	T7 = EMU_CheckedAdd(A0,AT);
	ZZ_CLOCKCYCLES(31,0x8003B560);
ZZ_3B4E4_7C:
	A3 = (int32_t)T6 < (int32_t)T7;
	if (A3)
	{
		ZZ_CLOCKCYCLES(3,0x8003B63C);
		goto ZZ_3B4E4_158;
	}
	AT = EMU_ReadU16(T6);
	T6 = EMU_CheckedAdd(T6,-2);
	if (AT == S6)
	{
		A3 = AT & 0x8000;
		ZZ_CLOCKCYCLES(7,0x8003B560);
		goto ZZ_3B4E4_7C;
	}
	A3 = AT & 0x8000;
	if (!A3)
	{
		S3 = AT & 0x7800;
		ZZ_CLOCKCYCLES(9,0x8003B590);
		goto ZZ_3B4E4_AC;
	}
	S3 = AT & 0x7800;
	S3 >>= 11;
	S4 = AT & 0x7FF;
	ZZ_CLOCKCYCLES(12,0x8003B60C);
	goto ZZ_3B4E4_128;
ZZ_3B4E4_AC:
	A3 = AT & 0x4000;
	if (!A3)
	{
		A3 = AT & 0x2000;
		ZZ_CLOCKCYCLES(3,0x8003B5D4);
		goto ZZ_3B4E4_F0;
	}
	A3 = AT & 0x2000;
	A3 = EMU_ReadU16(T6);
	T9 = A3 & 0xE000;
	if (T9)
	{
		S4 = A3 & 0x7FF;
		ZZ_CLOCKCYCLES(8,0x8003B5BC);
		goto ZZ_3B4E4_D8;
	}
	S4 = A3 & 0x7FF;
	A3 = EMU_ReadU16(T6 - 2); //+ 0xFFFFFFFE
	S4 = A3 & 0xFFF;
	ZZ_CLOCKCYCLES(11,0x8003B5BC);
ZZ_3B4E4_D8:
	S3 = AT & 0x1F;
	S3 += 16;
	A3 = AT & 0x3FE0;
	A3 >>= 5;
	S4 += A3;
	ZZ_CLOCKCYCLES(6,0x8003B60C);
	goto ZZ_3B4E4_128;
ZZ_3B4E4_F0:
	if (!A3)
	{
		S4 = AT & 0x7FF;
		ZZ_CLOCKCYCLES(2,0x8003B5FC);
		goto ZZ_3B4E4_118;
	}
	S4 = AT & 0x7FF;
	S4 <<= 1;
	A3 = A1 + 4;
	S4 += A3;
	A3 = EMU_ReadU16(S4);
	T9 = AT & 0x1800;
	A3 ^= T9;
	EMU_Write16(S4,A3);
	ZZ_CLOCKCYCLES(10,0x8003B560);
	goto ZZ_3B4E4_7C;
ZZ_3B4E4_118:
	S3 = AT & 0xFFF;
	AT = EMU_ReadU16(T6);
	T6 = EMU_CheckedAdd(T6,-2);
	S4 = AT & 0xFFF;
	ZZ_CLOCKCYCLES(4,0x8003B60C);
ZZ_3B4E4_128:
	S3 += 1;
	S3 += S4;
	S3 <<= 1;
	S4 <<= 1;
	AT = A1 + 4;
	S4 += AT;
	S3 += AT;
	AT = EMU_ReadU16(S4);
	A3 = EMU_ReadU16(S3);
	EMU_Write16(S3,AT);
	EMU_Write16(S4,A3);
	ZZ_CLOCKCYCLES(12,0x8003B560);
	goto ZZ_3B4E4_7C;
ZZ_3B4E4_158:
	V0 = R0;
	T5 = R0;
	T4 = R0;
	T7 = A0 + 8;
	AT = EMU_ReadU16(A0 + 4); //+ 0x4
	AT <<= 1;
	AT += 4;
	FP = EMU_CheckedAdd(A0,AT);
	S0 = FP;
	AT = EMU_ReadU16(A0 + 6); //+ 0x6
	AT <<= 1;
	AT += 4;
	SP = EMU_CheckedAdd(A0,AT);
	T6 = A1 + 4;
	GP = EMU_ReadU16(A1);
	S1 = A2 + 4;
	AT = EMU_ReadU16(S0);
	S0 += 2;
	T9 = (int32_t)S0 < (int32_t)SP;
	if (!T9)
	{
		T3 = R0;
		ZZ_CLOCKCYCLES(23,0x8003B6B4);
		goto ZZ_3B4E4_1D0;
	}
	T3 = R0;
	T8 = AT;
	if (T8 == S6)
	{
		T1 = T8 & 0xFFF;
		ZZ_CLOCKCYCLES(26,0x8003B6B4);
		goto ZZ_3B4E4_1D0;
	}
	T1 = T8 & 0xFFF;
	T3 = T8 & 0xF000;
	T3 >>= 12;
	T3 += 1;
	ZZ_CLOCKCYCLES(30,0x8003B6B8);
	goto ZZ_3B4E4_1D4;
ZZ_3B4E4_1D0:
	T1 = S6 << 8;
	ZZ_CLOCKCYCLES(1,0x8003B6B8);
ZZ_3B4E4_1D4:
	if ((int32_t)T3 <= 0)
	{
		ZZ_CLOCKCYCLES(2,0x8003B6C8);
		goto ZZ_3B4E4_1E4;
	}
	T8 = EMU_ReadU16(S0);
	S0 += 2;
	ZZ_CLOCKCYCLES(4,0x8003B6C8);
ZZ_3B4E4_1E4:
	AT = EMU_ReadU16(T7);
	T7 += 2;
	T9 = (int32_t)T7 < (int32_t)FP;
	if (!T9)
	{
		T2 = R0;
		ZZ_CLOCKCYCLES(5,0x8003B6F8);
		goto ZZ_3B4E4_214;
	}
	T2 = R0;
	S7 = AT;
	if (S7 == S6)
	{
		T0 = S7 & 0xFFF;
		ZZ_CLOCKCYCLES(8,0x8003B6F8);
		goto ZZ_3B4E4_214;
	}
	T0 = S7 & 0xFFF;
	T2 = S7 & 0xF000;
	T2 >>= 12;
	T2 += 1;
	ZZ_CLOCKCYCLES(12,0x8003B6FC);
	goto ZZ_3B4E4_218;
ZZ_3B4E4_214:
	T0 = S6 << 8;
	ZZ_CLOCKCYCLES(1,0x8003B6FC);
ZZ_3B4E4_218:
	if ((int32_t)T2 <= 0)
	{
		ZZ_CLOCKCYCLES(2,0x8003B70C);
		goto ZZ_3B4E4_228;
	}
	S7 = EMU_ReadU16(T7);
	T7 += 2;
	ZZ_CLOCKCYCLES(4,0x8003B70C);
ZZ_3B4E4_228:
	V1 = R0;
	ZZ_CLOCKCYCLES(1,0x8003B710);
ZZ_3B4E4_22C:
	AT = (int32_t)V1 < (int32_t)GP;
	A3 = (int32_t)R0 < (int32_t)T3;
	AT &= A3;
	if (!AT)
	{
		AT = EMU_CheckedAdd(T1,T5);
		ZZ_CLOCKCYCLES(5,0x8003B7A4);
		goto ZZ_3B4E4_2C0;
	}
	AT = EMU_CheckedAdd(T1,T5);
	AT = EMU_CheckedSubtract(AT,V1);
	if (AT)
	{
		ZZ_CLOCKCYCLES(8,0x8003B7A4);
		goto ZZ_3B4E4_2C0;
	}
	T3 = EMU_CheckedAdd(T3,-1);
	T5 += 1;
	V1 += 1;
	T6 += 2;
	if ((int32_t)T3 <= 0)
	{
		ZZ_CLOCKCYCLES(14,0x8003B758);
		goto ZZ_3B4E4_274;
	}
	T8 = EMU_ReadU16(S0);
	S0 += 2;
	ZZ_CLOCKCYCLES(18,0x8003B8A4);
	goto ZZ_3B4E4_3C0;
ZZ_3B4E4_274:
	AT = EMU_ReadU16(S0);
	S0 += 2;
	T9 = (int32_t)S0 < (int32_t)SP;
	if (!T9)
	{
		T3 = R0;
		ZZ_CLOCKCYCLES(5,0x8003B788);
		goto ZZ_3B4E4_2A4;
	}
	T3 = R0;
	T8 = AT;
	if (T8 == S6)
	{
		T1 = T8 & 0xFFF;
		ZZ_CLOCKCYCLES(8,0x8003B788);
		goto ZZ_3B4E4_2A4;
	}
	T1 = T8 & 0xFFF;
	T3 = T8 & 0xF000;
	T3 >>= 12;
	T3 += 1;
	ZZ_CLOCKCYCLES(12,0x8003B78C);
	goto ZZ_3B4E4_2A8;
ZZ_3B4E4_2A4:
	T1 = S6 << 8;
	ZZ_CLOCKCYCLES(1,0x8003B78C);
ZZ_3B4E4_2A8:
	if ((int32_t)T3 <= 0)
	{
		ZZ_CLOCKCYCLES(2,0x8003B8A4);
		goto ZZ_3B4E4_3C0;
	}
	T8 = EMU_ReadU16(S0);
	S0 += 2;
	ZZ_CLOCKCYCLES(6,0x8003B8A4);
	goto ZZ_3B4E4_3C0;
ZZ_3B4E4_2C0:
	if ((int32_t)T2 <= 0)
	{
		AT = EMU_CheckedAdd(T0,T5);
		ZZ_CLOCKCYCLES(2,0x8003B838);
		goto ZZ_3B4E4_354;
	}
	AT = EMU_CheckedAdd(T0,T5);
	AT = EMU_CheckedSubtract(AT,T4);
	AT -= 1;
	AT = EMU_CheckedSubtract(AT,V1);
	if (AT)
	{
		AT = S7 & 0xFFFF;
		ZZ_CLOCKCYCLES(7,0x8003B838);
		goto ZZ_3B4E4_354;
	}
	AT = S7 & 0xFFFF;
	EMU_Write16(S1,AT);
	S1 += 2;
	V0 += 1;
	T2 = EMU_CheckedAdd(T2,-1);
	T4 += 1;
	if ((int32_t)T2 <= 0)
	{
		ZZ_CLOCKCYCLES(14,0x8003B7EC);
		goto ZZ_3B4E4_308;
	}
	S7 = EMU_ReadU16(T7);
	T7 += 2;
	ZZ_CLOCKCYCLES(18,0x8003B8A4);
	goto ZZ_3B4E4_3C0;
ZZ_3B4E4_308:
	AT = EMU_ReadU16(T7);
	T7 += 2;
	T9 = (int32_t)T7 < (int32_t)FP;
	if (!T9)
	{
		T2 = R0;
		ZZ_CLOCKCYCLES(5,0x8003B81C);
		goto ZZ_3B4E4_338;
	}
	T2 = R0;
	S7 = AT;
	if (S7 == S6)
	{
		T0 = S7 & 0xFFF;
		ZZ_CLOCKCYCLES(8,0x8003B81C);
		goto ZZ_3B4E4_338;
	}
	T0 = S7 & 0xFFF;
	T2 = S7 & 0xF000;
	T2 >>= 12;
	T2 += 1;
	ZZ_CLOCKCYCLES(12,0x8003B820);
	goto ZZ_3B4E4_33C;
ZZ_3B4E4_338:
	T0 = S6 << 8;
	ZZ_CLOCKCYCLES(1,0x8003B820);
ZZ_3B4E4_33C:
	if ((int32_t)T2 <= 0)
	{
		ZZ_CLOCKCYCLES(2,0x8003B8A4);
		goto ZZ_3B4E4_3C0;
	}
	S7 = EMU_ReadU16(T7);
	T7 += 2;
	ZZ_CLOCKCYCLES(6,0x8003B8A4);
	goto ZZ_3B4E4_3C0;
ZZ_3B4E4_354:
	AT = (int32_t)V1 < (int32_t)GP;
	if (!AT)
	{
		AT = EMU_CheckedAdd(T1,T5);
		ZZ_CLOCKCYCLES(3,0x8003B8A4);
		goto ZZ_3B4E4_3C0;
	}
	AT = EMU_CheckedAdd(T1,T5);
	AT = EMU_CheckedSubtract(AT,V1);
	A3 = EMU_CheckedAdd(T0,T5);
	A3 = EMU_CheckedSubtract(A3,T4);
	A3 = EMU_CheckedAdd(A3,-1);
	A3 = EMU_CheckedSubtract(A3,V1);
	T9 = (int32_t)AT < (int32_t)A3;
	if (T9)
	{
		ZZ_CLOCKCYCLES(11,0x8003B868);
		goto ZZ_3B4E4_384;
	}
	AT = A3;
	ZZ_CLOCKCYCLES(12,0x8003B868);
ZZ_3B4E4_384:
	A3 = EMU_CheckedSubtract(GP,V1);
	A3 = EMU_CheckedAdd(A3,-1);
	T9 = (int32_t)AT < (int32_t)A3;
	if (T9)
	{
		ZZ_CLOCKCYCLES(5,0x8003B880);
		goto ZZ_3B4E4_39C;
	}
	AT = A3;
	ZZ_CLOCKCYCLES(6,0x8003B880);
ZZ_3B4E4_39C:
	A3 = (int32_t)AT < 2;
	if (!A3)
	{
		ZZ_CLOCKCYCLES(3,0x8003B910);
		goto ZZ_3B4E4_42C;
	}
	AT = EMU_ReadU16(T6);
	T6 += 2;
	EMU_Write16(S1,AT);
	S1 += 2;
	V0 += 1;
	V1 += 1;
	ZZ_CLOCKCYCLES(9,0x8003B8A4);
ZZ_3B4E4_3C0:
	AT = (int32_t)V1 < (int32_t)GP;
	A3 = (int32_t)R0 < (int32_t)T2;
	AT |= A3;
	A3 = (int32_t)R0 < (int32_t)T3;
	AT |= A3;
	if (AT)
	{
		ZZ_CLOCKCYCLES(7,0x8003B710);
		goto ZZ_3B4E4_22C;
	}
	EMU_Write16(A2,V0);
	AT = 0x1F800000;
	S0 = EMU_ReadU32(AT);
	S1 = EMU_ReadU32(AT + 4); //+ 0x4
	S2 = EMU_ReadU32(AT + 8); //+ 0x8
	S3 = EMU_ReadU32(AT + 12); //+ 0xC
	S4 = EMU_ReadU32(AT + 16); //+ 0x10
	S5 = EMU_ReadU32(AT + 20); //+ 0x14
	S6 = EMU_ReadU32(AT + 24); //+ 0x18
	S7 = EMU_ReadU32(AT + 28); //+ 0x1C
	T8 = EMU_ReadU32(AT + 32); //+ 0x20
	T9 = EMU_ReadU32(AT + 36); //+ 0x24
	K0 = EMU_ReadU32(AT + 40); //+ 0x28
	K1 = EMU_ReadU32(AT + 44); //+ 0x2C
	GP = EMU_ReadU32(AT + 48); //+ 0x30
	SP = EMU_ReadU32(AT + 52); //+ 0x34
	RA = EMU_ReadU32(AT + 60); //+ 0x3C
	FP = EMU_ReadU32(AT + 56); //+ 0x38
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(27);
	ZZ_JUMPREGISTER(0x80029ADC,ZZ_29A74_68);
	ZZ_JUMPREGISTER_END();
ZZ_3B4E4_42C:
	V0 = EMU_CheckedAdd(V0,AT);
	V1 = EMU_CheckedAdd(V1,AT);
	S2 = (int32_t)AT < 5;
	if (S2)
	{
		S2 = T6 & 0x3;
		ZZ_CLOCKCYCLES(5,0x8003BAF0);
		goto ZZ_3B4E4_60C;
	}
	S2 = T6 & 0x3;
	if (!S2)
	{
		S3 = S1 & 0x3;
		ZZ_CLOCKCYCLES(7,0x8003B954);
		goto ZZ_3B4E4_470;
	}
	S3 = S1 & 0x3;
	if (!S3)
	{
		ZZ_CLOCKCYCLES(9,0x8003BA58);
		goto ZZ_3B4E4_574;
	}
	S2 = EMU_ReadU16(T6);
	T6 += 2;
	EMU_Write16(S1,S2);
	S1 += 2;
	AT -= 1;
	ZZ_CLOCKCYCLES(15,0x8003B95C);
	goto ZZ_3B4E4_478;
ZZ_3B4E4_470:
	if (S3)
	{
		ZZ_CLOCKCYCLES(2,0x8003B9BC);
		goto ZZ_3B4E4_4D8;
	}
	ZZ_CLOCKCYCLES(2,0x8003B95C);
ZZ_3B4E4_478:
	S2 = AT < 4;
	if (S2)
	{
		S2 = AT < 5;
		ZZ_CLOCKCYCLES(3,0x8003BAF0);
		goto ZZ_3B4E4_60C;
	}
	S2 = AT < 5;
	if (!S2)
	{
		S5 = AT & 0x3;
		ZZ_CLOCKCYCLES(5,0x8003B98C);
		goto ZZ_3B4E4_4A8;
	}
	S5 = AT & 0x3;
	AT = AT - S5;
	S4 = 0x80040000;
	S4 -= 18012;
	S2 = AT << 2;
	S4 = S4 - S2;
	ZZ_JUMPREGISTER_BEGIN(S4);
	ZZ_CLOCKCYCLES_JR(12);
	ZZ_JUMPREGISTER(0x8003B9A4,ZZ_3B4E4_4C0);
	ZZ_JUMPREGISTER(0x8003B994,ZZ_3B4E4_4B0);
	ZZ_JUMPREGISTER_END();
ZZ_3B4E4_4A8:
	S5 = AT - 4;
	AT = 4;
	ZZ_CLOCKCYCLES(2,0x8003B994);
ZZ_3B4E4_4B0:
	S3 = EMU_ReadU32(T6 + 4); //+ 0x4
	S2 = EMU_ReadU32(T6);
	EMU_Write32(S1 + 4,S3); //+ 0x4
	EMU_Write32(S1,S2);
	ZZ_CLOCKCYCLES(4,0x8003B9A4);
ZZ_3B4E4_4C0:
	T6 += AT;
	T6 += AT;
	S1 += AT;
	S1 += AT;
	AT = S5;
	ZZ_CLOCKCYCLES(6,0x8003B95C);
	goto ZZ_3B4E4_478;
ZZ_3B4E4_4D8:
	S2 = AT < 4;
	if (S2)
	{
		S2 = AT < 5;
		ZZ_CLOCKCYCLES(3,0x8003BAF0);
		goto ZZ_3B4E4_60C;
	}
	S2 = AT < 5;
	if (!S2)
	{
		S5 = AT & 0x3;
		ZZ_CLOCKCYCLES(5,0x8003BA00);
		goto ZZ_3B4E4_51C;
	}
	S5 = AT & 0x3;
	AT = AT - S5;
	S4 = 0x80040000;
	S4 -= 17860;
	S3 = AT << 2;
	S3 += AT;
	S3 <<= 1;
	S4 = S4 - S3;
	A3 = AT + AT;
	A3 += S1;
	S2 = EMU_ReadU16(A3);
	ZZ_JUMPREGISTER_BEGIN(S4);
	ZZ_CLOCKCYCLES_JR(17);
	ZZ_JUMPREGISTER(0x8003BA3C,ZZ_3B4E4_558);
	ZZ_JUMPREGISTER(0x8003BA14,ZZ_3B4E4_530);
	ZZ_JUMPREGISTER_END();
ZZ_3B4E4_51C:
	S5 = AT - 4;
	AT = 4;
	A3 = AT + AT;
	A3 += S1;
	S2 = EMU_ReadU16(A3);
	ZZ_CLOCKCYCLES(5,0x8003BA14);
ZZ_3B4E4_530:
	T9 = EMU_ReadU32(T6 + 4); //+ 0x4
	S3 = S2 << 16;
	A3 = T9 >> 16;
	S3 |= A3;
	EMU_Write32(S1 + 6,S3); //+ 0x6
	S2 = EMU_ReadU32(T6);
	S3 = T9 << 16;
	A3 = S2 >> 16;
	S3 |= A3;
	EMU_Write32(S1 + 2,S3); //+ 0x2
	ZZ_CLOCKCYCLES(10,0x8003BA3C);
ZZ_3B4E4_558:
	EMU_Write16(S1,S2);
	T6 += AT;
	T6 += AT;
	S1 += AT;
	S1 += AT;
	AT = S5;
	ZZ_CLOCKCYCLES(7,0x8003B9BC);
	goto ZZ_3B4E4_4D8;
ZZ_3B4E4_574:
	S2 = AT < 4;
	if (S2)
	{
		S2 = AT < 5;
		ZZ_CLOCKCYCLES(3,0x8003BAF0);
		goto ZZ_3B4E4_60C;
	}
	S2 = AT < 5;
	if (!S2)
	{
		S5 = AT & 0x3;
		ZZ_CLOCKCYCLES(5,0x8003BA9C);
		goto ZZ_3B4E4_5B8;
	}
	S5 = AT & 0x3;
	AT = AT - S5;
	S4 = 0x80040000;
	S4 -= 17704;
	S3 = AT << 2;
	S3 += AT;
	S3 <<= 1;
	S4 = S4 - S3;
	A3 = AT + AT;
	A3 += T6;
	S2 = EMU_ReadU16(A3 - 2); //+ 0xFFFFFFFE
	ZZ_JUMPREGISTER_BEGIN(S4);
	ZZ_CLOCKCYCLES_JR(17);
	ZZ_JUMPREGISTER(0x8003BAD8,ZZ_3B4E4_5F4);
	ZZ_JUMPREGISTER(0x8003BAB0,ZZ_3B4E4_5CC);
	ZZ_JUMPREGISTER_END();
ZZ_3B4E4_5B8:
	S5 = AT - 4;
	AT = 4;
	A3 = AT + AT;
	A3 += T6;
	S2 = EMU_ReadU16(A3 - 2); //+ 0xFFFFFFFE
	ZZ_CLOCKCYCLES(5,0x8003BAB0);
ZZ_3B4E4_5CC:
	T9 = EMU_ReadU32(T6 + 2); //+ 0x2
	S3 = S2 << 16;
	A3 = T9 >> 16;
	S3 |= A3;
	EMU_Write32(S1 + 4,S3); //+ 0x4
	S2 = EMU_ReadU32(T6 - 2); //+ 0xFFFFFFFE
	S3 = T9 << 16;
	A3 = S2 >> 16;
	S3 |= A3;
	EMU_Write32(S1,S3);
	ZZ_CLOCKCYCLES(10,0x8003BAD8);
ZZ_3B4E4_5F4:
	T6 += AT;
	T6 += AT;
	S1 += AT;
	S1 += AT;
	AT = S5;
	ZZ_CLOCKCYCLES(6,0x8003BA58);
	goto ZZ_3B4E4_574;
ZZ_3B4E4_60C:
	S2 = EMU_ReadU16(T6);
	S4 = 0x80040000;
	S4 -= 17644;
	S3 = AT << 5;
	S4 += S3;
	S3 = AT << 1;
	T6 += S3;
	ZZ_JUMPREGISTER_BEGIN(S4);
	S1 += S3;
	ZZ_CLOCKCYCLES_JR(9);
	ZZ_JUMPREGISTER(0x8003BB14,ZZ_3B4E4_630);
	ZZ_JUMPREGISTER(0x8003BB34,ZZ_3B4E4_650);
	ZZ_JUMPREGISTER(0x8003BB54,ZZ_3B4E4_670);
	ZZ_JUMPREGISTER(0x8003BB74,ZZ_3B4E4_690);
	ZZ_JUMPREGISTER(0x8003BB94,ZZ_3B4E4_6B0);
	ZZ_JUMPREGISTER(0x8003BBB4,ZZ_3B4E4_6D0);
	ZZ_JUMPREGISTER_END();
ZZ_3B4E4_630:
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(2);
	ZZ_JUMPREGISTER(0x80029ADC,ZZ_29A74_68);
	ZZ_JUMPREGISTER_END();
ZZ_3B4E4_650:
	ZZ_JUMPREGISTER_BEGIN(RA);
	EMU_Write16(S1 - 2,S2); //+ 0xFFFFFFFE
	ZZ_CLOCKCYCLES_JR(2);
	ZZ_JUMPREGISTER(0x80029ADC,ZZ_29A74_68);
	ZZ_JUMPREGISTER_END();
ZZ_3B4E4_670:
	S3 = EMU_ReadU16(T6 - 2); //+ 0xFFFFFFFE
	EMU_Write16(S1 - 4,S2); //+ 0xFFFFFFFC
	ZZ_JUMPREGISTER_BEGIN(RA);
	EMU_Write16(S1 - 2,S3); //+ 0xFFFFFFFE
	ZZ_CLOCKCYCLES_JR(4);
	ZZ_JUMPREGISTER(0x80029ADC,ZZ_29A74_68);
	ZZ_JUMPREGISTER_END();
ZZ_3B4E4_690:
	S3 = EMU_ReadU16(T6 - 4); //+ 0xFFFFFFFC
	EMU_Write16(S1 - 6,S2); //+ 0xFFFFFFFA
	S2 = EMU_ReadU16(T6 - 2); //+ 0xFFFFFFFE
	EMU_Write16(S1 - 4,S3); //+ 0xFFFFFFFC
	ZZ_JUMPREGISTER_BEGIN(RA);
	EMU_Write16(S1 - 2,S2); //+ 0xFFFFFFFE
	ZZ_CLOCKCYCLES_JR(6);
	ZZ_JUMPREGISTER(0x80029ADC,ZZ_29A74_68);
	ZZ_JUMPREGISTER_END();
ZZ_3B4E4_6B0:
	S3 = EMU_ReadU16(T6 - 6); //+ 0xFFFFFFFA
	EMU_Write16(S1 - 8,S2); //+ 0xFFFFFFF8
	S2 = EMU_ReadU16(T6 - 4); //+ 0xFFFFFFFC
	EMU_Write16(S1 - 6,S3); //+ 0xFFFFFFFA
	S3 = EMU_ReadU16(T6 - 2); //+ 0xFFFFFFFE
	EMU_Write16(S1 - 4,S2); //+ 0xFFFFFFFC
	ZZ_JUMPREGISTER_BEGIN(RA);
	EMU_Write16(S1 - 2,S3); //+ 0xFFFFFFFE
	ZZ_CLOCKCYCLES_JR(8);
	ZZ_JUMPREGISTER(0x80029ADC,ZZ_29A74_68);
	ZZ_JUMPREGISTER_END();
ZZ_3B4E4_6D0:
	AT = EMU_CheckedAdd(AT,-1);
	ZZ_CLOCKCYCLES(1,0x8003BBB8);
ZZ_3B4E4_6D4:
	A3 = EMU_ReadU16(T6);
	T6 += 2;
	EMU_Write16(S1,A3);
	S1 += 2;
	if (AT)
	{
		AT = EMU_CheckedAdd(AT,-1);
		ZZ_CLOCKCYCLES(6,0x8003BBB8);
		goto ZZ_3B4E4_6D4;
	}
	AT = EMU_CheckedAdd(AT,-1);
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(8);
	ZZ_JUMPREGISTER(0x80029ADC,ZZ_29A74_68);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x8003B4E4,0x8003B560,ZZ_3B4E4);
ZZ_MARK_TARGET(0x8003B560,0x8003B590,ZZ_3B4E4_7C);
ZZ_MARK_TARGET(0x8003B590,0x8003B5BC,ZZ_3B4E4_AC);
ZZ_MARK_TARGET(0x8003B5BC,0x8003B5D4,ZZ_3B4E4_D8);
ZZ_MARK_TARGET(0x8003B5D4,0x8003B5FC,ZZ_3B4E4_F0);
ZZ_MARK_TARGET(0x8003B5FC,0x8003B60C,ZZ_3B4E4_118);
ZZ_MARK_TARGET(0x8003B60C,0x8003B63C,ZZ_3B4E4_128);
ZZ_MARK_TARGET(0x8003B63C,0x8003B6B4,ZZ_3B4E4_158);
ZZ_MARK_TARGET(0x8003B6B4,0x8003B6B8,ZZ_3B4E4_1D0);
ZZ_MARK_TARGET(0x8003B6B8,0x8003B6C8,ZZ_3B4E4_1D4);
ZZ_MARK_TARGET(0x8003B6C8,0x8003B6F8,ZZ_3B4E4_1E4);
ZZ_MARK_TARGET(0x8003B6F8,0x8003B6FC,ZZ_3B4E4_214);
ZZ_MARK_TARGET(0x8003B6FC,0x8003B70C,ZZ_3B4E4_218);
ZZ_MARK_TARGET(0x8003B70C,0x8003B710,ZZ_3B4E4_228);
ZZ_MARK_TARGET(0x8003B710,0x8003B758,ZZ_3B4E4_22C);
ZZ_MARK_TARGET(0x8003B758,0x8003B788,ZZ_3B4E4_274);
ZZ_MARK_TARGET(0x8003B788,0x8003B78C,ZZ_3B4E4_2A4);
ZZ_MARK_TARGET(0x8003B78C,0x8003B7A4,ZZ_3B4E4_2A8);
ZZ_MARK_TARGET(0x8003B7A4,0x8003B7EC,ZZ_3B4E4_2C0);
ZZ_MARK_TARGET(0x8003B7EC,0x8003B81C,ZZ_3B4E4_308);
ZZ_MARK_TARGET(0x8003B81C,0x8003B820,ZZ_3B4E4_338);
ZZ_MARK_TARGET(0x8003B820,0x8003B838,ZZ_3B4E4_33C);
ZZ_MARK_TARGET(0x8003B838,0x8003B868,ZZ_3B4E4_354);
ZZ_MARK_TARGET(0x8003B868,0x8003B880,ZZ_3B4E4_384);
ZZ_MARK_TARGET(0x8003B880,0x8003B8A4,ZZ_3B4E4_39C);
ZZ_MARK_TARGET(0x8003B8A4,0x8003B910,ZZ_3B4E4_3C0);
ZZ_MARK_TARGET(0x8003B910,0x8003B94C,ZZ_3B4E4_42C);
ZZ_MARK_TARGET(0x8003B954,0x8003B95C,ZZ_3B4E4_470);
ZZ_MARK_TARGET(0x8003B95C,0x8003B98C,ZZ_3B4E4_478);
ZZ_MARK_TARGET(0x8003B98C,0x8003B994,ZZ_3B4E4_4A8);
ZZ_MARK_TARGET(0x8003B994,0x8003B9A4,ZZ_3B4E4_4B0);
ZZ_MARK_TARGET(0x8003B9A4,0x8003B9BC,ZZ_3B4E4_4C0);
ZZ_MARK_TARGET(0x8003B9BC,0x8003BA00,ZZ_3B4E4_4D8);
ZZ_MARK_TARGET(0x8003BA00,0x8003BA14,ZZ_3B4E4_51C);
ZZ_MARK_TARGET(0x8003BA14,0x8003BA3C,ZZ_3B4E4_530);
ZZ_MARK_TARGET(0x8003BA3C,0x8003BA58,ZZ_3B4E4_558);
ZZ_MARK_TARGET(0x8003BA58,0x8003BA9C,ZZ_3B4E4_574);
ZZ_MARK_TARGET(0x8003BA9C,0x8003BAB0,ZZ_3B4E4_5B8);
ZZ_MARK_TARGET(0x8003BAB0,0x8003BAD8,ZZ_3B4E4_5CC);
ZZ_MARK_TARGET(0x8003BAD8,0x8003BAF0,ZZ_3B4E4_5F4);
ZZ_MARK_TARGET(0x8003BAF0,0x8003BB14,ZZ_3B4E4_60C);
ZZ_MARK_TARGET(0x8003BB14,0x8003BB1C,ZZ_3B4E4_630);
ZZ_MARK_TARGET(0x8003BB34,0x8003BB3C,ZZ_3B4E4_650);
ZZ_MARK_TARGET(0x8003BB54,0x8003BB64,ZZ_3B4E4_670);
ZZ_MARK_TARGET(0x8003BB74,0x8003BB8C,ZZ_3B4E4_690);
ZZ_MARK_TARGET(0x8003BB94,0x8003BBB4,ZZ_3B4E4_6B0);
ZZ_MARK_TARGET(0x8003BBB4,0x8003BBB8,ZZ_3B4E4_6D0);
ZZ_MARK_TARGET(0x8003BBB8,0x8003BBD8,ZZ_3B4E4_6D4);
