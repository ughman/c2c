#ifdef ZZ_INCLUDE_CODE
ZZ_46020:
	T8 = AT | A3;
	T8 |= T0;
	T8 <<= 13;
	if ((int32_t)T8 >= 0)
	{
		T8 = EMU_ReadU32(V1 + 152); //+ 0x98
		ZZ_CLOCKCYCLES(5,0x800426B8);
		goto ZZ_420F4_5C4;
	}
	T8 = EMU_ReadU32(V1 + 152); //+ 0x98
	T9 = GTE_GetRegister(GTE_DREG_VZ0);
	S3 = GTE_GetRegister(GTE_DREG_VZ1);
	GP = GTE_GetRegister(GTE_DREG_VZ2);
	T9 = T8 - T9;
	T9 &= 0xFC00;
	if (!T9)
	{
		S3 = T8 - S3;
		ZZ_CLOCKCYCLES(12,0x80046064);
		goto ZZ_46020_44;
	}
	S3 = T8 - S3;
	S3 &= 0xFC00;
	if (!S3)
	{
		GP = T8 - GP;
		ZZ_CLOCKCYCLES(15,0x80046064);
		goto ZZ_46020_44;
	}
	GP = T8 - GP;
	GP &= 0xFC00;
	if (GP)
	{
		T8 = EMU_ReadU32(V1 + 148); //+ 0x94
		ZZ_CLOCKCYCLES(18,0x800426B8);
		goto ZZ_420F4_5C4;
	}
	ZZ_CLOCKCYCLES(17,0x80046064);
ZZ_46020_44:
	T8 = EMU_ReadU32(V1 + 148); //+ 0x94
	T9 = GTE_GetRegister(GTE_DREG_VXY0);
	S3 = GTE_GetRegister(GTE_DREG_VXY1);
	GP = GTE_GetRegister(GTE_DREG_VXY2);
	T9 = T8 - T9;
	T9 &= 0xFC00;
	if (!T9)
	{
		S3 = T8 - S3;
		ZZ_CLOCKCYCLES(8,0x8004609C);
		goto ZZ_46020_7C;
	}
	S3 = T8 - S3;
	S3 &= 0xFC00;
	if (!S3)
	{
		GP = T8 - GP;
		ZZ_CLOCKCYCLES(11,0x8004609C);
		goto ZZ_46020_7C;
	}
	GP = T8 - GP;
	GP &= 0xFC00;
	if (GP)
	{
		ZZ_CLOCKCYCLES(14,0x800426B8);
		goto ZZ_420F4_5C4;
	}
	ZZ_CLOCKCYCLES(14,0x8004609C);
ZZ_46020_7C:
	GTE_RotateTranslateProjectTriple();
	T5 = EMU_ReadU32(T5);
	S4 = T3 & 0xE000;
	S4 >>= 8;
	T9 = T3 & 0x7FF;
	T3 &= 0x1800;
	if (!T3)
	{
		S4 += V1;
		ZZ_CLOCKCYCLES(8,0x800460E4);
		goto ZZ_46020_C4;
	}
	S4 += V1;
	T8 = EMU_ReadU32(S4 + 652); //+ 0x28C
	T9 <<= 3;
	T9 += T8;
	S3 = EMU_ReadU32(T9);
	T6 <<= 2;
	T6 &= 0x3C;
	T8 = A3 >> 6;
	T8 &= 0xC00;
	GP = EMU_ReadU32(T9 + 4); //+ 0x4
	ZZ_CLOCKCYCLES(18,0x80046110);
	goto ZZ_46020_F0;
ZZ_46020_C4:
	T8 = EMU_ReadU32(S4 + 648); //+ 0x288
	GP = T9 << 1;
	GP += T8;
	GP = EMU_ReadU16(GP);
	T9 <<= 2;
	T9 = T8 - T9;
	T6 <<= 2;
	T6 &= 0x3C;
	T8 = A3 >> 6;
	T8 &= 0xC00;
	S3 = EMU_ReadU32(T9 - 4); //+ 0xFFFFFFFC
	ZZ_CLOCKCYCLES(11,0x80046110);
