#ifdef ZZ_INCLUDE_CODE
ZZ_14A1C:
	SP -= 240;
	EMU_Write32(SP + 232,S6); //+ 0xE8
	S6 = A1;
	EMU_Write32(SP + 208,S0); //+ 0xD0
	S0 = R0;
	EMU_Write32(SP + 228,S5); //+ 0xE4
	S5 = R0;
	EMU_Write32(SP + 216,S2); //+ 0xD8
	S2 = R0;
	EMU_Write32(SP + 236,RA); //+ 0xEC
	EMU_Write32(SP + 224,S4); //+ 0xE0
	EMU_Write32(SP + 220,S3); //+ 0xDC
	if ((int32_t)S6 <= 0)
	{
		EMU_Write32(SP + 212,S1); //+ 0xD4
		ZZ_CLOCKCYCLES(14,0x80014C18);
		goto ZZ_14A1C_1FC;
	}
	EMU_Write32(SP + 212,S1); //+ 0xD4
	S3 = A0;
	S4 = SP + 16;
	S1 = S4;
	ZZ_CLOCKCYCLES(17,0x80014A60);
ZZ_14A1C_44:
	V0 = EMU_ReadU32(S3);
	A0 = EMU_ReadU32(V0);
	V0 = A0 & 0x1;
	if (!V0)
	{
		A3 = A0;
		ZZ_CLOCKCYCLES(7,0x80014A90);
		goto ZZ_14A1C_74;
	}
	A3 = A0;
	RA = 0x80014A84; //ZZ_14A1C_68
	ZZ_CLOCKCYCLES(9,0x80014C48);
	goto ZZ_14C48;
ZZ_14A1C_68:
	V1 = EMU_ReadU32(S3);
	A3 = V0;
	EMU_Write32(V1,A3);
	ZZ_CLOCKCYCLES(3,0x80014A90);
ZZ_14A1C_74:
	A0 = EMU_ReadU32(A3);
	V0 = A0 & 0x1;
	if (V0)
	{
		V1 = (int32_t)A0 >> 1;
		ZZ_CLOCKCYCLES(5,0x80014B2C);
		goto ZZ_14A1C_110;
	}
	V1 = (int32_t)A0 >> 1;
	RA = 0x80014AAC; //ZZ_14A1C_90
	ZZ_CLOCKCYCLES(7,0x8001424C);
	goto ZZ_1424C;
ZZ_14A1C_90:
	A0 = V0;
	if (!A0)
	{
		V0 = 0x2;
		ZZ_CLOCKCYCLES(3,0x80014C08);
		goto ZZ_14A1C_1EC;
	}
	V0 = 0x2;
	V1 = EMU_ReadS16(A0 + 6); //+ 0x6
	if (V1 == V0)
	{
		V0 = 0x1;
		ZZ_CLOCKCYCLES(7,0x80014C08);
		goto ZZ_14A1C_1EC;
	}
	V0 = 0x1;
	V1 = EMU_ReadS16(A0 + 4); //+ 0x4
	if (V1 == V0)
	{
		ZZ_CLOCKCYCLES(11,0x80014AE8);
		goto ZZ_14A1C_CC;
	}
	V0 = EMU_ReadS8(A0 + 15); //+ 0xF
	if (V0)
	{
		ZZ_CLOCKCYCLES(15,0x80014C08);
		goto ZZ_14A1C_1EC;
	}
	ZZ_CLOCKCYCLES(15,0x80014AE8);
ZZ_14A1C_CC:
	if ((int32_t)S0 <= 0)
	{
		A1 = R0;
		ZZ_CLOCKCYCLES(2,0x80014B18);
		goto ZZ_14A1C_FC;
	}
	A1 = R0;
	A2 = EMU_ReadU32(A0 + 20); //+ 0x14
	V1 = S4;
	ZZ_CLOCKCYCLES(4,0x80014AF8);
