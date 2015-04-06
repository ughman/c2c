#ifdef ZZ_INCLUDE_CODE
ZZ_2C638:
	SP -= 128;
	EMU_Write32(SP + 100,S1); //+ 0x64
	S1 = A0;
	EMU_Write32(SP + 108,S3); //+ 0x6C
	S3 = A2;
	V0 = -2;
	EMU_Write32(SP + 120,RA); //+ 0x78
	EMU_Write32(SP + 116,S5); //+ 0x74
	EMU_Write32(SP + 112,S4); //+ 0x70
	EMU_Write32(SP + 104,S2); //+ 0x68
	if (S3 != V0)
	{
		EMU_Write32(SP + 96,S0); //+ 0x60
		ZZ_CLOCKCYCLES(12,0x8002C68C);
		goto ZZ_2C638_54;
	}
	EMU_Write32(SP + 96,S0); //+ 0x60
	V0 = EMU_ReadU32(S1 + 232); //+ 0xE8
	if (!V0)
	{
		ZZ_CLOCKCYCLES(16,0x8002C68C);
		goto ZZ_2C638_54;
	}
	V1 = EMU_ReadU8(V0);
	V0 = 0x1;
	if (V1 != V0)
	{
		ZZ_CLOCKCYCLES(20,0x8002C68C);
		goto ZZ_2C638_54;
	}
	S3 = R0;
	ZZ_CLOCKCYCLES(21,0x8002C68C);
ZZ_2C638_54:
	if ((int32_t)S3 >= 0)
	{
		S5 = R0;
		ZZ_CLOCKCYCLES(2,0x8002C69C);
		goto ZZ_2C638_64;
	}
	S5 = R0;
	S2 = R0;
	ZZ_CLOCKCYCLES(4,0x8002C6E4);
	goto ZZ_2C638_AC;
ZZ_2C638_64:
	V0 = EMU_ReadU32(S1 + 8); //+ 0x8
	S5 = EMU_ReadU32(V0 + 32); //+ 0x20
	V0 = EMU_ReadU32(S5 + 12); //+ 0xC
	V0 = S3 < V0;
	if (V0)
	{
		V0 = S3 << 2;
		ZZ_CLOCKCYCLES(9,0x8002C6C8);
		goto ZZ_2C638_90;
	}
	V0 = S3 << 2;
	V0 = R0;
	ZZ_CLOCKCYCLES(11,0x8002CD08);
	goto ZZ_2C638_6D0;
ZZ_2C638_90:
	V0 += S3;
	V0 <<= 3;
	V0 += 24;
	S4 = S5 + V0;
	V0 = EMU_ReadU32(S4);
	S2 = V0 & 0x7;
	ZZ_CLOCKCYCLES(7,0x8002C6E4);
ZZ_2C638_AC:
	S0 = 0x80070000;
	S0 -= 12796;
	V0 = EMU_ReadU32(S0);
	V0 = (int32_t)V0 < 96;
	if (V0)
	{
		A2 = S0 - 4;
		ZZ_CLOCKCYCLES(7,0x8002C70C);
		goto ZZ_2C638_D4;
	}
	A2 = S0 - 4;
	RA = 0x8002C708; //ZZ_2C638_D0
	ZZ_CLOCKCYCLES(9,0x8002CD30);
	goto ZZ_2CD30;
ZZ_2C638_D0:
	A2 = S0 - 4;
	ZZ_CLOCKCYCLES(1,0x8002C70C);
ZZ_2C638_D4:
	A1 = 0x1;
	A0 = S0 + 5136;
	A3 = S0 + 656;
	ZZ_CLOCKCYCLES(3,0x8002C718);
ZZ_2C638_E0:
	S0 = EMU_ReadU32(A2);
	if (!S2)
	{
		V1 = S0 + 32;
		ZZ_CLOCKCYCLES(3,0x8002C738);
		goto ZZ_2C638_100;
	}
	V1 = S0 + 32;
	if (S2 != A1)
	{
		ZZ_CLOCKCYCLES(5,0x8002C734);
		goto ZZ_2C638_FC;
	}
	V1 = S0 + 68;
	ZZ_CLOCKCYCLES(7,0x8002C738);
	goto ZZ_2C638_100;
