#ifdef ZZ_INCLUDE_CODE
ZZ_30CB4:
	SP -= 120;
	EMU_Write32(SP + 108,S3); //+ 0x6C
	S3 = A0;
	EMU_Write32(SP + 96,S0); //+ 0x60
	S0 = A1;
	EMU_Write32(SP + 112,RA); //+ 0x70
	EMU_Write32(SP + 104,S2); //+ 0x68
	EMU_Write32(SP + 100,S1); //+ 0x64
	A0 = EMU_ReadU32(S0);
	V0 = EMU_ReadU32(S0 + 12); //+ 0xC
	A0 += V0;
	A0 = (int32_t)A0 >> 1;
	EMU_Write32(SP + 32,A0); //+ 0x20
	V0 = EMU_ReadU32(S0 + 4); //+ 0x4
	V1 = EMU_ReadU32(S0 + 16); //+ 0x10
	V0 += V1;
	A1 = (int32_t)V0 >> 1;
	EMU_Write32(SP + 36,A1); //+ 0x24
	V0 = EMU_ReadU32(S0 + 8); //+ 0x8
	V1 = EMU_ReadU32(S0 + 20); //+ 0x14
	S1 = A2;
	S2 = A3;
	V0 += V1;
	V1 = (int32_t)V0 >> 1;
	if ((int32_t)A0 >= 0)
	{
		EMU_Write32(SP + 40,V1); //+ 0x28
		ZZ_CLOCKCYCLES(28,0x80030D28);
		goto ZZ_30CB4_74;
	}
	EMU_Write32(SP + 40,V1); //+ 0x28
	A0 += 15;
	ZZ_CLOCKCYCLES(29,0x80030D28);
ZZ_30CB4_74:
	V0 = (int32_t)A0 >> 4;
	EMU_Write32(SP + 32,V0); //+ 0x20
	V0 = A1;
	if ((int32_t)V0 >= 0)
	{
		ZZ_CLOCKCYCLES(5,0x80030D40);
		goto ZZ_30CB4_8C;
	}
	V0 += 15;
	ZZ_CLOCKCYCLES(6,0x80030D40);
ZZ_30CB4_8C:
	V0 = (int32_t)V0 >> 4;
	EMU_Write32(SP + 36,V0); //+ 0x24
	V0 = V1;
	if ((int32_t)V0 >= 0)
	{
		ZZ_CLOCKCYCLES(5,0x80030D58);
		goto ZZ_30CB4_A4;
	}
	V0 += 15;
	ZZ_CLOCKCYCLES(6,0x80030D58);
ZZ_30CB4_A4:
	V0 = (int32_t)V0 >> 4;
	A0 = SP + 32;
	A1 = S1;
	A2 = SP + 16;
	RA = 0x80030D70; //ZZ_30CB4_BC
	EMU_Write32(SP + 40,V0); //+ 0x28
	ZZ_CLOCKCYCLES(6,0x800182B8);
	goto ZZ_182B8;
ZZ_30CB4_BC:
	A0 = EMU_ReadU32(SP + 16); //+ 0x10
	V1 = EMU_ReadU32(SP + 20); //+ 0x14
	A1 = EMU_ReadU32(SP + 24); //+ 0x18
	A0 <<= 4;
	V1 <<= 4;
	A1 <<= 4;
	EMU_Write32(SP + 16,A0); //+ 0x10
	EMU_Write32(SP + 20,V1); //+ 0x14
	EMU_Write32(SP + 24,A1); //+ 0x18
	V0 = EMU_ReadU32(S2);
	A2 = A0 + V0;
	EMU_Write32(SP + 16,A2); //+ 0x10
	V0 = EMU_ReadU32(S2 + 4); //+ 0x4
	V1 += V0;
	EMU_Write32(SP + 20,V1); //+ 0x14
	V0 = EMU_ReadU32(S2 + 8); //+ 0x8
	A1 += V0;
	EMU_Write32(SP + 24,A1); //+ 0x18
	V0 = EMU_ReadU32(S0 + 12); //+ 0xC
	V1 = EMU_ReadU32(S0);
	A0 = EMU_ReadS16(S1);
	V0 = V0 - V1;
	A1 = (int32_t)V0 >> 2;
	EMU_SMultiply(A1,A0);
	T0 = LO;
	V0 = (int32_t)T0 >> 12;
	if ((int32_t)V0 >= 0)
	{
		EMU_Write32(SP + 48,V0); //+ 0x30
		ZZ_CLOCKCYCLES(31,0x80030DF4);
		goto ZZ_30CB4_140;
	}
	EMU_Write32(SP + 48,V0); //+ 0x30
	V0 = -V0;
	EMU_Write32(SP + 48,V0); //+ 0x30
	ZZ_CLOCKCYCLES(33,0x80030DF4);
