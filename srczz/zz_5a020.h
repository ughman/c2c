#ifdef ZZ_INCLUDE_CODE
ZZ_5A020:
	SP -= 48;
	EMU_Write32(SP + 28,S3); //+ 0x1C
	S3 = A3;
	EMU_Write32(SP + 32,S4); //+ 0x20
	S4 = R0;
	EMU_Write32(SP + 36,S5); //+ 0x24
	S5 = A0;
	EMU_Write32(SP + 40,S6); //+ 0x28
	S6 = A1;
	V1 = A0 & 0xFF;
	V1 <<= 2;
	A0 &= 0xFF00;
	A0 = (int32_t)A0 >> 8;
	V0 = A0 << 1;
	V0 += A0;
	V0 <<= 2;
	V0 = V0 - A0;
	V0 <<= 4;
	A1 <<= 16;
	A2 <<= 16;
	EMU_Write32(SP + 16,S0); //+ 0x10
	S0 = (int32_t)A2 >> 16;
	A0 = (int32_t)A1 >> 16;
	A1 = S0;
	EMU_Write32(SP + 44,RA); //+ 0x2C
	EMU_Write32(SP + 24,S2); //+ 0x18
	EMU_Write32(SP + 20,S1); //+ 0x14
	AT = 0x80070000;
	AT += V1;
	V1 = EMU_ReadU32(AT - 15268); //+ 0xFFFFC45C
	S2 = EMU_ReadU16(SP + 64); //+ 0x40
	RA = 0x8005A0A4; //ZZ_5A020_84
	S1 = V1 + V0;
	ZZ_CLOCKCYCLES(33,0x8005A59C);
	goto ZZ_5A59C;
ZZ_5A020_84:
	AT = 0x80070000;
	EMU_Write16(AT - 26606,S5); //+ 0xFFFF9812
	if (S2)
	{
		V0 = S3 & 0xFFFF;
		ZZ_CLOCKCYCLES(4,0x8005A0B8);
		goto ZZ_5A020_98;
	}
	V0 = S3 & 0xFFFF;
	S2 = 1;
	ZZ_CLOCKCYCLES(5,0x8005A0B8);
ZZ_5A020_98:
	if (V0)
	{
		ZZ_CLOCKCYCLES(2,0x8005A0C4);
		goto ZZ_5A020_A4;
	}
	S3 = 1;
	ZZ_CLOCKCYCLES(3,0x8005A0C4);
ZZ_5A020_A4:
	V0 = 0x80070000;
	V0 = EMU_ReadU8(V0 - 32136); //+ 0xFFFF8278
	V0 = (int32_t)S4 < (int32_t)V0;
	if (!V0)
	{
		T1 = R0;
		ZZ_CLOCKCYCLES(6,0x8005A56C);
		goto ZZ_5A020_54C;
	}
	T1 = R0;
	T5 = S0;
	S0 = T5 << 4;
	T4 = 0x2040000;
	T4 |= 0x811;
	T2 = 0x4100000;
	T2 |= 0x4105;
	T6 = 127;
	T3 = 0x40000;
	T3 |= 0x11;
	T7 = 0x80070000;
	T7 -= 26580;
	T8 = T7 + 2;
	V1 = T1 << 16;
	ZZ_CLOCKCYCLES(19,0x8005A110);