ZZ_2C638_FC:
	S2 = R0;
	ZZ_CLOCKCYCLES(1,0x8002C738);
ZZ_2C638_100:
	V0 = V1 < A0;
	if (!V0)
	{
		ZZ_CLOCKCYCLES(3,0x8002C718);
		goto ZZ_2C638_E0;
	}
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 12796); //+ 0xFFFFCE04
	EMU_Write32(A0 - 5140,V1); //+ 0xFFFFEBEC
	V0 <<= 2;
	V0 += A3;
	EMU_Write32(V0,S0);
	V0 = EMU_ReadU32(A0 - 5136); //+ 0xFFFFEBF0
	V0 += 1;
	EMU_Write32(A0 - 5136,V0); //+ 0xFFFFEBF0
	EMU_Write32(S0 + 4,S1); //+ 0x4
	if (S5)
	{
		EMU_Write32(S0,S2);
		ZZ_CLOCKCYCLES(16,0x8002C884);
		goto ZZ_2C638_24C;
	}
	EMU_Write32(S0,S2);
	V1 = EMU_ReadU32(S1 + 120); //+ 0x78
	A0 = EMU_ReadU32(S1 + 96); //+ 0x60
	if ((int32_t)V1 >= 0)
	{
		ZZ_CLOCKCYCLES(20,0x8002C78C);
		goto ZZ_2C638_154;
	}
	V1 = -V1;
	ZZ_CLOCKCYCLES(21,0x8002C78C);
ZZ_2C638_154:
	V0 = V1 << 1;
	V0 += V1;
	V0 <<= 3;
	V0 += V1;
	V0 <<= 3;
	V0 = (int32_t)V0 >> 4;
	A0 = A0 - V0;
	EMU_Write32(S0 + 8,A0); //+ 0x8
	V1 = EMU_ReadU32(S1 + 120); //+ 0x78
	A0 = EMU_ReadU32(S1 + 96); //+ 0x60
	if ((int32_t)V1 >= 0)
	{
		ZZ_CLOCKCYCLES(12,0x8002C7C0);
		goto ZZ_2C638_188;
	}
	V1 = -V1;
	ZZ_CLOCKCYCLES(13,0x8002C7C0);
ZZ_2C638_188:
	V0 = V1 << 1;
	V0 += V1;
	V0 <<= 3;
	V0 += V1;
	V0 <<= 3;
	V0 = (int32_t)V0 >> 4;
	A0 += V0;
	EMU_Write32(S0 + 20,A0); //+ 0x14
	V1 = EMU_ReadU32(S1 + 124); //+ 0x7C
	A0 = EMU_ReadU32(S1 + 100); //+ 0x64
	V0 = V1 << 1;
	V0 += V1;
	V0 <<= 3;
	V0 += V1;
	V0 <<= 3;
	V0 = (int32_t)V0 >> 4;
	A0 = A0 - V0;
	EMU_Write32(S0 + 12,A0); //+ 0xC
	V1 = EMU_ReadU32(S1 + 124); //+ 0x7C
	A0 = EMU_ReadU32(S1 + 100); //+ 0x64
	V0 = V1 << 1;
	V0 += V1;
	V0 <<= 3;
	V0 += V1;
	V0 <<= 3;
	V0 = (int32_t)V0 >> 4;
	A0 += V0;
	EMU_Write32(S0 + 24,A0); //+ 0x18
	V1 = EMU_ReadU32(S1 + 128); //+ 0x80
	A0 = EMU_ReadU32(S1 + 104); //+ 0x68
	V0 = V1 << 1;
	V0 += V1;
	V0 <<= 3;
	V0 += V1;
	V0 <<= 3;
	V0 = (int32_t)V0 >> 4;
	A0 = A0 - V0;
	EMU_Write32(S0 + 16,A0); //+ 0x10
	V1 = EMU_ReadU32(S1 + 128); //+ 0x80
	A0 = EMU_ReadU32(S1 + 104); //+ 0x68
	V0 = V1 << 1;
	V0 += V1;
	V0 <<= 3;
	V0 += V1;
	V0 <<= 3;
	V0 = (int32_t)V0 >> 4;
	A0 += V0;
	EMU_Write32(S0 + 28,A0); //+ 0x1C
	ZZ_CLOCKCYCLES(49,0x8002CD04);
	goto ZZ_2C638_6CC;