ZZ_30CB4_140:
	V0 = EMU_ReadS16(S1 + 6); //+ 0x6
	EMU_SMultiply(A1,V0);
	T0 = LO;
	V0 = (int32_t)T0 >> 12;
	if ((int32_t)V0 >= 0)
	{
		EMU_Write32(SP + 52,V0); //+ 0x34
		ZZ_CLOCKCYCLES(7,0x80030E18);
		goto ZZ_30CB4_164;
	}
	EMU_Write32(SP + 52,V0); //+ 0x34
	V0 = -V0;
	EMU_Write32(SP + 52,V0); //+ 0x34
	ZZ_CLOCKCYCLES(9,0x80030E18);
ZZ_30CB4_164:
	V0 = EMU_ReadS16(S1 + 12); //+ 0xC
	EMU_SMultiply(A1,V0);
	T0 = LO;
	V0 = (int32_t)T0 >> 12;
	if ((int32_t)V0 >= 0)
	{
		EMU_Write32(SP + 56,V0); //+ 0x38
		ZZ_CLOCKCYCLES(7,0x80030E3C);
		goto ZZ_30CB4_188;
	}
	EMU_Write32(SP + 56,V0); //+ 0x38
	V0 = -V0;
	EMU_Write32(SP + 56,V0); //+ 0x38
	ZZ_CLOCKCYCLES(9,0x80030E3C);
ZZ_30CB4_188:
	V0 = EMU_ReadU32(S0 + 16); //+ 0x10
	V1 = EMU_ReadU32(S0 + 4); //+ 0x4
	A0 = EMU_ReadS16(S1 + 2); //+ 0x2
	V0 = V0 - V1;
	A1 = (int32_t)V0 >> 2;
	EMU_SMultiply(A1,A0);
	T0 = LO;
	V0 = (int32_t)T0 >> 12;
	if ((int32_t)V0 >= 0)
	{
		EMU_Write32(SP + 64,V0); //+ 0x40
		ZZ_CLOCKCYCLES(10,0x80030E6C);
		goto ZZ_30CB4_1B8;
	}
	EMU_Write32(SP + 64,V0); //+ 0x40
	V0 = -V0;
	EMU_Write32(SP + 64,V0); //+ 0x40
	ZZ_CLOCKCYCLES(12,0x80030E6C);
ZZ_30CB4_1B8:
	V0 = EMU_ReadS16(S1 + 8); //+ 0x8
	EMU_SMultiply(A1,V0);
	T0 = LO;
	V0 = (int32_t)T0 >> 12;
	if ((int32_t)V0 >= 0)
	{
		EMU_Write32(SP + 68,V0); //+ 0x44
		ZZ_CLOCKCYCLES(7,0x80030E90);
		goto ZZ_30CB4_1DC;
	}
	EMU_Write32(SP + 68,V0); //+ 0x44
	V0 = -V0;
	EMU_Write32(SP + 68,V0); //+ 0x44
	ZZ_CLOCKCYCLES(9,0x80030E90);
ZZ_30CB4_1DC:
	V0 = EMU_ReadS16(S1 + 14); //+ 0xE
	EMU_SMultiply(A1,V0);
	T0 = LO;
	V0 = (int32_t)T0 >> 12;
	if ((int32_t)V0 >= 0)
	{
		EMU_Write32(SP + 72,V0); //+ 0x48
		ZZ_CLOCKCYCLES(7,0x80030EB4);
		goto ZZ_30CB4_200;
	}
	EMU_Write32(SP + 72,V0); //+ 0x48
	V0 = -V0;
	EMU_Write32(SP + 72,V0); //+ 0x48
	ZZ_CLOCKCYCLES(9,0x80030EB4);
ZZ_30CB4_200:
	V0 = EMU_ReadU32(S0 + 20); //+ 0x14
	V1 = EMU_ReadU32(S0 + 8); //+ 0x8
	A0 = EMU_ReadS16(S1 + 4); //+ 0x4
	V0 = V0 - V1;
	A1 = (int32_t)V0 >> 2;
	EMU_SMultiply(A1,A0);
	T0 = LO;
	V0 = (int32_t)T0 >> 12;
	if ((int32_t)V0 >= 0)
	{
		EMU_Write32(SP + 80,V0); //+ 0x50
		ZZ_CLOCKCYCLES(10,0x80030EE4);
		goto ZZ_30CB4_230;
	}
	EMU_Write32(SP + 80,V0); //+ 0x50
	V0 = -V0;
	EMU_Write32(SP + 80,V0); //+ 0x50
	ZZ_CLOCKCYCLES(12,0x80030EE4);
