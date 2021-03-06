#ifdef ZZ_INCLUDE_CODE
ZZ_5AB94:
	SP -= 1080;
	EMU_Write32(SP + 1060,S3); //+ 0x424
	S3 = A0;
	EMU_Write32(SP + 1048,S0); //+ 0x418
	S0 = A1;
	EMU_Write32(SP + 1052,S1); //+ 0x41C
	S1 = 16;
	EMU_Write32(SP + 1068,S5); //+ 0x42C
	S5 = A3;
	EMU_Write32(SP + 1064,S4); //+ 0x428
	S4 = A2;
	EMU_Write32(SP + 1072,RA); //+ 0x430
	RA = 0x8005ABCC; //ZZ_5AB94_38
	EMU_Write32(SP + 1056,S2); //+ 0x420
	ZZ_CLOCKCYCLES(14,0x80057A94);
	goto ZZ_57A94;
ZZ_5AB94_38:
	V1 = 1;
	if (V0 != V1)
	{
		S2 = S0;
		ZZ_CLOCKCYCLES(3,0x8005ABE0);
		goto ZZ_5AB94_4C;
	}
	S2 = S0;
	V0 = -1;
	ZZ_CLOCKCYCLES(5,0x8005AF48);
	goto ZZ_5AB94_3B4;
ZZ_5AB94_4C:
	RA = 0x8005ABE8; //ZZ_5AB94_54
	A0 = 1;
	ZZ_CLOCKCYCLES(2,0x80057A6C);
	goto ZZ_57A6C;
ZZ_5AB94_54:
	V0 = S0 << 16;
	V1 = (int32_t)V0 >> 16;
	V0 = (int32_t)V1 < 16;
	if (!V0)
	{
		V0 = -1;
		ZZ_CLOCKCYCLES(5,0x8005ACA4);
		goto ZZ_5AB94_110;
	}
	V0 = -1;
	if (V1 != V0)
	{
		A1 = R0;
		ZZ_CLOCKCYCLES(7,0x8005AC50);
		goto ZZ_5AB94_BC;
	}
	A1 = R0;
	ZZ_CLOCKCYCLES(7,0x8005AC04);
ZZ_5AB94_70:
	AT = 0x80070000;
	AT += A1;
	V0 = EMU_ReadU8(AT - 26596); //+ 0xFFFF981C
	if (!V0)
	{
		V0 = 1;
		ZZ_CLOCKCYCLES(6,0x8005AC34);
		goto ZZ_5AB94_A0;
	}
	V0 = 1;
	A1 += 1;
	V0 = (int32_t)A1 < 16;
	if (V0)
	{
		V0 = S1 << 16;
		ZZ_CLOCKCYCLES(10,0x8005AC04);
		goto ZZ_5AB94_70;
	}
	V0 = S1 << 16;
	ZZ_CLOCKCYCLES(12,0x8005AC94);
	goto ZZ_5AB94_100;
ZZ_5AB94_A0:
	AT = 0x80070000;
	AT += A1;
	EMU_Write8(AT - 26596,V0); //+ 0xFFFF981C
	V0 = 0x80070000;
	V0 = EMU_ReadU16(V0 - 13020); //+ 0xFFFFCD24
	S1 = A1;
	ZZ_CLOCKCYCLES(7,0x8005AC84);
	goto ZZ_5AB94_F0;
ZZ_5AB94_BC:
	AT = 0x80070000;
	AT += V1;
	V0 = EMU_ReadU8(AT - 26596); //+ 0xFFFF981C
	if (V0)
	{
		V0 = S1 << 16;
		ZZ_CLOCKCYCLES(6,0x8005AC94);
		goto ZZ_5AB94_100;
	}
	V0 = S1 << 16;
	V0 = 1;
	AT = 0x80070000;
	AT += V1;
	EMU_Write8(AT - 26596,V0); //+ 0xFFFF981C
	V0 = 0x80070000;
	V0 = EMU_ReadU16(V0 - 13020); //+ 0xFFFFCD24
	S1 = S2;
	ZZ_CLOCKCYCLES(13,0x8005AC84);
