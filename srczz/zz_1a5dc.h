#ifdef ZZ_INCLUDE_CODE
ZZ_1A5DC:
	SP -= 64;
	EMU_Write32(SP + 48,S0); //+ 0x30
	S0 = A0;
	EMU_Write32(SP + 56,RA); //+ 0x38
	EMU_Write32(SP + 52,S1); //+ 0x34
	V0 = EMU_ReadU32(S0 + 8); //+ 0x8
	EMU_Write32(V0 + 40,R0); //+ 0x28
	A0 = EMU_ReadU32(S0 + 232); //+ 0xE8
	if (!A0)
	{
		S1 = A1;
		ZZ_CLOCKCYCLES(12,0x8001A830);
		goto ZZ_1A5DC_254;
	}
	S1 = A1;
	V1 = EMU_ReadU8(A0);
	V0 = 0x4;
	if (V1 == V0)
	{
		V1 = 0xFF800000;
		ZZ_CLOCKCYCLES(16,0x8001A660);
		goto ZZ_1A5DC_84;
	}
	V1 = 0xFF800000;
	V1 |= 0x3;
	A0 += 4;
	V1 &= A0;
	V0 = 0x80000000;
	if (V1 != V0)
	{
		A1 = 0x1;
		ZZ_CLOCKCYCLES(22,0x8001A830);
		goto ZZ_1A5DC_254;
	}
	A1 = 0x1;
	RA = 0x8001A63C; //ZZ_1A5DC_60
	A2 = R0;
	ZZ_CLOCKCYCLES(24,0x80014364);
	goto ZZ_14364;
ZZ_1A5DC_60:
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	EMU_Write32(V1 + 40,V0); //+ 0x28
	V0 = (int32_t)V0 < -254;
	if (V0)
	{
		ZZ_CLOCKCYCLES(6,0x8001A660);
		goto ZZ_1A5DC_84;
	}
	V0 = EMU_ReadU32(S0 + 8); //+ 0x8
	EMU_Write32(V0 + 40,R0); //+ 0x28
	ZZ_CLOCKCYCLES(9,0x8001A830);
	goto ZZ_1A5DC_254;
ZZ_1A5DC_84:
	V0 = EMU_ReadU32(S0 + 232); //+ 0xE8
	V1 = EMU_ReadU8(V0);
	V0 = 0x1;
	if (V1 != V0)
	{
		V0 = -14;
		ZZ_CLOCKCYCLES(6,0x8001A824);
		goto ZZ_1A5DC_248;
	}
	V0 = -14;
	A2 = EMU_ReadU32(S0 + 8); //+ 0x8
	A0 = S0;
	A1 = SP + 40;
	RA = 0x8001A68C; //ZZ_1A5DC_B0
	A2 += 36;
	ZZ_CLOCKCYCLES(11,0x8001AA44);
	goto ZZ_1AA44;
ZZ_1A5DC_B0:
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	EMU_Write32(V1 + 44,V0); //+ 0x2C
	V0 = EMU_ReadU32(SP + 40); //+ 0x28
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	A1 = 0x1;
	A2 = R0;
	A0 = V0 + 16;
	RA = 0x8001A6B4; //ZZ_1A5DC_D8
	EMU_Write32(V1 + 32,V0); //+ 0x20
	ZZ_CLOCKCYCLES(10,0x80014364);
	goto ZZ_14364;
ZZ_1A5DC_D8:
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	A0 = 0x80060000;
	A0 = EMU_ReadU32(A0 - 2524); //+ 0xFFFFF624
	if (S0 != A0)
	{
		EMU_Write32(V1 + 40,V0); //+ 0x28
		ZZ_CLOCKCYCLES(6,0x8001A830);
		goto ZZ_1A5DC_254;
	}
	EMU_Write32(V1 + 40,V0); //+ 0x28
	A2 = EMU_ReadU32(S1);
	if ((int32_t)A2 >= 0)
	{
		V0 = -A2;
		ZZ_CLOCKCYCLES(10,0x8001A6E0);
		goto ZZ_1A5DC_104;
	}
	V0 = -A2;
	EMU_Write32(S1,V0);
	ZZ_CLOCKCYCLES(11,0x8001A6E0);
