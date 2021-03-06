#ifdef ZZ_INCLUDE_CODE
ZZ_2F658:
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 + 2916); //+ 0xB64
	SP -= 56;
	EMU_Write32(SP + 52,RA); //+ 0x34
	EMU_Write32(SP + 48,S4); //+ 0x30
	EMU_Write32(SP + 44,S3); //+ 0x2C
	EMU_Write32(SP + 40,S2); //+ 0x28
	EMU_Write32(SP + 36,S1); //+ 0x24
	EMU_Write32(SP + 32,S0); //+ 0x20
	V0 = EMU_ReadU32(V0 + 16); //+ 0x10
	S1 = A0;
	V0 = EMU_ReadU32(V0 + 668); //+ 0x29C
	S0 = A1;
	S2 = A2;
	V0 &= 0x2000;
	if (V0)
	{
		S3 = A3;
		ZZ_CLOCKCYCLES(17,0x8002F9B0);
		goto ZZ_2F658_358;
	}
	S3 = A3;
	V0 = 0x80060000;
	V0 += 7248;
	V0 ^= S0;
	if (S3)
	{
		S4 = V0 < 1;
		ZZ_CLOCKCYCLES(22,0x8002F900);
		goto ZZ_2F658_2A8;
	}
	S4 = V0 < 1;
	A1 = 0x80060000;
	A1 = EMU_ReadU32(A1 - 2524); //+ 0xFFFFF624
	A2 = 0x4400;
	A3 = R0;
	RA = 0x8002F6C8; //ZZ_2F658_70
	EMU_Write32(SP + 16,R0); //+ 0x10
	ZZ_CLOCKCYCLES(28,0x8001CD48);
	goto ZZ_1CD48;
ZZ_2F658_70:
	if (!S2)
	{
		ZZ_CLOCKCYCLES(2,0x8002F6E8);
		goto ZZ_2F658_90;
	}
	AT = 0x80070000;
	EMU_Write32(AT - 12648,R0); //+ 0xFFFFCE98
	AT = 0x80070000;
	EMU_Write32(AT - 12544,R0); //+ 0xFFFFCF00
	ZZ_CLOCKCYCLES(8,0x8002F700);
	goto ZZ_2F658_A8;
ZZ_2F658_90:
	V1 = 0x80070000;
	V1 -= 12648;
	V0 = EMU_ReadU32(V1);
	V0 += 256;
	EMU_Write32(V1,V0);
	ZZ_CLOCKCYCLES(6,0x8002F700);
ZZ_2F658_A8:
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 - 2524); //+ 0xFFFFF624
	A3 = S0;
	EMU_Write32(S0 + 52,S2); //+ 0x34
	A2 = V0 + 96;
	T0 = V0 + 128;
	ZZ_CLOCKCYCLES(6,0x8002F718);
ZZ_2F658_C0:
	V0 = EMU_ReadU32(A2);
	V1 = EMU_ReadU32(A2 + 4); //+ 0x4
	A0 = EMU_ReadU32(A2 + 8); //+ 0x8
	A1 = EMU_ReadU32(A2 + 12); //+ 0xC
	EMU_Write32(A3,V0);
	EMU_Write32(A3 + 4,V1); //+ 0x4
	EMU_Write32(A3 + 8,A0); //+ 0x8
	EMU_Write32(A3 + 12,A1); //+ 0xC
	A2 += 16;
	if (A2 != T0)
	{
		A3 += 16;
		ZZ_CLOCKCYCLES(11,0x8002F718);
		goto ZZ_2F658_C0;
	}
	A3 += 16;
	V0 = EMU_ReadU32(A2);
	EMU_Write32(A3,V0);
	V0 = EMU_ReadU8(S1 + 288); //+ 0x120
	V0 -= 6;
	V0 = V0 < 2;
	if (V0)
	{
		ZZ_CLOCKCYCLES(20,0x8002F780);
		goto ZZ_2F658_128;
	}
	V0 = EMU_ReadU32(S1 + 96); //+ 0x60
	V1 = EMU_ReadU32(S1 + 100); //+ 0x64
	A0 = EMU_ReadU32(S1 + 104); //+ 0x68
	EMU_Write32(S0,V0);
	EMU_Write32(S0 + 4,V1); //+ 0x4
	EMU_Write32(S0 + 8,A0); //+ 0x8
	ZZ_CLOCKCYCLES(26,0x8002F780);