ZZ_2C638_24C:
	if (!S2)
	{
		V0 = 0x1;
		ZZ_CLOCKCYCLES(2,0x8002C914);
		goto ZZ_2C638_2DC;
	}
	V0 = 0x1;
	if (S2 != V0)
	{
		V0 = S0;
		ZZ_CLOCKCYCLES(4,0x8002CD08);
		goto ZZ_2C638_6D0;
	}
	V0 = S0;
	V0 = S3 << 2;
	V0 += S3;
	V0 <<= 3;
	V0 += S5;
	V1 = EMU_ReadU32(V0 + 40); //+ 0x28
	A0 = EMU_ReadU32(V0 + 44); //+ 0x2C
	A1 = EMU_ReadU32(V0 + 48); //+ 0x30
	A2 = EMU_ReadU32(V0 + 52); //+ 0x34
	EMU_Write32(S0 + 8,V1); //+ 0x8
	EMU_Write32(S0 + 12,A0); //+ 0xC
	EMU_Write32(S0 + 16,A1); //+ 0x10
	EMU_Write32(S0 + 20,A2); //+ 0x14
	V1 = EMU_ReadU32(V0 + 56); //+ 0x38
	A0 = EMU_ReadU32(V0 + 60); //+ 0x3C
	EMU_Write32(S0 + 24,V1); //+ 0x18
	EMU_Write32(S0 + 28,A0); //+ 0x1C
	V0 = EMU_ReadU32(S1 + 96); //+ 0x60
	EMU_Write32(S0 + 32,V0); //+ 0x20
	V0 = EMU_ReadU32(S1 + 100); //+ 0x64
	EMU_Write32(S0 + 36,V0); //+ 0x24
	V0 = EMU_ReadU32(S1 + 104); //+ 0x68
	EMU_Write32(S0 + 40,V0); //+ 0x28
	A2 = EMU_ReadU32(S1 + 8); //+ 0x8
	A0 = S0 + 44;
	A1 = S0 + 8;
	RA = 0x8002C90C; //ZZ_2C638_2D4
	A3 = S0 + 32;
	ZZ_CLOCKCYCLES(34,0x80030CB4);
	goto ZZ_30CB4;
ZZ_2C638_2D4:
	V0 = S0;
	ZZ_CLOCKCYCLES(2,0x8002CD08);
	goto ZZ_2C638_6D0;
ZZ_2C638_2DC:
	V0 = EMU_ReadU32(S1 + 112); //+ 0x70
	S2 = V0 & 0xFFF;
	if (S2)
	{
		ZZ_CLOCKCYCLES(5,0x8002C990);
		goto ZZ_2C638_358;
	}
	if (V0)
	{
		ZZ_CLOCKCYCLES(7,0x8002C990);
		goto ZZ_2C638_358;
	}
	V0 = EMU_ReadU32(S1 + 108); //+ 0x6C
	if (V0)
	{
		V0 = 0x1000;
		ZZ_CLOCKCYCLES(11,0x8002C990);
		goto ZZ_2C638_358;
	}
	V0 = 0x1000;
	V1 = EMU_ReadU32(S1 + 120); //+ 0x78
	if (V1 != V0)
	{
		ZZ_CLOCKCYCLES(15,0x8002C990);
		goto ZZ_2C638_358;
	}
	V0 = EMU_ReadU32(S1 + 96); //+ 0x60
	V1 = EMU_ReadU32(S4 + 4); //+ 0x4
	V0 += V1;
	EMU_Write32(SP + 24,V0); //+ 0x18
	V0 = EMU_ReadU32(S1 + 100); //+ 0x64
	V1 = EMU_ReadU32(S4 + 8); //+ 0x8
	V0 += V1;
	EMU_Write32(SP + 28,V0); //+ 0x1C
	V0 = EMU_ReadU32(S1 + 104); //+ 0x68
	V1 = EMU_ReadU32(S4 + 12); //+ 0xC
	V0 += V1;
	EMU_Write32(SP + 32,V0); //+ 0x20
	ZZ_CLOCKCYCLES(31,0x8002C9C8);
	goto ZZ_2C638_390;