ZZ_5A020_F0:
	V1 = (int32_t)V1 >> 16;
	V0 = V1 << 3;
	V0 = V0 - V1;
	V0 <<= 2;
	V0 = V0 - V1;
	A0 = V0 << 1;
	AT = 0x80060000;
	AT += A0;
	V1 = EMU_ReadS16(AT + 1204); //+ 0x4B4
	V0 = S5 << 16;
	V0 = (int32_t)V0 >> 16;
	if (V1 != V0)
	{
		V0 = T1 + 1;
		ZZ_CLOCKCYCLES(13,0x8005A54C);
		goto ZZ_5A020_52C;
	}
	V0 = T1 + 1;
	AT = 0x80060000;
	AT += A0;
	V0 = EMU_ReadS16(AT + 1208); //+ 0x4B8
	if (V0 != T5)
	{
		V0 = T1 + 1;
		ZZ_CLOCKCYCLES(19,0x8005A54C);
		goto ZZ_5A020_52C;
	}
	V0 = T1 + 1;
	AT = 0x80060000;
	AT += A0;
	V1 = EMU_ReadS16(AT + 1212); //+ 0x4BC
	V0 = S6 << 16;
	V0 = (int32_t)V0 >> 16;
	if (V1 != V0)
	{
		V0 = T1 + 1;
		ZZ_CLOCKCYCLES(26,0x8005A54C);
		goto ZZ_5A020_52C;
	}
	V0 = T1 + 1;
	V0 = EMU_ReadU8(S1 + 23); //+ 0x17
	V0 <<= 1;
	A0 = V0 + S1;
	V1 = EMU_ReadS16(A0 + 96); //+ 0x60
	V0 = S3 & 0xFFFF;
	if (V1 == V0)
	{
		ZZ_CLOCKCYCLES(34,0x8005A1A8);
		goto ZZ_5A020_188;
	}
	if (V1)
	{
		V0 = T1 << 16;
		ZZ_CLOCKCYCLES(36,0x8005A1AC);
		goto ZZ_5A020_18C;
	}
	V0 = T1 << 16;
	V0 = 1;
	EMU_Write16(A0 + 96,V0); //+ 0x60
	ZZ_CLOCKCYCLES(38,0x8005A1A8);
ZZ_5A020_188:
	V0 = T1 << 16;
	ZZ_CLOCKCYCLES(1,0x8005A1AC);
ZZ_5A020_18C:
	V0 = (int32_t)V0 >> 16;
	A3 = V0 << 3;
	A3 = A3 - V0;
	A3 <<= 2;
	A3 = A3 - V0;
	A3 <<= 1;
	AT = 0x80060000;
	AT += A3;
	V1 = EMU_ReadS16(AT + 1196); //+ 0x4AC
	V0 = S3 & 0xFFFF;
	EMU_SMultiply(V1,V0);
	V1 = LO;
	V0 = 0x81020000;
	V0 |= 0x409;
	EMU_SMultiply(V1,V0);
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32144); //+ 0xFFFF8270
	A1 = EMU_ReadU8(V0 + 24); //+ 0x18
	V0 = A1 << 14;
	V0 = V0 - A1;
	T0 = HI;
	A0 = T0 + V1;
	A0 = (int32_t)A0 >> 6;
	V1 = (int32_t)V1 >> 31;
	A0 = A0 - V1;
	EMU_SMultiply(A0,V0);
	A0 = LO;
	V0 = 0x82060000;
	V0 |= 0x1029;
	EMU_SMultiply(A0,V0);
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32152); //+ 0xFFFF8268
	V0 += S0;
	V0 = EMU_ReadU8(V0 + 1); //+ 0x1
	V1 = HI;
	V1 += A0;
	V1 = (int32_t)V1 >> 13;
	A0 = (int32_t)A0 >> 31;
	T0 = V1 - A0;
	EMU_SMultiply(T0,V0);
	AT = 0x80060000;
	AT += A3;
	A2 = EMU_ReadS16(AT + 1206); //+ 0x4B6
	AT = 0x80060000;
	AT += A3;
	V0 = EMU_ReadS16(AT + 1210); //+ 0x4BA
	A2 <<= 4;
	A2 += V0;
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32140); //+ 0xFFFF8274
	A2 <<= 5;
	A2 += V0;
	V1 = LO;
	V0 = EMU_ReadU8(A2 + 2); //+ 0x2
	EMU_SMultiply(V1,V0);
	V0 = LO;
	V1 = 0x40C0000;
	V1 |= 0x2051;
	EMU_UMultiply(V0,V1);
	V1 = HI;
	V0 = V0 - V1;
	V0 >>= 1;
	V1 += V0;
	V0 = EMU_ReadU16(S1 + 88); //+ 0x58
	A0 = V1 >> 13;
	EMU_SMultiply(A0,V0);
	V0 = LO;
	V1 = EMU_ReadU16(S1 + 90); //+ 0x5A
	EMU_SMultiply(A0,V1);
	V1 = LO;
	EMU_UMultiply(V0,T4);
	A0 = HI;
	EMU_UMultiply(V1,T4);
	V0 = V0 - A0;
	V0 >>= 1;
	A0 += V0;
	T0 = A0 >> 6;
	A1 = HI;
	V1 = V1 - A1;
	V1 >>= 1;
	A1 += V1;
	V1 = EMU_ReadU8(A2 + 3); //+ 0x3
	V0 = V1 < 64;
	if (!V0)
	{
		A0 = A1 >> 6;
		ZZ_CLOCKCYCLES(95,0x8005A358);
		goto ZZ_5A020_338;
	}
	A0 = A1 >> 6;
	EMU_SMultiply(A0,V1);
	V0 = LO;
	EMU_UMultiply(V0,T2);
	A2 = T0;
	V1 = HI;
	V0 = V0 - V1;
	V0 >>= 1;
	V1 += V0;
	A1 = V1 >> 5;
	ZZ_CLOCKCYCLES(107,0x8005A388);
	goto ZZ_5A020_368;