ZZ_2F658_128:
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 12516); //+ 0xFFFFCF1C
	if ((int32_t)V0 < 0)
	{
		ZZ_CLOCKCYCLES(5,0x8002F7BC);
		goto ZZ_2F658_164;
	}
	if (!V0)
	{
		ZZ_CLOCKCYCLES(7,0x8002F7BC);
		goto ZZ_2F658_164;
	}
	A1 = 0x80070000;
	A1 -= 12384;
	V0 = EMU_ReadU32(A1);
	V1 = EMU_ReadU32(A1 + 4); //+ 0x4
	A0 = EMU_ReadU32(A1 + 8); //+ 0x8
	EMU_Write32(S0,V0);
	EMU_Write32(S0 + 4,V1); //+ 0x4
	EMU_Write32(S0 + 8,A0); //+ 0x8
	ZZ_CLOCKCYCLES(15,0x8002F7BC);
ZZ_2F658_164:
	EMU_Write32(S0 + 12,R0); //+ 0xC
	EMU_Write32(S0 + 16,R0); //+ 0x10
	EMU_Write32(S0 + 20,R0); //+ 0x14
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 + 2916); //+ 0xB64
	V0 = EMU_ReadU32(V0 + 4); //+ 0x4
	EMU_Write32(S0 + 36,V0); //+ 0x24
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 + 2936); //+ 0xB78
	EMU_Write32(S0 + 44,V0); //+ 0x2C
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 + 30772); //+ 0x7834
	V0 = EMU_ReadU32(V0 + 8); //+ 0x8
	A1 = 0x173;
	EMU_Write32(S0 + 48,V0); //+ 0x30
	A0 = 0x80060000;
	A0 = EMU_ReadU32(A0 + 2924); //+ 0xB6C
	A2 = R0;
	A3 = R0;
	S2 = 0x2;
	EMU_Write32(SP + 16,R0); //+ 0x10
	EMU_Write32(SP + 20,S2); //+ 0x14
	RA = 0x8002F82C; //ZZ_2F658_1D4
	EMU_Write32(SP + 24,R0); //+ 0x18
	ZZ_CLOCKCYCLES(28,0x800324E0);
	goto ZZ_324E0;
ZZ_2F658_1D4:
	EMU_Write32(S0 + 40,V0); //+ 0x28
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 12516); //+ 0xFFFFCF1C
	V0 = (int32_t)V0 < -1;
	if (V0)
	{
		V0 = -1;
		ZZ_CLOCKCYCLES(7,0x8002F8F4);
		goto ZZ_2F658_29C;
	}
	V0 = -1;
	V0 = EMU_ReadU32(S1 + 240); //+ 0xF0
	if (!V0)
	{
		ZZ_CLOCKCYCLES(11,0x8002F8F0);
		goto ZZ_2F658_298;
	}
	if (S4)
	{
		V0 = -1;
		ZZ_CLOCKCYCLES(13,0x8002F8F4);
		goto ZZ_2F658_29C;
	}
	V0 = -1;
	EMU_Write32(SP + 16,R0); //+ 0x10
	EMU_Write32(SP + 20,S2); //+ 0x14
	EMU_Write32(SP + 24,R0); //+ 0x18
	A0 = EMU_ReadU32(S1 + 240); //+ 0xF0
	A1 = 0x288;
	A2 = R0;
	RA = 0x8002F880; //ZZ_2F658_228
	A3 = R0;
	ZZ_CLOCKCYCLES(21,0x800324E0);
	goto ZZ_324E0;