ZZ_2C638_358:
	V0 = EMU_ReadU32(S4 + 4); //+ 0x4
	EMU_Write32(SP + 40,V0); //+ 0x28
	V0 = EMU_ReadU32(S4 + 8); //+ 0x8
	A0 = SP + 40;
	EMU_Write32(SP + 44,V0); //+ 0x2C
	V0 = EMU_ReadU32(S4 + 12); //+ 0xC
	A1 = S1 + 96;
	A2 = S1 + 108;
	A3 = S1 + 120;
	EMU_Write32(SP + 48,V0); //+ 0x30
	V0 = SP + 24;
	RA = 0x8002C9C8; //ZZ_2C638_390
	EMU_Write32(SP + 16,V0); //+ 0x10
	ZZ_CLOCKCYCLES(14,0x8001EB2C);
	goto ZZ_1EB2C;
ZZ_2C638_390:
	A1 = EMU_ReadU32(S1 + 120); //+ 0x78
	V0 = S3 << 2;
	V0 += S3;
	V0 <<= 3;
	V0 += 24;
	if ((int32_t)A1 >= 0)
	{
		A2 = S5 + V0;
		ZZ_CLOCKCYCLES(7,0x8002C9E8);
		goto ZZ_2C638_3B0;
	}
	A2 = S5 + V0;
	A1 = -A1;
	ZZ_CLOCKCYCLES(8,0x8002C9E8);
ZZ_2C638_3B0:
	EMU_Write32(SP + 80,A1); //+ 0x50
	V1 = EMU_ReadU32(S1 + 124); //+ 0x7C
	EMU_Write32(SP + 84,V1); //+ 0x54
	A0 = EMU_ReadU32(S1 + 128); //+ 0x80
	EMU_Write32(SP + 88,A0); //+ 0x58
	V0 = EMU_ReadU32(A2 + 16); //+ 0x10
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,A1);
	T1 = LO;
	A3 = (int32_t)T1 >> 4;
	EMU_Write32(SP + 56,A3); //+ 0x38
	V0 = EMU_ReadU32(A2 + 20); //+ 0x14
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,V1);
	T1 = LO;
	V0 = (int32_t)T1 >> 4;
	EMU_Write32(SP + 60,V0); //+ 0x3C
	V0 = EMU_ReadU32(A2 + 24); //+ 0x18
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,A0);
	T1 = LO;
	T0 = (int32_t)T1 >> 4;
	EMU_Write32(SP + 64,T0); //+ 0x40
	V0 = EMU_ReadU32(A2 + 28); //+ 0x1C
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,A1);
	T1 = LO;
	V0 = (int32_t)T1 >> 4;
	EMU_Write32(SP + 68,V0); //+ 0x44
	V0 = EMU_ReadU32(A2 + 32); //+ 0x20
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,V1);
	T1 = LO;
	V0 = (int32_t)T1 >> 4;
	EMU_Write32(SP + 72,V0); //+ 0x48
	V0 = EMU_ReadU32(A2 + 36); //+ 0x24
	V0 = (int32_t)V0 >> 8;
	EMU_SMultiply(V0,A0);
	V0 = S2 - 512;
	V0 = V0 < 3073;
	T1 = LO;
	V1 = (int32_t)T1 >> 4;
	if (V0)
	{
		EMU_Write32(SP + 76,V1); //+ 0x4C
		ZZ_CLOCKCYCLES(52,0x8002CB28);
		goto ZZ_2C638_4F0;
	}
	EMU_Write32(SP + 76,V1); //+ 0x4C
	V0 = EMU_ReadU32(SP + 24); //+ 0x18
	V0 += A3;
	EMU_Write32(S0 + 8,V0); //+ 0x8
	V0 = EMU_ReadU32(SP + 28); //+ 0x1C
	V1 = EMU_ReadU32(SP + 60); //+ 0x3C
	V0 += V1;
	EMU_Write32(S0 + 12,V0); //+ 0xC
	V0 = EMU_ReadU32(SP + 32); //+ 0x20
	V1 = EMU_ReadU32(SP + 64); //+ 0x40
	V0 += V1;
	EMU_Write32(S0 + 16,V0); //+ 0x10
	V0 = EMU_ReadU32(SP + 24); //+ 0x18
	V1 = EMU_ReadU32(SP + 68); //+ 0x44
	V0 += V1;
	EMU_Write32(S0 + 20,V0); //+ 0x14
	V0 = EMU_ReadU32(SP + 28); //+ 0x1C
	V1 = EMU_ReadU32(SP + 72); //+ 0x48
	V0 += V1;
	EMU_Write32(S0 + 24,V0); //+ 0x18
	V0 = EMU_ReadU32(SP + 32); //+ 0x20
	V1 = EMU_ReadU32(SP + 76); //+ 0x4C
	V0 += V1;
	ZZ_CLOCKCYCLES(80,0x8002CC90);
	goto ZZ_2C638_658;