ZZ_14A1C_DC:
	V0 = EMU_ReadU32(V1);
	if (A2 == V0)
	{
		ZZ_CLOCKCYCLES(4,0x80014B18);
		goto ZZ_14A1C_FC;
	}
	A1 += 1;
	V0 = (int32_t)A1 < (int32_t)S0;
	if (V0)
	{
		V1 += 4;
		ZZ_CLOCKCYCLES(8,0x80014AF8);
		goto ZZ_14A1C_DC;
	}
	V1 += 4;
	ZZ_CLOCKCYCLES(8,0x80014B18);
ZZ_14A1C_FC:
	if (A1 != S0)
	{
		ZZ_CLOCKCYCLES(2,0x80014C08);
		goto ZZ_14A1C_1EC;
	}
	V0 = EMU_ReadU32(A0 + 20); //+ 0x14
	S2 += 1;
	ZZ_CLOCKCYCLES(5,0x80014BFC);
	goto ZZ_14A1C_1E0;
ZZ_14A1C_110:
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32164); //+ 0xFFFF825C
	V1 <<= 2;
	V1 += V0;
	V1 = EMU_ReadU32(V1);
	V0 = -18;
	if (V1 != V0)
	{
		ZZ_CLOCKCYCLES(8,0x80014B8C);
		goto ZZ_14A1C_170;
	}
	if ((int32_t)S0 <= 0)
	{
		A1 = R0;
		ZZ_CLOCKCYCLES(10,0x80014B78);
		goto ZZ_14A1C_15C;
	}
	A1 = R0;
	A2 = S4;
	ZZ_CLOCKCYCLES(11,0x80014B58);
ZZ_14A1C_13C:
	V0 = EMU_ReadU32(A2);
	if (A0 == V0)
	{
		ZZ_CLOCKCYCLES(4,0x80014B78);
		goto ZZ_14A1C_15C;
	}
	A1 += 1;
	V0 = (int32_t)A1 < (int32_t)S0;
	if (V0)
	{
		A2 += 4;
		ZZ_CLOCKCYCLES(8,0x80014B58);
		goto ZZ_14A1C_13C;
	}
	A2 += 4;
	ZZ_CLOCKCYCLES(8,0x80014B78);
ZZ_14A1C_15C:
	if (A1 != S0)
	{
		ZZ_CLOCKCYCLES(2,0x80014C08);
		goto ZZ_14A1C_1EC;
	}
	V0 = EMU_ReadU32(A3);
	S2 += 1;
	ZZ_CLOCKCYCLES(5,0x80014BFC);
	goto ZZ_14A1C_1E0;
ZZ_14A1C_170:
	V0 = -255;
	if (V1 == V0)
	{
		ZZ_CLOCKCYCLES(3,0x80014C08);
		goto ZZ_14A1C_1EC;
	}
	V0 = EMU_ReadS16(V1 + 6); //+ 0x6
	V0 = (int32_t)V0 < 2;
	if (!V0)
	{
		ZZ_CLOCKCYCLES(8,0x80014C08);
		goto ZZ_14A1C_1EC;
	}
	V0 = EMU_ReadS8(V1 + 15); //+ 0xF
	if (V0)
	{
		ZZ_CLOCKCYCLES(12,0x80014C08);
		goto ZZ_14A1C_1EC;
	}
	if ((int32_t)S0 <= 0)
	{
		A1 = R0;
		ZZ_CLOCKCYCLES(14,0x80014BEC);
		goto ZZ_14A1C_1D0;
	}
	A1 = R0;
	A2 = EMU_ReadU32(V1 + 20); //+ 0x14
	A0 = S4;
	ZZ_CLOCKCYCLES(16,0x80014BCC);