ZZ_5A020_338:
	V0 = T6 - V1;
	EMU_SMultiply(T0,V0);
	V0 = LO;
	EMU_UMultiply(V0,T2);
	A1 = A0;
	V1 = HI;
	V0 = V0 - V1;
	V0 >>= 1;
	V1 += V0;
	A2 = V1 >> 5;
	ZZ_CLOCKCYCLES(12,0x8005A388);
ZZ_5A020_368:
	V1 = T1 << 16;
	V1 = (int32_t)V1 >> 16;
	V0 = V1 << 3;
	V0 = V0 - V1;
	V0 <<= 2;
	V0 = V0 - V1;
	V0 <<= 1;
	AT = 0x80060000;
	AT += V0;
	V0 = EMU_ReadS16(AT + 1208); //+ 0x4B8
	V1 = 0x80070000;
	V1 = EMU_ReadU32(V1 - 32152); //+ 0xFFFF8268
	V0 <<= 4;
	V0 += V1;
	V1 = EMU_ReadU8(V0 + 4); //+ 0x4
	V0 = V1 < 64;
	if (!V0)
	{
		EMU_SMultiply(A1,V1);
		ZZ_CLOCKCYCLES(19,0x8005A3FC);
		goto ZZ_5A020_3DC;
	}
	EMU_SMultiply(A1,V1);
	V0 = LO;
	EMU_UMultiply(V0,T2);
	V1 = HI;
	V0 = V0 - V1;
	V0 >>= 1;
	V1 += V0;
	A1 = V1 >> 5;
	ZZ_CLOCKCYCLES(29,0x8005A428);
	goto ZZ_5A020_408;
ZZ_5A020_3DC:
	V0 = T6 - V1;
	EMU_SMultiply(A2,V0);
	V0 = LO;
	EMU_UMultiply(V0,T2);
	V1 = HI;
	V0 = V0 - V1;
	V0 >>= 1;
	V1 += V0;
	A2 = V1 >> 5;
	ZZ_CLOCKCYCLES(11,0x8005A428);
ZZ_5A020_408:
	V1 = S2 & 0xFF;
	V0 = V1 < 64;
	if (!V0)
	{
		EMU_SMultiply(A1,V1);
		ZZ_CLOCKCYCLES(4,0x8005A460);
		goto ZZ_5A020_440;
	}
	EMU_SMultiply(A1,V1);
	V0 = LO;
	EMU_UMultiply(V0,T2);
	V1 = HI;
	V0 = V0 - V1;
	V0 >>= 1;
	V1 += V0;
	A1 = V1 >> 5;
	ZZ_CLOCKCYCLES(14,0x8005A48C);
	goto ZZ_5A020_46C;
ZZ_5A020_440:
	V0 = T6 - V1;
	EMU_SMultiply(A2,V0);
	V0 = LO;
	EMU_UMultiply(V0,T2);
	V1 = HI;
	V0 = V0 - V1;
	V0 >>= 1;
	V1 += V0;
	A2 = V1 >> 5;
	ZZ_CLOCKCYCLES(11,0x8005A48C);
ZZ_5A020_46C:
	V1 = 0x80060000;
	V1 = EMU_ReadS16(V1 + 14048); //+ 0x36E0
	V0 = 1;
	if (V1 != V0)
	{
		V0 = A2 < A1;
		ZZ_CLOCKCYCLES(5,0x8005A4B4);
		goto ZZ_5A020_494;
	}
	V0 = A2 < A1;
	if (!V0)
	{
		ZZ_CLOCKCYCLES(7,0x8005A4B0);
		goto ZZ_5A020_490;
	}
	A2 = A1;
	ZZ_CLOCKCYCLES(9,0x8005A4B4);
	goto ZZ_5A020_494;
ZZ_5A020_490:
	A1 = A2;
	ZZ_CLOCKCYCLES(1,0x8005A4B4);