ZZ_2C638_4F0:
	V0 = (int32_t)S2 < 1536;
	if (!V0)
	{
		ZZ_CLOCKCYCLES(3,0x8002CBA4);
		goto ZZ_2C638_56C;
	}
	V0 = EMU_ReadU32(SP + 24); //+ 0x18
	V0 += T0;
	EMU_Write32(S0 + 8,V0); //+ 0x8
	V0 = EMU_ReadU32(SP + 24); //+ 0x18
	V1 = EMU_ReadU32(SP + 76); //+ 0x4C
	V0 += V1;
	EMU_Write32(S0 + 20,V0); //+ 0x14
	V0 = EMU_ReadU32(SP + 28); //+ 0x1C
	V1 = EMU_ReadU32(SP + 60); //+ 0x3C
	V0 += V1;
	EMU_Write32(S0 + 12,V0); //+ 0xC
	V0 = EMU_ReadU32(SP + 28); //+ 0x1C
	V1 = EMU_ReadU32(SP + 72); //+ 0x48
	V0 += V1;
	EMU_Write32(S0 + 24,V0); //+ 0x18
	V0 = EMU_ReadU32(SP + 32); //+ 0x20
	V1 = EMU_ReadU32(SP + 68); //+ 0x44
	V0 = V0 - V1;
	EMU_Write32(S0 + 16,V0); //+ 0x10
	V0 = EMU_ReadU32(SP + 32); //+ 0x20
	V1 = EMU_ReadU32(SP + 56); //+ 0x38
	V0 = V0 - V1;
	ZZ_CLOCKCYCLES(31,0x8002CC90);
	goto ZZ_2C638_658;