ZZ_46020_F0:
	T6 |= T8;
	T8 = A3 << 6;
	T8 &= 0x3C0;
	T6 |= T8;
	T6 += S2;
	T8 = GTE_GetRegister(GTE_DREG_SXY0);
	T9 = GTE_GetRegister(GTE_DREG_SXY1);
	V0 = GTE_GetRegister(GTE_DREG_SXY2);
	RA = EMU_ReadU32(V1 + 540); //+ 0x21C
	A0 = T8 & T9;
	T8 = T8 - RA;
	T9 = T9 - RA;
	A0 &= V0;
	V0 = V0 - RA;
	T8 |= T9;
	T8 = ~(T8 | V0);
	T8 |= A0;
	if ((int32_t)T8 < 0)
	{
		T8 <<= 16;
		ZZ_CLOCKCYCLES(19,0x80042628);
		goto ZZ_420F4_534;
	}
	T8 <<= 16;
	if ((int32_t)T8 < 0)
	{
		A0 = 1904;
		ZZ_CLOCKCYCLES(21,0x80042628);
		goto ZZ_420F4_534;
	}
	A0 = 1904;
	T6 = EMU_ReadU32(T6);
	T7 <<= 2;
	T7 &= 0x3C;
	T9 = T0 >> 6;
	T9 &= 0xC00;
	T7 |= T9;
	T9 = T0 << 6;
	T9 &= 0x3C0;
	T7 |= T9;
	T7 += S2;
	V0 = GTE_GetRegister(GTE_DREG_SZ1);
	T8 = GTE_GetRegister(GTE_DREG_SZ2);
	T9 = GTE_GetRegister(GTE_DREG_SZ3);
	T7 = EMU_ReadU32(T7);
	V0 += T8;
	V0 += T9;
	RA = V0 >> 5;
	V0 = A0 - RA;
	if ((int32_t)V0 >= 0)
	{
		V0 <<= 2;
		ZZ_CLOCKCYCLES(41,0x800461B8);
		goto ZZ_46020_198;
	}
	V0 <<= 2;
	V0 = 0;
	ZZ_CLOCKCYCLES(42,0x800461B8);
ZZ_46020_198:
	V0 += FP;
	EMU_Write32(V1 + 464,RA); //+ 0x1D0
	RA = 0x800461C8; //ZZ_46020_1A8
	EMU_Write32(V1 + 480,V0); //+ 0x1E0
	ZZ_CLOCKCYCLES(4,0x80046478);
	goto ZZ_46478;
ZZ_46020_1A8:
	S2 = EMU_ReadU32(S4 + 660); //+ 0x294
	S6 = EMU_ReadU32(V1 + 472); //+ 0x1D8
	T2 = EMU_ReadU32(V1 + 476); //+ 0x1DC
	ZZ_CLOCKCYCLES(4,0x80042628);
	goto ZZ_420F4_534;
ZZ_46020_1B8:
	T8 = AT | A3;
	T8 |= T0;
	T8 |= A0;
	T8 <<= 13;
	if ((int32_t)T8 >= 0)
	{
		T8 = EMU_ReadU32(V1 + 152); //+ 0x98
		ZZ_CLOCKCYCLES(6,0x80042938);
		goto ZZ_420F4_844;
	}
	T8 = EMU_ReadU32(V1 + 152); //+ 0x98
	T9 = GTE_GetRegister(GTE_DREG_VZ0);
	S3 = GTE_GetRegister(GTE_DREG_VZ1);
	GP = GTE_GetRegister(GTE_DREG_VZ2);
	T9 = T8 - T9;
	T9 &= 0xFC00;
	if (!T9)
	{
		S3 = T8 - S3;
		ZZ_CLOCKCYCLES(13,0x80046220);
		goto ZZ_46020_200;
	}
	S3 = T8 - S3;
	S3 &= 0xFC00;
	if (!S3)
	{
		GP = T8 - GP;
		ZZ_CLOCKCYCLES(16,0x80046220);
		goto ZZ_46020_200;
	}
	GP = T8 - GP;
	GP &= 0xFC00;
	if (GP)
	{
		T8 = EMU_ReadU32(V1 + 148); //+ 0x94
		ZZ_CLOCKCYCLES(19,0x80042938);
		goto ZZ_420F4_844;
	}
	ZZ_CLOCKCYCLES(18,0x80046220);