ZZ_14A1C_1B0:
	V0 = EMU_ReadU32(A0);
	if (A2 == V0)
	{
		ZZ_CLOCKCYCLES(4,0x80014BEC);
		goto ZZ_14A1C_1D0;
	}
	A1 += 1;
	V0 = (int32_t)A1 < (int32_t)S0;
	if (V0)
	{
		A0 += 4;
		ZZ_CLOCKCYCLES(8,0x80014BCC);
		goto ZZ_14A1C_1B0;
	}
	A0 += 4;
	ZZ_CLOCKCYCLES(8,0x80014BEC);
ZZ_14A1C_1D0:
	if (A1 != S0)
	{
		ZZ_CLOCKCYCLES(2,0x80014C08);
		goto ZZ_14A1C_1EC;
	}
	V0 = EMU_ReadU32(V1 + 20); //+ 0x14
	S2 += 1;
	ZZ_CLOCKCYCLES(4,0x80014BFC);
ZZ_14A1C_1E0:
	S0 += 1;
	EMU_Write32(S1,V0);
	S1 += 4;
	ZZ_CLOCKCYCLES(3,0x80014C08);
ZZ_14A1C_1EC:
	S5 += 1;
	V0 = (int32_t)S5 < (int32_t)S6;
	if (V0)
	{
		S3 += 4;
		ZZ_CLOCKCYCLES(4,0x80014A60);
		goto ZZ_14A1C_44;
	}
	S3 += 4;
	ZZ_CLOCKCYCLES(4,0x80014C18);
ZZ_14A1C_1FC:
	V0 = S2;
	RA = EMU_ReadU32(SP + 236); //+ 0xEC
	S6 = EMU_ReadU32(SP + 232); //+ 0xE8
	S5 = EMU_ReadU32(SP + 228); //+ 0xE4
	S4 = EMU_ReadU32(SP + 224); //+ 0xE0
	S3 = EMU_ReadU32(SP + 220); //+ 0xDC
	S2 = EMU_ReadU32(SP + 216); //+ 0xD8
	S1 = EMU_ReadU32(SP + 212); //+ 0xD4
	S0 = EMU_ReadU32(SP + 208); //+ 0xD0
	SP += 240;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(12);
	ZZ_JUMPREGISTER(0x80039274,ZZ_39198_DC);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80014A1C,0x80014A60,ZZ_14A1C);
ZZ_MARK_TARGET(0x80014A60,0x80014A84,ZZ_14A1C_44);
ZZ_MARK_TARGET(0x80014A84,0x80014A90,ZZ_14A1C_68);
ZZ_MARK_TARGET(0x80014A90,0x80014AAC,ZZ_14A1C_74);
ZZ_MARK_TARGET(0x80014AAC,0x80014AE8,ZZ_14A1C_90);
ZZ_MARK_TARGET(0x80014AE8,0x80014AF8,ZZ_14A1C_CC);
ZZ_MARK_TARGET(0x80014AF8,0x80014B18,ZZ_14A1C_DC);
ZZ_MARK_TARGET(0x80014B18,0x80014B2C,ZZ_14A1C_FC);
ZZ_MARK_TARGET(0x80014B2C,0x80014B58,ZZ_14A1C_110);
ZZ_MARK_TARGET(0x80014B58,0x80014B78,ZZ_14A1C_13C);
ZZ_MARK_TARGET(0x80014B78,0x80014B8C,ZZ_14A1C_15C);
ZZ_MARK_TARGET(0x80014B8C,0x80014BCC,ZZ_14A1C_170);
ZZ_MARK_TARGET(0x80014BCC,0x80014BEC,ZZ_14A1C_1B0);
ZZ_MARK_TARGET(0x80014BEC,0x80014BFC,ZZ_14A1C_1D0);
ZZ_MARK_TARGET(0x80014BFC,0x80014C08,ZZ_14A1C_1E0);
ZZ_MARK_TARGET(0x80014C08,0x80014C18,ZZ_14A1C_1EC);
ZZ_MARK_TARGET(0x80014C18,0x80014C48,ZZ_14A1C_1FC);