ZZ_2C638_56C:
	V0 = (int32_t)S2 < 2560;
	if (!V0)
	{
		ZZ_CLOCKCYCLES(3,0x8002CC20);
		goto ZZ_2C638_5E8;
	}
	V0 = EMU_ReadU32(SP + 24); //+ 0x18
	V0 += A3;
	EMU_Write32(S0 + 8,V0); //+ 0x8
	V0 = EMU_ReadU32(SP + 24); //+ 0x18
	V1 = EMU_ReadU32(SP + 68); //+ 0x44
	V0 += V1;
	EMU_Write32(S0 + 20,V0); //+ 0x14
	V0 = EMU_ReadU32(SP + 28); //+ 0x1C
	V1 = EMU_ReadU32(SP + 60); //+ 0x3C
	V0 += V1;
	EMU_Write32(S0 + 12,V0); //+ 0xC
	V0 = EMU_ReadU32(SP + 28); //+ 0x1C
	V1 = EMU_ReadU32(SP + 72); //+ 0x48
	V0 += V1;
	EMU_Write32(S0 + 24,V0); //+ 0x18
	V0 = EMU_ReadU32(SP + 32); //+ 0x20
	V1 = EMU_ReadU32(SP + 76); //+ 0x4C
	V0 = V0 - V1;
	EMU_Write32(S0 + 16,V0); //+ 0x10
	V0 = EMU_ReadU32(SP + 32); //+ 0x20
	V1 = EMU_ReadU32(SP + 64); //+ 0x40
	V0 = V0 - V1;
	ZZ_CLOCKCYCLES(31,0x8002CC90);
	goto ZZ_2C638_658;
ZZ_2C638_5E8:
	V0 = EMU_ReadU32(SP + 24); //+ 0x18
	V0 = V0 - V1;
	EMU_Write32(S0 + 8,V0); //+ 0x8
	V0 = EMU_ReadU32(SP + 24); //+ 0x18
	V1 = EMU_ReadU32(SP + 64); //+ 0x40
	V0 = V0 - V1;
	EMU_Write32(S0 + 20,V0); //+ 0x14
	V0 = EMU_ReadU32(SP + 28); //+ 0x1C
	V1 = EMU_ReadU32(SP + 60); //+ 0x3C
	V0 += V1;
	EMU_Write32(S0 + 12,V0); //+ 0xC
	V0 = EMU_ReadU32(SP + 28); //+ 0x1C
	V1 = EMU_ReadU32(SP + 72); //+ 0x48
	V0 += V1;
	EMU_Write32(S0 + 24,V0); //+ 0x18
	V0 = EMU_ReadU32(SP + 32); //+ 0x20
	V1 = EMU_ReadU32(SP + 56); //+ 0x38
	V0 += V1;
	EMU_Write32(S0 + 16,V0); //+ 0x10
	V0 = EMU_ReadU32(SP + 32); //+ 0x20
	V1 = EMU_ReadU32(SP + 68); //+ 0x44
	V0 += V1;
	ZZ_CLOCKCYCLES(28,0x8002CC90);
ZZ_2C638_658:
	EMU_Write32(S0 + 28,V0); //+ 0x1C
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 + 11632); //+ 0x2D70
	V0 &= 0x200;
	if (!V0)
	{
		V1 = 0x20000000;
		ZZ_CLOCKCYCLES(7,0x8002CD04);
		goto ZZ_2C638_6CC;
	}
	V1 = 0x20000000;
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 - 2524); //+ 0xFFFFF624
	V0 = EMU_ReadU32(V0 + 256); //+ 0x100
	V0 &= V1;
	if (!V0)
	{
		A1 = 0xFFFF0000;
		ZZ_CLOCKCYCLES(15,0x8002CD04);
		goto ZZ_2C638_6CC;
	}
	A1 = 0xFFFF0000;
	V0 = EMU_ReadU32(S0 + 8); //+ 0x8
	V1 = EMU_ReadU32(S0 + 16); //+ 0x10
	A0 = EMU_ReadU32(S0 + 20); //+ 0x14
	A2 = EMU_ReadU32(S0 + 28); //+ 0x1C
	A1 |= 0x5FD8;
	V0 += A1;
	V1 += A1;
	EMU_Write32(S0 + 8,V0); //+ 0x8
	V0 = 0xA028;
	A0 += V0;
	A2 += V0;
	EMU_Write32(S0 + 16,V1); //+ 0x10
	EMU_Write32(S0 + 20,A0); //+ 0x14
	EMU_Write32(S0 + 28,A2); //+ 0x1C
	ZZ_CLOCKCYCLES(29,0x8002CD04);