ZZ_46020_200:
	T8 = EMU_ReadU32(V1 + 148); //+ 0x94
	T9 = GTE_GetRegister(GTE_DREG_VXY0);
	S3 = GTE_GetRegister(GTE_DREG_VXY1);
	GP = GTE_GetRegister(GTE_DREG_VXY2);
	T9 = T8 - T9;
	T9 &= 0xFC00;
	if (!T9)
	{
		S3 = T8 - S3;
		ZZ_CLOCKCYCLES(8,0x80046258);
		goto ZZ_46020_238;
	}
	S3 = T8 - S3;
	S3 &= 0xFC00;
	if (!S3)
	{
		GP = T8 - GP;
		ZZ_CLOCKCYCLES(11,0x80046258);
		goto ZZ_46020_238;
	}
	GP = T8 - GP;
	GP &= 0xFC00;
	if (GP)
	{
		ZZ_CLOCKCYCLES(14,0x80042938);
		goto ZZ_420F4_844;
	}
	ZZ_CLOCKCYCLES(14,0x80046258);
ZZ_46020_238:
	GTE_RotateTranslateProjectTriple();
	T5 = EMU_ReadU32(T5);
	S4 = T3 & 0xE000;
	S4 >>= 8;
	T9 = T3 & 0x7FF;
	T3 &= 0x1800;
	if (!T3)
	{
		S4 += V1;
		ZZ_CLOCKCYCLES(8,0x800462A0);
		goto ZZ_46020_280;
	}
	S4 += V1;
	T8 = EMU_ReadU32(S4 + 652); //+ 0x28C
	T9 <<= 3;
	T9 += T8;
	S3 = EMU_ReadU32(T9);
	T6 <<= 2;
	T6 &= 0x3C;
	T8 = A3 >> 6;
	T8 &= 0xC00;
	GP = EMU_ReadU32(T9 + 4); //+ 0x4
	ZZ_CLOCKCYCLES(18,0x800462CC);
	goto ZZ_46020_2AC;
ZZ_46020_280:
	T8 = EMU_ReadU32(S4 + 648); //+ 0x288
	GP = T9 << 1;
	GP += T8;
	GP = EMU_ReadU16(GP);
	T9 <<= 2;
	T9 = T8 - T9;
	T6 <<= 2;
	T6 &= 0x3C;
	T8 = A3 >> 6;
	T8 &= 0xC00;
	S3 = EMU_ReadU32(T9 - 4); //+ 0xFFFFFFFC
	ZZ_CLOCKCYCLES(11,0x800462CC);