ZZ_2F658_228:
	A0 = V0;
	if (!A0)
	{
		EMU_Write32(S0 + 56,A0); //+ 0x38
		ZZ_CLOCKCYCLES(3,0x8002F8F8);
		goto ZZ_2F658_2A0;
	}
	EMU_Write32(S0 + 56,A0); //+ 0x38
	V0 = EMU_ReadU32(S0 + 48); //+ 0x30
	A1 = A0;
	V1 = 0x80070000;
	V1 -= 26192;
	V0 <<= 3;
	if ((int32_t)A0 >= 0)
	{
		A2 = V0 + V1;
		ZZ_CLOCKCYCLES(10,0x8002F8AC);
		goto ZZ_2F658_254;
	}
	A2 = V0 + V1;
	A1 = A0 + 7;
	ZZ_CLOCKCYCLES(11,0x8002F8AC);
ZZ_2F658_254:
	V1 = (int32_t)A1 >> 3;
	V0 = V1 << 2;
	V0 += A2;
	V0 = EMU_ReadU32(V0);
	V1 <<= 3;
	V1 = A0 - V1;
	V1 <<= 2;
	V0 >>= V1;
	V0 &= 0xF;
	V0 <<= 8;
	AT = 0x80070000;
	EMU_Write32(AT - 12208,V0); //+ 0xFFFFD050
	V0 = EMU_ReadU32(S0 + 56); //+ 0x38
	AT = 0x80070000;
	EMU_Write32(AT - 12212,V0); //+ 0xFFFFD04C
	ZZ_CLOCKCYCLES(17,0x8002F8F8);
	goto ZZ_2F658_2A0;
ZZ_2F658_298:
	V0 = -1;
	ZZ_CLOCKCYCLES(1,0x8002F8F4);
ZZ_2F658_29C:
	EMU_Write32(S0 + 56,V0); //+ 0x38
	ZZ_CLOCKCYCLES(1,0x8002F8F8);
ZZ_2F658_2A0:
	RA = 0x8002F900; //ZZ_2F658_2A8
	A0 = S0 + 4160;
	ZZ_CLOCKCYCLES(2,0x8001473C);
	goto ZZ_1473C;
ZZ_2F658_2A8:
	V0 = 0x2;
	if (S3 != V0)
	{
		A2 = R0;
		ZZ_CLOCKCYCLES(3,0x8002F96C);
		goto ZZ_2F658_314;
	}
	A2 = R0;
	V0 = EMU_ReadU32(S0 + 4156); //+ 0x103C
	V1 = 0x80070000;
	V1 = EMU_ReadU32(V1 - 12544); //+ 0xFFFFCF00
	T0 = 0x80070000;
	T0 -= 19364;
	A3 = S0 + 4192;
	A1 = S0;
	V0 += V1;
	EMU_Write32(S0 + 4156,V0); //+ 0x103C
	ZZ_CLOCKCYCLES(12,0x8002F930);
ZZ_2F658_2D8:
	A0 = EMU_ReadU32(T0);
	T0 += 4;
	V0 = EMU_ReadU32(A3 + 60); //+ 0x3C
	A3 += 4;
	V1 = EMU_ReadU32(A1 + 60); //+ 0x3C
	A2 += 1;
	V0 = ~V0;
	V0 &= A0;
	V1 |= V0;
	EMU_Write32(A1 + 60,V1); //+ 0x3C
	V0 = A2 < 1024;
	if (V0)
	{
		A1 += 4;
		ZZ_CLOCKCYCLES(13,0x8002F930);
		goto ZZ_2F658_2D8;
	}
	A1 += 4;
	V0 = 0x2;
	ZZ_CLOCKCYCLES(15,0x8002F980);
	goto ZZ_2F658_328;