ZZ_2C638_6CC:
	V0 = S0;
	ZZ_CLOCKCYCLES(1,0x8002CD08);
ZZ_2C638_6D0:
	RA = EMU_ReadU32(SP + 120); //+ 0x78
	S5 = EMU_ReadU32(SP + 116); //+ 0x74
	S4 = EMU_ReadU32(SP + 112); //+ 0x70
	S3 = EMU_ReadU32(SP + 108); //+ 0x6C
	S2 = EMU_ReadU32(SP + 104); //+ 0x68
	S1 = EMU_ReadU32(SP + 100); //+ 0x64
	S0 = EMU_ReadU32(SP + 96); //+ 0x60
	SP += 128;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(10);
	ZZ_JUMPREGISTER(0x80038394,ZZ_37930_A64);
	ZZ_JUMPREGISTER(0x8001D160,ZZ_1D014_14C);
	ZZ_JUMPREGISTER(0x8001D0E0,ZZ_1D014_CC);
	ZZ_JUMPREGISTER(0x8001D1B0,ZZ_1D014_19C);
	ZZ_JUMPREGISTER(0x8001D0FC,ZZ_1D014_E8);
	ZZ_JUMPREGISTER(0x8001E5F0,ZZ_1D860_D90);
	ZZ_JUMPREGISTER(0x8001E5CC,ZZ_1D860_D6C);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x8002C638,0x8002C68C,ZZ_2C638);
ZZ_MARK_TARGET(0x8002C68C,0x8002C69C,ZZ_2C638_54);
ZZ_MARK_TARGET(0x8002C69C,0x8002C6C8,ZZ_2C638_64);
ZZ_MARK_TARGET(0x8002C6C8,0x8002C6E4,ZZ_2C638_90);
ZZ_MARK_TARGET(0x8002C6E4,0x8002C708,ZZ_2C638_AC);
ZZ_MARK_TARGET(0x8002C708,0x8002C70C,ZZ_2C638_D0);
ZZ_MARK_TARGET(0x8002C70C,0x8002C718,ZZ_2C638_D4);
ZZ_MARK_TARGET(0x8002C718,0x8002C734,ZZ_2C638_E0);
ZZ_MARK_TARGET(0x8002C734,0x8002C738,ZZ_2C638_FC);
ZZ_MARK_TARGET(0x8002C738,0x8002C78C,ZZ_2C638_100);
ZZ_MARK_TARGET(0x8002C78C,0x8002C7C0,ZZ_2C638_154);
ZZ_MARK_TARGET(0x8002C7C0,0x8002C884,ZZ_2C638_188);
ZZ_MARK_TARGET(0x8002C884,0x8002C90C,ZZ_2C638_24C);
ZZ_MARK_TARGET(0x8002C90C,0x8002C914,ZZ_2C638_2D4);
ZZ_MARK_TARGET(0x8002C914,0x8002C990,ZZ_2C638_2DC);
ZZ_MARK_TARGET(0x8002C990,0x8002C9C8,ZZ_2C638_358);
ZZ_MARK_TARGET(0x8002C9C8,0x8002C9E8,ZZ_2C638_390);
ZZ_MARK_TARGET(0x8002C9E8,0x8002CB28,ZZ_2C638_3B0);
ZZ_MARK_TARGET(0x8002CB28,0x8002CBA4,ZZ_2C638_4F0);
ZZ_MARK_TARGET(0x8002CBA4,0x8002CC20,ZZ_2C638_56C);
ZZ_MARK_TARGET(0x8002CC20,0x8002CC90,ZZ_2C638_5E8);
ZZ_MARK_TARGET(0x8002CC90,0x8002CD04,ZZ_2C638_658);
ZZ_MARK_TARGET(0x8002CD04,0x8002CD08,ZZ_2C638_6CC);
ZZ_MARK_TARGET(0x8002CD08,0x8002CD30,ZZ_2C638_6D0);