ZZ_5AB94_F0:
	V0 += 1;
	AT = 0x80070000;
	EMU_Write16(AT - 13020,V0); //+ 0xFFFFCD24
	V0 = S1 << 16;
	ZZ_CLOCKCYCLES(4,0x8005AC94);
ZZ_5AB94_100:
	A3 = (int32_t)V0 >> 16;
	V0 = (int32_t)A3 < 16;
	if (V0)
	{
		A2 = S3;
		ZZ_CLOCKCYCLES(4,0x8005ACB4);
		goto ZZ_5AB94_120;
	}
	A2 = S3;
	ZZ_CLOCKCYCLES(4,0x8005ACA4);
ZZ_5AB94_110:
	RA = 0x8005ACAC; //ZZ_5AB94_118
	A0 = R0;
	ZZ_CLOCKCYCLES(2,0x80057A6C);
	goto ZZ_57A6C;
ZZ_5AB94_118:
	V0 = -1;
	ZZ_CLOCKCYCLES(2,0x8005AF48);
	goto ZZ_5AB94_3B4;
ZZ_5AB94_120:
	V0 = A3 << 2;
	AT = 0x80060000;
	AT += V0;
	EMU_Write32(AT + 11712,A2); //+ 0x2DC0
	V1 = 0x560000;
	A0 = S3;
	A1 = EMU_ReadU32(A0);
	V1 |= 0x4142;
	V0 = A1 >> 8;
	if (V0 == V1)
	{
		A2 += 32;
		ZZ_CLOCKCYCLES(11,0x8005ACF4);
		goto ZZ_5AB94_160;
	}
	A2 += 32;
	AT = 0x80070000;
	AT += A3;
	EMU_Write8(AT - 26596,R0); //+ 0xFFFF981C
	A0 = R0;
	ZZ_CLOCKCYCLES(16,0x8005AE68);
	goto ZZ_5AB94_2D4;
ZZ_5AB94_160:
	V1 = A1 & 0xFF;
	V0 = 112;
	if (V1 != V0)
	{
		V0 = 64;
		ZZ_CLOCKCYCLES(4,0x8005AD1C);
		goto ZZ_5AB94_188;
	}
	V0 = 64;
	V0 = EMU_ReadU32(A0 + 4); //+ 0x4
	V0 = (int32_t)V0 < 5;
	if (V0)
	{
		V0 = 64;
		ZZ_CLOCKCYCLES(9,0x8005AD1C);
		goto ZZ_5AB94_188;
	}
	V0 = 64;
	V0 = 128;
	ZZ_CLOCKCYCLES(10,0x8005AD1C);
ZZ_5AB94_188:
	AT = 0x80070000;
	EMU_Write16(AT - 32156,V0); //+ 0xFFFF8264
	V0 = EMU_ReadU16(A0 + 18); //+ 0x12
	V1 = 0x80070000;
	V1 = EMU_ReadS16(V1 - 32156); //+ 0xFFFF8264
	V0 = (int32_t)V1 < (int32_t)V0;
	if (V0)
	{
		S2 = A2;
		ZZ_CLOCKCYCLES(9,0x8005AE50);
		goto ZZ_5AB94_2BC;
	}
	S2 = A2;
	V0 = S1 << 16;
	V0 = (int32_t)V0 >> 14;
	AT = 0x80060000;
	AT += V0;
	EMU_Write32(AT + 11648,A2); //+ 0x2D80
	V0 = V1 << 4;
	A2 = S2 + V0;
	A1 = R0;
	if ((int32_t)V1 <= 0)
	{
		S0 = R0;
		ZZ_CLOCKCYCLES(19,0x8005AD94);
		goto ZZ_5AB94_200;
	}
	S0 = R0;
	A3 = V1;
	V1 = S2;
	ZZ_CLOCKCYCLES(21,0x8005AD70);