ZZ_46020_2AC:
	T6 |= T8;
	T8 = A3 << 6;
	T8 &= 0x3C0;
	T6 |= T8;
	T6 += S2;
	EMU_Write32(V1 + 376,GTE_GetRegister(GTE_DREG_SXY0)); //+ 0x178
	EMU_Write32(V1 + 380,GTE_GetRegister(GTE_DREG_SZ1)); //+ 0x17C
	EMU_Write32(V1 + 436,GTE_GetRegister(GTE_DREG_VXY0)); //+ 0x1B4
	EMU_Write32(V1 + 440,GTE_GetRegister(GTE_DREG_VZ0)); //+ 0x1B8
	GTE_SetRegister(GTE_DREG_VXY0,V0);
	GTE_SetRegister(GTE_DREG_VZ0,A2);
	EMU_Write32(V1 + 544,V0); //+ 0x220
	EMU_Write32(V1 + 548,A2); //+ 0x224
	T8 = GTE_GetRegister(GTE_DREG_SXY0);
	T9 = GTE_GetRegister(GTE_DREG_SXY1);
	V0 = GTE_GetRegister(GTE_DREG_SXY2);
	RA = EMU_ReadU32(V1 + 540); //+ 0x21C
	GTE_RotateTranslateProjectSingle();
	T6 = EMU_ReadU32(T6);
	A2 = T8 & T9;
	T8 = T8 - RA;
	T9 = T9 - RA;
	A2 &= V0;
	V0 = V0 - RA;
	T8 |= T9;
	T7 <<= 2;
	T7 &= 0x3C;
	T9 = T0 >> 6;
	T9 &= 0xC00;
	T7 |= T9;
	T9 = GTE_GetRegister(GTE_DREG_SXY2);
	T8 |= V0;
	A2 &= T9;
	T9 = T9 - RA;
	T8 = ~(T8 | T9);
	T8 |= A2;
	if ((int32_t)T8 < 0)
	{
		T8 <<= 16;
		ZZ_CLOCKCYCLES(39,0x80042628);
		goto ZZ_420F4_534;
	}
	T8 <<= 16;
	if ((int32_t)T8 < 0)
	{
		A2 = 1904;
		ZZ_CLOCKCYCLES(41,0x80042628);
		goto ZZ_420F4_534;
	}
	A2 = 1904;
	T9 = T0 << 6;
	T9 &= 0x3C0;
	T7 |= T9;
	T7 += S2;
	T7 = EMU_ReadU32(T7);
	A1 <<= 2;
	A1 &= 0x3C;
	T9 = A0 >> 6;
	T9 &= 0xC00;
	A1 |= T9;
	T9 = A0 << 6;
	T9 &= 0x3C0;
	A1 |= T9;
	A1 += S2;
	V0 = GTE_GetRegister(GTE_DREG_SZ1);
	T8 = GTE_GetRegister(GTE_DREG_SZ2);
	T9 = GTE_GetRegister(GTE_DREG_SZ3);
	A1 = EMU_ReadU32(A1);
	V0 += T8;
	V0 += T9;
	RA = V0 >> 5;
	V0 = A2 - RA;
	if ((int32_t)V0 >= 0)
	{
		V0 <<= 2;
		ZZ_CLOCKCYCLES(65,0x800463D4);
		goto ZZ_46020_3B4;
	}
	V0 <<= 2;
	V0 = 0;
	ZZ_CLOCKCYCLES(66,0x800463D4);
ZZ_46020_3B4:
	V0 += FP;
	EMU_Write32(V1 + 480,V0); //+ 0x1E0
	EMU_Write32(V1 + 464,RA); //+ 0x1D0
	T8 = A1;
	A1 = T5;
	T5 = T6;
	T6 = T7;
	T7 = T8;
	EMU_Write32(V1 + 388,S6); //+ 0x184
	EMU_Write32(V1 + 536,S5); //+ 0x218
	EMU_Write32(V1 + 444,GTE_GetRegister(GTE_DREG_VXY1)); //+ 0x1BC
	EMU_Write32(V1 + 448,GTE_GetRegister(GTE_DREG_VZ1)); //+ 0x1C0
	GTE_SetRegister(GTE_DREG_VXY0,EMU_ReadU32(V1 + 444)); //+ 0x1BC
	GTE_SetRegister(GTE_DREG_VZ0,EMU_ReadU32(V1 + 448)); //+ 0x1C0
	EMU_Write32(V1 + 452,GTE_GetRegister(GTE_DREG_VXY2)); //+ 0x1C4
	EMU_Write32(V1 + 456,GTE_GetRegister(GTE_DREG_VZ2)); //+ 0x1C8
	GTE_SetRegister(GTE_DREG_VXY1,EMU_ReadU32(V1 + 452)); //+ 0x1C4
	GTE_SetRegister(GTE_DREG_VZ1,EMU_ReadU32(V1 + 456)); //+ 0x1C8
	GTE_SetRegister(GTE_DREG_VXY2,EMU_ReadU32(V1 + 544)); //+ 0x220
	GTE_SetRegister(GTE_DREG_VZ2,EMU_ReadU32(V1 + 548)); //+ 0x224
	RA = 0x8004642C; //ZZ_46020_40C
	EMU_Write32(V1 + 552,A1); //+ 0x228
	ZZ_CLOCKCYCLES(22,0x80046478);
	goto ZZ_46478;