ZZ_2F658_314:
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 12544); //+ 0xFFFFCF00
	EMU_Write32(S0 + 4156,V0); //+ 0x103C
	V0 = 0x2;
	ZZ_CLOCKCYCLES(5,0x8002F980);
ZZ_2F658_328:
	if (S3 == V0)
	{
		A2 = R0;
		ZZ_CLOCKCYCLES(2,0x8002F9B0);
		goto ZZ_2F658_358;
	}
	A2 = R0;
	V1 = 0x80070000;
	V1 -= 19364;
	A1 = S0;
	ZZ_CLOCKCYCLES(5,0x8002F994);
ZZ_2F658_33C:
	V0 = EMU_ReadU32(V1);
	V1 += 4;
	A2 += 1;
	EMU_Write32(A1 + 60,V0); //+ 0x3C
	V0 = A2 < 1024;
	if (V0)
	{
		A1 += 4;
		ZZ_CLOCKCYCLES(7,0x8002F994);
		goto ZZ_2F658_33C;
	}
	A1 += 4;
	ZZ_CLOCKCYCLES(7,0x8002F9B0);
ZZ_2F658_358:
	RA = EMU_ReadU32(SP + 52); //+ 0x34
	S4 = EMU_ReadU32(SP + 48); //+ 0x30
	S3 = EMU_ReadU32(SP + 44); //+ 0x2C
	S2 = EMU_ReadU32(SP + 40); //+ 0x28
	S1 = EMU_ReadU32(SP + 36); //+ 0x24
	S0 = EMU_ReadU32(SP + 32); //+ 0x20
	SP += 56;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(9);
	ZZ_JUMPREGISTER(0x80037F44,ZZ_37930_614);
	ZZ_JUMPREGISTER(0x80020BC0,ZZ_20304_8BC);
	ZZ_JUMPREGISTER(0x80019838,ZZ_191D4_664);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x8002F658,0x8002F6C8,ZZ_2F658);
ZZ_MARK_TARGET(0x8002F6C8,0x8002F6E8,ZZ_2F658_70);
ZZ_MARK_TARGET(0x8002F6E8,0x8002F700,ZZ_2F658_90);
ZZ_MARK_TARGET(0x8002F700,0x8002F718,ZZ_2F658_A8);
ZZ_MARK_TARGET(0x8002F718,0x8002F780,ZZ_2F658_C0);
ZZ_MARK_TARGET(0x8002F780,0x8002F7BC,ZZ_2F658_128);
ZZ_MARK_TARGET(0x8002F7BC,0x8002F82C,ZZ_2F658_164);
ZZ_MARK_TARGET(0x8002F82C,0x8002F880,ZZ_2F658_1D4);
ZZ_MARK_TARGET(0x8002F880,0x8002F8AC,ZZ_2F658_228);
ZZ_MARK_TARGET(0x8002F8AC,0x8002F8F0,ZZ_2F658_254);
ZZ_MARK_TARGET(0x8002F8F0,0x8002F8F4,ZZ_2F658_298);
ZZ_MARK_TARGET(0x8002F8F4,0x8002F8F8,ZZ_2F658_29C);
ZZ_MARK_TARGET(0x8002F8F8,0x8002F900,ZZ_2F658_2A0);
ZZ_MARK_TARGET(0x8002F900,0x8002F930,ZZ_2F658_2A8);
ZZ_MARK_TARGET(0x8002F930,0x8002F96C,ZZ_2F658_2D8);
ZZ_MARK_TARGET(0x8002F96C,0x8002F980,ZZ_2F658_314);
ZZ_MARK_TARGET(0x8002F980,0x8002F994,ZZ_2F658_328);
ZZ_MARK_TARGET(0x8002F994,0x8002F9B0,ZZ_2F658_33C);
ZZ_MARK_TARGET(0x8002F9B0,0x8002F9D4,ZZ_2F658_358);