ZZ_5AB94_1DC:
	V0 = EMU_ReadU8(V1);
	if (!V0)
	{
		EMU_Write32(V1 + 8,S0); //+ 0x8
		ZZ_CLOCKCYCLES(4,0x8005AD84);
		goto ZZ_5AB94_1F0;
	}
	EMU_Write32(V1 + 8,S0); //+ 0x8
	S0 += 1;
	ZZ_CLOCKCYCLES(5,0x8005AD84);
ZZ_5AB94_1F0:
	A1 += 1;
	V0 = (int32_t)A1 < (int32_t)A3;
	if (V0)
	{
		V1 += 16;
		ZZ_CLOCKCYCLES(4,0x8005AD70);
		goto ZZ_5AB94_1DC;
	}
	V1 += 16;
	ZZ_CLOCKCYCLES(4,0x8005AD94);
ZZ_5AB94_200:
	S0 = R0;
	A1 = SP + 16;
	V0 = S1 << 16;
	V0 = (int32_t)V0 >> 14;
	T0 = SP + 1040;
	AT = 0x80060000;
	AT += V0;
	EMU_Write32(AT + 11780,A2); //+ 0x2E04
	V0 = EMU_ReadU16(A0 + 18); //+ 0x12
	S3 = EMU_ReadU8(A0 + 22); //+ 0x16
	V0 <<= 9;
	A2 += V0;
	V0 = S3 << 2;
	A3 = V0 + A1;
	ZZ_CLOCKCYCLES(14,0x8005ADCC);
ZZ_5AB94_238:
	V0 = (int32_t)A3 < (int32_t)A1;
	if (V0)
	{
		ZZ_CLOCKCYCLES(3,0x8005AE00);
		goto ZZ_5AB94_26C;
	}
	V0 = EMU_ReadU32(A0 + 4); //+ 0x4
	V1 = EMU_ReadU16(A2);
	V0 = (int32_t)V0 < 5;
	if (V0)
	{
		V0 = V1 << 2;
		ZZ_CLOCKCYCLES(8,0x8005ADF0);
		goto ZZ_5AB94_25C;
	}
	V0 = V1 << 2;
	V0 = V1 << 3;
	ZZ_CLOCKCYCLES(9,0x8005ADF0);
ZZ_5AB94_25C:
	EMU_Write32(A1,V0);
	V0 = EMU_ReadU32(A1);
	S0 += V0;
	ZZ_CLOCKCYCLES(4,0x8005AE00);
ZZ_5AB94_26C:
	A1 += 4;
	V0 = (int32_t)A1 < (int32_t)T0;
	if (V0)
	{
		A2 += 2;
		ZZ_CLOCKCYCLES(4,0x8005ADCC);
		goto ZZ_5AB94_238;
	}
	A2 += 2;
	V0 = S4 << 16;
	if (V0)
	{
		A3 = S5;
		ZZ_CLOCKCYCLES(7,0x8005AE3C);
		goto ZZ_5AB94_2A8;
	}
	A3 = S5;
	RA = 0x8005AE24; //ZZ_5AB94_290
	A0 = S0;
	ZZ_CLOCKCYCLES(9,0x8005AF70);
	goto ZZ_5AF70;
ZZ_5AB94_290:
	A3 = V0;
	V0 = -1;
	if (A3 != V0)
	{
		V1 = A3 + S0;
		ZZ_CLOCKCYCLES(4,0x8005AE40);
		goto ZZ_5AB94_2AC;
	}
	V1 = A3 + S0;
	A0 = R0;
	ZZ_CLOCKCYCLES(6,0x8005AE54);
	goto ZZ_5AB94_2C0;
ZZ_5AB94_2A8:
	V1 = A3 + S0;
	ZZ_CLOCKCYCLES(1,0x8005AE40);
ZZ_5AB94_2AC:
	V0 = 0x80000;
	V0 = V0 < V1;
	if (!V0)
	{
		S0 = R0;
		ZZ_CLOCKCYCLES(4,0x8005AE90);
		goto ZZ_5AB94_2FC;
	}
	S0 = R0;
	ZZ_CLOCKCYCLES(4,0x8005AE50);