ZZ_1A5DC_104:
	A0 = EMU_ReadU32(SP + 40); //+ 0x28
	A1 = EMU_ReadU32(A0 + 28); //+ 0x1C
	V0 = EMU_ReadU32(A0 + 40); //+ 0x28
	A1 += V0;
	EMU_Write32(SP + 16,A1); //+ 0x10
	V0 = EMU_ReadU32(A0 + 32); //+ 0x20
	V1 = EMU_ReadU32(A0 + 44); //+ 0x2C
	V0 += V1;
	EMU_Write32(SP + 20,V0); //+ 0x14
	V0 = EMU_ReadU32(A0 + 36); //+ 0x24
	V1 = EMU_ReadU32(A0 + 48); //+ 0x30
	V0 += V1;
	EMU_Write32(SP + 24,V0); //+ 0x18
	V0 = EMU_ReadU32(A0 + 28); //+ 0x1C
	V1 = EMU_ReadU32(A0 + 52); //+ 0x34
	V0 += V1;
	EMU_Write32(SP + 28,V0); //+ 0x1C
	V0 = EMU_ReadU32(A0 + 32); //+ 0x20
	V1 = EMU_ReadU32(A0 + 56); //+ 0x38
	V0 += V1;
	EMU_Write32(SP + 32,V0); //+ 0x20
	V0 = EMU_ReadU32(A0 + 36); //+ 0x24
	V1 = EMU_ReadU32(A0 + 60); //+ 0x3C
	V0 += V1;
	EMU_Write32(SP + 36,V0); //+ 0x24
	V0 = EMU_ReadU32(S1);
	A1 = (int32_t)A1 >> 8;
	EMU_SMultiply(A1,V0);
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	A3 = LO;
	V0 = (int32_t)A3 >> 4;
	EMU_Write32(V1 + 48,V0); //+ 0x30
	V0 = EMU_ReadU32(SP + 20); //+ 0x14
	V1 = EMU_ReadU32(S1 + 4); //+ 0x4
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,V1);
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	A3 = LO;
	V0 = (int32_t)A3 >> 4;
	EMU_Write32(V1 + 52,V0); //+ 0x34
	V0 = EMU_ReadU32(SP + 24); //+ 0x18
	V1 = EMU_ReadU32(S1 + 8); //+ 0x8
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,V1);
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	A3 = LO;
	V0 = (int32_t)A3 >> 4;
	EMU_Write32(V1 + 56,V0); //+ 0x38
	V0 = EMU_ReadU32(SP + 28); //+ 0x1C
	V1 = EMU_ReadU32(S1);
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,V1);
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	A3 = LO;
	V0 = (int32_t)A3 >> 4;
	EMU_Write32(V1 + 60,V0); //+ 0x3C
	V0 = EMU_ReadU32(SP + 32); //+ 0x20
	V1 = EMU_ReadU32(S1 + 4); //+ 0x4
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,V1);
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	A3 = LO;
	V0 = (int32_t)A3 >> 4;
	EMU_Write32(V1 + 64,V0); //+ 0x40
	V0 = EMU_ReadU32(SP + 36); //+ 0x24
	V1 = EMU_ReadU32(S1 + 8); //+ 0x8
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,V1);
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	A3 = LO;
	V0 = (int32_t)A3 >> 4;
	EMU_Write32(V1 + 68,V0); //+ 0x44
	EMU_Write32(S1,A2);
	ZZ_CLOCKCYCLES(81,0x8001A830);
	goto ZZ_1A5DC_254;
ZZ_1A5DC_248:
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	EMU_Write32(V1 + 40,V0); //+ 0x28
	ZZ_CLOCKCYCLES(3,0x8001A830);
ZZ_1A5DC_254:
	RA = EMU_ReadU32(SP + 56); //+ 0x38
	S1 = EMU_ReadU32(SP + 52); //+ 0x34
	S0 = EMU_ReadU32(SP + 48); //+ 0x30
	SP += 64;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(6);
	ZZ_JUMPREGISTER(0x800382B0,ZZ_37930_980);
	ZZ_JUMPREGISTER(0x8001E008,ZZ_1D860_7A8);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x8001A5DC,0x8001A63C,ZZ_1A5DC);
ZZ_MARK_TARGET(0x8001A63C,0x8001A660,ZZ_1A5DC_60);
ZZ_MARK_TARGET(0x8001A660,0x8001A68C,ZZ_1A5DC_84);
ZZ_MARK_TARGET(0x8001A68C,0x8001A6B4,ZZ_1A5DC_B0);
ZZ_MARK_TARGET(0x8001A6B4,0x8001A6E0,ZZ_1A5DC_D8);
ZZ_MARK_TARGET(0x8001A6E0,0x8001A824,ZZ_1A5DC_104);
ZZ_MARK_TARGET(0x8001A824,0x8001A830,ZZ_1A5DC_248);
ZZ_MARK_TARGET(0x8001A830,0x8001A848,ZZ_1A5DC_254);