ZZ_46020_40C:
	S5 = EMU_ReadU32(V1 + 536); //+ 0x218
	T6 = EMU_ReadU32(V1 + 424); //+ 0x1A8
	T7 = EMU_ReadU32(V1 + 428); //+ 0x1AC
	GTE_SetRegister(GTE_DREG_SXY1,EMU_ReadU32(V1 + 400)); //+ 0x190
	GTE_SetRegister(GTE_DREG_SXY2,EMU_ReadU32(V1 + 408)); //+ 0x198
	GTE_SetRegister(GTE_DREG_SXY0,EMU_ReadU32(V1 + 376)); //+ 0x178
	GTE_SetRegister(GTE_DREG_VXY1,EMU_ReadU32(V1 + 444)); //+ 0x1BC
	GTE_SetRegister(GTE_DREG_VZ1,EMU_ReadU32(V1 + 448)); //+ 0x1C0
	GTE_SetRegister(GTE_DREG_VXY2,EMU_ReadU32(V1 + 452)); //+ 0x1C4
	GTE_SetRegister(GTE_DREG_VZ2,EMU_ReadU32(V1 + 456)); //+ 0x1C8
	GTE_SetRegister(GTE_DREG_VXY0,EMU_ReadU32(V1 + 436)); //+ 0x1B4
	GTE_SetRegister(GTE_DREG_VZ0,EMU_ReadU32(V1 + 440)); //+ 0x1B8
	EMU_Write32(V1 + 388,R0); //+ 0x184
	RA = 0x80046468; //ZZ_46020_448
	T5 = EMU_ReadU32(V1 + 552); //+ 0x228
	ZZ_CLOCKCYCLES(15,0x80046478);
	goto ZZ_46478;
ZZ_46020_448:
	S2 = EMU_ReadU32(S4 + 660); //+ 0x294
	S6 = EMU_ReadU32(V1 + 472); //+ 0x1D8
	T2 = EMU_ReadU32(V1 + 476); //+ 0x1DC
	ZZ_CLOCKCYCLES(4,0x80042628);
	goto ZZ_420F4_534;
#endif
ZZ_MARK_TARGET(0x80046020,0x80046064,ZZ_46020);
ZZ_MARK_TARGET(0x80046064,0x8004609C,ZZ_46020_44);
ZZ_MARK_TARGET(0x8004609C,0x800460E4,ZZ_46020_7C);
ZZ_MARK_TARGET(0x800460E4,0x80046110,ZZ_46020_C4);
ZZ_MARK_TARGET(0x80046110,0x800461B8,ZZ_46020_F0);
ZZ_MARK_TARGET(0x800461B8,0x800461C8,ZZ_46020_198);
ZZ_MARK_TARGET(0x800461C8,0x800461D8,ZZ_46020_1A8);
ZZ_MARK_TARGET(0x800461D8,0x80046220,ZZ_46020_1B8);
ZZ_MARK_TARGET(0x80046220,0x80046258,ZZ_46020_200);
ZZ_MARK_TARGET(0x80046258,0x800462A0,ZZ_46020_238);
ZZ_MARK_TARGET(0x800462A0,0x800462CC,ZZ_46020_280);
ZZ_MARK_TARGET(0x800462CC,0x800463D4,ZZ_46020_2AC);
ZZ_MARK_TARGET(0x800463D4,0x8004642C,ZZ_46020_3B4);
ZZ_MARK_TARGET(0x8004642C,0x80046468,ZZ_46020_40C);
ZZ_MARK_TARGET(0x80046468,0x80046478,ZZ_46020_448);