ZZ_5AB94_2BC:
	A0 = R0;
	ZZ_CLOCKCYCLES(1,0x8005AE54);
ZZ_5AB94_2C0:
	V0 = S1 << 16;
	V0 = (int32_t)V0 >> 16;
	AT = 0x80070000;
	AT += V0;
	EMU_Write8(AT - 26596,R0); //+ 0xFFFF981C
	ZZ_CLOCKCYCLES(5,0x8005AE68);
ZZ_5AB94_2D4:
	RA = 0x8005AE70; //ZZ_5AB94_2DC
	ZZ_CLOCKCYCLES(2,0x80057A6C);
	goto ZZ_57A6C;
ZZ_5AB94_2DC:
	V1 = 0x80070000;
	V1 = EMU_ReadU16(V1 - 13020); //+ 0xFFFFCD24
	V1 -= 1;
	AT = 0x80070000;
	EMU_Write16(AT - 13020,V1); //+ 0xFFFFCD24
	V0 = -1;
	ZZ_CLOCKCYCLES(8,0x8005AF48);
	goto ZZ_5AB94_3B4;
ZZ_5AB94_2FC:
	V0 = S1 << 16;
	V0 = (int32_t)V0 >> 14;
	AT = 0x80070000;
	AT += V0;
	EMU_Write32(AT - 13016,A3); //+ 0xFFFFCD28
	V1 = S3 & 0xFF;
	V0 = (int32_t)V1 < 0;
	if (V0)
	{
		A1 = R0;
		ZZ_CLOCKCYCLES(9,0x8005AF20);
		goto ZZ_5AB94_38C;
	}
	A1 = R0;
	A2 = V1;
	A0 = SP + 16;
	ZZ_CLOCKCYCLES(11,0x8005AEBC);
ZZ_5AB94_328:
	V0 = EMU_ReadU32(A0);
	S0 += V0;
	V0 = A1 & 0x1;
	if (V0)
	{
		V1 = A1 >> 31;
		ZZ_CLOCKCYCLES(6,0x8005AEF4);
		goto ZZ_5AB94_360;
	}
	V1 = A1 >> 31;
	V1 += A1;
	V1 = (int32_t)V1 >> 1;
	V1 <<= 4;
	V1 += S2;
	V0 = A3 + S0;
	V0 >>= 3;
	EMU_Write16(V1 + 12,V0); //+ 0xC
	ZZ_CLOCKCYCLES(14,0x8005AF10);
	goto ZZ_5AB94_37C;
ZZ_5AB94_360:
	V1 += A1;
	V1 = (int32_t)V1 >> 1;
	V1 <<= 4;
	V1 += S2;
	V0 = A3 + S0;
	V0 >>= 3;
	EMU_Write16(V1 + 14,V0); //+ 0xE
	ZZ_CLOCKCYCLES(7,0x8005AF10);
ZZ_5AB94_37C:
	A1 += 1;
	V0 = (int32_t)A2 < (int32_t)A1;
	if (!V0)
	{
		A0 += 4;
		ZZ_CLOCKCYCLES(4,0x8005AEBC);
		goto ZZ_5AB94_328;
	}
	A0 += 4;
	ZZ_CLOCKCYCLES(4,0x8005AF20);
ZZ_5AB94_38C:
	V0 = S1 << 16;
	V0 = (int32_t)V0 >> 16;
	V1 = V0 << 2;
	AT = 0x80070000;
	AT += V1;
	EMU_Write32(AT - 13084,S0); //+ 0xFFFFCCE4
	V1 = 2;
	AT = 0x80070000;
	AT += V0;
	EMU_Write8(AT - 26596,V1); //+ 0xFFFF981C
	ZZ_CLOCKCYCLES(10,0x8005AF48);