ZZ_5A020_494:
	EMU_SMultiply(A2,A2);
	V0 = LO;
	EMU_SMultiply(A1,A1);
	A0 = LO;
	EMU_UMultiply(V0,T3);
	V1 = HI;
	EMU_UMultiply(A0,T3);
	V0 = V0 - V1;
	V0 >>= 1;
	V1 += V0;
	A2 = V1 >> 13;
	A1 = HI;
	A0 = A0 - A1;
	A0 >>= 1;
	A1 += A0;
	A1 >>= 13;
	A0 = T1 << 16;
	A0 = (int32_t)A0 >> 16;
	V1 = A0 << 4;
	V0 = V1 + T7;
	V1 += T8;
	EMU_Write16(V0,A2);
	EMU_Write16(V1,A1);
	AT = 0x80060000;
	AT += A0;
	V0 = EMU_ReadU8(AT + 2508); //+ 0x9CC
	S4 += 1;
	V0 |= 0x3;
	AT = 0x80060000;
	AT += A0;
	EMU_Write8(AT + 2508,V0); //+ 0x9CC
	V0 = T1 + 1;
	ZZ_CLOCKCYCLES(38,0x8005A54C);
ZZ_5A020_52C:
	T1 = V0;
	V0 <<= 16;
	V1 = 0x80070000;
	V1 = EMU_ReadU8(V1 - 32136); //+ 0xFFFF8278
	V0 = (int32_t)V0 >> 16;
	V0 = (int32_t)V0 < (int32_t)V1;
	if (V0)
	{
		V1 = T1 << 16;
		ZZ_CLOCKCYCLES(8,0x8005A110);
		goto ZZ_5A020_F0;
	}
	V1 = T1 << 16;
	ZZ_CLOCKCYCLES(8,0x8005A56C);
ZZ_5A020_54C:
	V0 = S4;
	RA = EMU_ReadU32(SP + 44); //+ 0x2C
	S6 = EMU_ReadU32(SP + 40); //+ 0x28
	S5 = EMU_ReadU32(SP + 36); //+ 0x24
	S4 = EMU_ReadU32(SP + 32); //+ 0x20
	S3 = EMU_ReadU32(SP + 28); //+ 0x1C
	S2 = EMU_ReadU32(SP + 24); //+ 0x18
	S1 = EMU_ReadU32(SP + 20); //+ 0x14
	S0 = EMU_ReadU32(SP + 16); //+ 0x10
	SP += 48;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(12);
	ZZ_JUMPREGISTER(0x800538BC,ZZ_53830_8C);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x8005A020,0x8005A0A4,ZZ_5A020);
ZZ_MARK_TARGET(0x8005A0A4,0x8005A0B8,ZZ_5A020_84);
ZZ_MARK_TARGET(0x8005A0B8,0x8005A0C4,ZZ_5A020_98);
ZZ_MARK_TARGET(0x8005A0C4,0x8005A110,ZZ_5A020_A4);
ZZ_MARK_TARGET(0x8005A110,0x8005A1A8,ZZ_5A020_F0);
ZZ_MARK_TARGET(0x8005A1A8,0x8005A1AC,ZZ_5A020_188);
ZZ_MARK_TARGET(0x8005A1AC,0x8005A358,ZZ_5A020_18C);
ZZ_MARK_TARGET(0x8005A358,0x8005A388,ZZ_5A020_338);
ZZ_MARK_TARGET(0x8005A388,0x8005A3FC,ZZ_5A020_368);
ZZ_MARK_TARGET(0x8005A3FC,0x8005A428,ZZ_5A020_3DC);
ZZ_MARK_TARGET(0x8005A428,0x8005A460,ZZ_5A020_408);
ZZ_MARK_TARGET(0x8005A460,0x8005A48C,ZZ_5A020_440);
ZZ_MARK_TARGET(0x8005A48C,0x8005A4B0,ZZ_5A020_46C);
ZZ_MARK_TARGET(0x8005A4B0,0x8005A4B4,ZZ_5A020_490);
ZZ_MARK_TARGET(0x8005A4B4,0x8005A54C,ZZ_5A020_494);
ZZ_MARK_TARGET(0x8005A54C,0x8005A56C,ZZ_5A020_52C);
ZZ_MARK_TARGET(0x8005A56C,0x8005A59C,ZZ_5A020_54C);