ZZ_30CB4_230:
	V0 = EMU_ReadS16(S1 + 10); //+ 0xA
	EMU_SMultiply(A1,V0);
	T0 = LO;
	V0 = (int32_t)T0 >> 12;
	if ((int32_t)V0 >= 0)
	{
		EMU_Write32(SP + 84,V0); //+ 0x54
		ZZ_CLOCKCYCLES(7,0x80030F08);
		goto ZZ_30CB4_254;
	}
	EMU_Write32(SP + 84,V0); //+ 0x54
	V0 = -V0;
	EMU_Write32(SP + 84,V0); //+ 0x54
	ZZ_CLOCKCYCLES(9,0x80030F08);
ZZ_30CB4_254:
	V0 = EMU_ReadS16(S1 + 16); //+ 0x10
	EMU_SMultiply(A1,V0);
	T0 = LO;
	V0 = (int32_t)T0 >> 12;
	if ((int32_t)V0 >= 0)
	{
		EMU_Write32(SP + 88,V0); //+ 0x58
		ZZ_CLOCKCYCLES(7,0x80030F2C);
		goto ZZ_30CB4_278;
	}
	EMU_Write32(SP + 88,V0); //+ 0x58
	V0 = -V0;
	EMU_Write32(SP + 88,V0); //+ 0x58
	ZZ_CLOCKCYCLES(9,0x80030F2C);
ZZ_30CB4_278:
	V0 = EMU_ReadU32(SP + 48); //+ 0x30
	V1 = EMU_ReadU32(SP + 64); //+ 0x40
	A0 = EMU_ReadU32(SP + 80); //+ 0x50
	V0 += V1;
	V0 += A0;
	A1 = V0 << 1;
	V0 = A2 + A1;
	EMU_Write32(S3 + 12,V0); //+ 0xC
	V0 = EMU_ReadU32(SP + 16); //+ 0x10
	V0 = V0 - A1;
	EMU_Write32(S3,V0);
	V0 = EMU_ReadU32(SP + 52); //+ 0x34
	A0 = EMU_ReadU32(SP + 68); //+ 0x44
	A1 = EMU_ReadU32(SP + 84); //+ 0x54
	V1 = EMU_ReadU32(SP + 20); //+ 0x14
	V0 += A0;
	V0 += A1;
	A1 = V0 << 1;
	V1 += A1;
	EMU_Write32(S3 + 16,V1); //+ 0x10
	V0 = EMU_ReadU32(SP + 20); //+ 0x14
	V0 = V0 - A1;
	EMU_Write32(S3 + 4,V0); //+ 0x4
	V0 = EMU_ReadU32(SP + 56); //+ 0x38
	A0 = EMU_ReadU32(SP + 72); //+ 0x48
	A1 = EMU_ReadU32(SP + 88); //+ 0x58
	V1 = EMU_ReadU32(SP + 24); //+ 0x18
	V0 += A0;
	V0 += A1;
	A1 = V0 << 1;
	V1 += A1;
	EMU_Write32(S3 + 20,V1); //+ 0x14
	V0 = EMU_ReadU32(SP + 24); //+ 0x18
	V0 = V0 - A1;
	EMU_Write32(S3 + 8,V0); //+ 0x8
	RA = EMU_ReadU32(SP + 112); //+ 0x70
	S3 = EMU_ReadU32(SP + 108); //+ 0x6C
	S2 = EMU_ReadU32(SP + 104); //+ 0x68
	S1 = EMU_ReadU32(SP + 100); //+ 0x64
	S0 = EMU_ReadU32(SP + 96); //+ 0x60
	SP += 120;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(46);
	ZZ_JUMPREGISTER(0x8002C90C,ZZ_2C638_2D4);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80030CB4,0x80030D28,ZZ_30CB4);
ZZ_MARK_TARGET(0x80030D28,0x80030D40,ZZ_30CB4_74);
ZZ_MARK_TARGET(0x80030D40,0x80030D58,ZZ_30CB4_8C);
ZZ_MARK_TARGET(0x80030D58,0x80030D70,ZZ_30CB4_A4);
ZZ_MARK_TARGET(0x80030D70,0x80030DF4,ZZ_30CB4_BC);
ZZ_MARK_TARGET(0x80030DF4,0x80030E18,ZZ_30CB4_140);
ZZ_MARK_TARGET(0x80030E18,0x80030E3C,ZZ_30CB4_164);
ZZ_MARK_TARGET(0x80030E3C,0x80030E6C,ZZ_30CB4_188);
ZZ_MARK_TARGET(0x80030E6C,0x80030E90,ZZ_30CB4_1B8);
ZZ_MARK_TARGET(0x80030E90,0x80030EB4,ZZ_30CB4_1DC);
ZZ_MARK_TARGET(0x80030EB4,0x80030EE4,ZZ_30CB4_200);
ZZ_MARK_TARGET(0x80030EE4,0x80030F08,ZZ_30CB4_230);
ZZ_MARK_TARGET(0x80030F08,0x80030F2C,ZZ_30CB4_254);
ZZ_MARK_TARGET(0x80030F2C,0x80030FE4,ZZ_30CB4_278);