ZZ_5AB94_3B4:
	RA = EMU_ReadU32(SP + 1072); //+ 0x430
	S5 = EMU_ReadU32(SP + 1068); //+ 0x42C
	S4 = EMU_ReadU32(SP + 1064); //+ 0x428
	S3 = EMU_ReadU32(SP + 1060); //+ 0x424
	S2 = EMU_ReadU32(SP + 1056); //+ 0x420
	S1 = EMU_ReadU32(SP + 1052); //+ 0x41C
	S0 = EMU_ReadU32(SP + 1048); //+ 0x418
	SP += 1080;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(10);
	ZZ_JUMPREGISTER(0x8005AB80,ZZ_5AB64_1C);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x8005AB94,0x8005ABCC,ZZ_5AB94);
ZZ_MARK_TARGET(0x8005ABCC,0x8005ABE0,ZZ_5AB94_38);
ZZ_MARK_TARGET(0x8005ABE0,0x8005ABE8,ZZ_5AB94_4C);
ZZ_MARK_TARGET(0x8005ABE8,0x8005AC04,ZZ_5AB94_54);
ZZ_MARK_TARGET(0x8005AC04,0x8005AC34,ZZ_5AB94_70);
ZZ_MARK_TARGET(0x8005AC34,0x8005AC50,ZZ_5AB94_A0);
ZZ_MARK_TARGET(0x8005AC50,0x8005AC84,ZZ_5AB94_BC);
ZZ_MARK_TARGET(0x8005AC84,0x8005AC94,ZZ_5AB94_F0);
ZZ_MARK_TARGET(0x8005AC94,0x8005ACA4,ZZ_5AB94_100);
ZZ_MARK_TARGET(0x8005ACA4,0x8005ACAC,ZZ_5AB94_110);
ZZ_MARK_TARGET(0x8005ACAC,0x8005ACB4,ZZ_5AB94_118);
ZZ_MARK_TARGET(0x8005ACB4,0x8005ACF4,ZZ_5AB94_120);
ZZ_MARK_TARGET(0x8005ACF4,0x8005AD1C,ZZ_5AB94_160);
ZZ_MARK_TARGET(0x8005AD1C,0x8005AD70,ZZ_5AB94_188);
ZZ_MARK_TARGET(0x8005AD70,0x8005AD84,ZZ_5AB94_1DC);
ZZ_MARK_TARGET(0x8005AD84,0x8005AD94,ZZ_5AB94_1F0);
ZZ_MARK_TARGET(0x8005AD94,0x8005ADCC,ZZ_5AB94_200);
ZZ_MARK_TARGET(0x8005ADCC,0x8005ADF0,ZZ_5AB94_238);
ZZ_MARK_TARGET(0x8005ADF0,0x8005AE00,ZZ_5AB94_25C);
ZZ_MARK_TARGET(0x8005AE00,0x8005AE24,ZZ_5AB94_26C);
ZZ_MARK_TARGET(0x8005AE24,0x8005AE3C,ZZ_5AB94_290);
ZZ_MARK_TARGET(0x8005AE3C,0x8005AE40,ZZ_5AB94_2A8);
ZZ_MARK_TARGET(0x8005AE40,0x8005AE50,ZZ_5AB94_2AC);
ZZ_MARK_TARGET(0x8005AE50,0x8005AE54,ZZ_5AB94_2BC);
ZZ_MARK_TARGET(0x8005AE54,0x8005AE68,ZZ_5AB94_2C0);
ZZ_MARK_TARGET(0x8005AE68,0x8005AE70,ZZ_5AB94_2D4);
ZZ_MARK_TARGET(0x8005AE70,0x8005AE90,ZZ_5AB94_2DC);
ZZ_MARK_TARGET(0x8005AE90,0x8005AEBC,ZZ_5AB94_2FC);
ZZ_MARK_TARGET(0x8005AEBC,0x8005AEF4,ZZ_5AB94_328);
ZZ_MARK_TARGET(0x8005AEF4,0x8005AF10,ZZ_5AB94_360);
ZZ_MARK_TARGET(0x8005AF10,0x8005AF20,ZZ_5AB94_37C);
ZZ_MARK_TARGET(0x8005AF20,0x8005AF48,ZZ_5AB94_38C);
ZZ_MARK_TARGET(0x8005AF48,0x8005AF70,ZZ_5AB94_3B4);
