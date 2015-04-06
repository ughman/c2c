#ifdef ZZ_INCLUDE_CODE
ZZ_26C7C:
	SP -= 120;
	EMU_Write32(SP + 100,S5); //+ 0x64
	S5 = A0;
	EMU_Write32(SP + 108,S7); //+ 0x6C
	S7 = A1;
	EMU_Write32(SP + 84,S1); //+ 0x54
	S1 = A2;
	EMU_Write32(SP + 88,S2); //+ 0x58
	S2 = A3;
	EMU_Write32(SP + 112,RA); //+ 0x70
	EMU_Write32(SP + 104,S6); //+ 0x68
	EMU_Write32(SP + 96,S4); //+ 0x60
	EMU_Write32(SP + 92,S3); //+ 0x5C
	EMU_Write32(SP + 80,S0); //+ 0x50
	V0 = EMU_ReadU32(S5 + 4); //+ 0x4
	A1 = 0x4B;
	A2 = R0;
	S4 = EMU_ReadU32(V0 + 20); //+ 0x14
	S6 = (int32_t)S7 >> 8;
	A3 = S6;
	S0 = 0x2;
	EMU_Write32(SP + 16,R0); //+ 0x10
	EMU_Write32(SP + 20,S0); //+ 0x14
	EMU_Write32(SP + 24,R0); //+ 0x18
	EMU_Write32(SP + 28,R0); //+ 0x1C
	RA = 0x80026CE8; //ZZ_26C7C_6C
	EMU_Write32(SP + 32,R0); //+ 0x20
	ZZ_CLOCKCYCLES(27,0x80031DF4);
	goto ZZ_31DF4;
ZZ_26C7C_6C:
	A0 = 0x80060000;
	A0 = EMU_ReadU32(A0 + 2928); //+ 0xB70
	A1 = 0x4B;
	A2 = R0;
	A3 = S6 << 1;
	S3 = V0;
	EMU_Write32(SP + 16,R0); //+ 0x10
	EMU_Write32(SP + 20,S0); //+ 0x14
	EMU_Write32(SP + 24,R0); //+ 0x18
	EMU_Write32(SP + 28,R0); //+ 0x1C
	RA = 0x80026D18; //ZZ_26C7C_9C
	EMU_Write32(SP + 32,R0); //+ 0x20
	ZZ_CLOCKCYCLES(12,0x80031DF4);
	goto ZZ_31DF4;
ZZ_26C7C_9C:
	A0 = EMU_ReadS16(S3);
	V1 = EMU_ReadU32(S4);
	V1 += A0;
	V1 <<= 8;
	EMU_Write32(S1,V1);
	A0 = EMU_ReadS16(S3 + 2); //+ 0x2
	V1 = EMU_ReadU32(S4 + 4); //+ 0x4
	V1 += A0;
	V1 <<= 8;
	EMU_Write32(S1 + 4,V1); //+ 0x4
	A0 = EMU_ReadS16(S3 + 4); //+ 0x4
	V1 = EMU_ReadU32(S4 + 8); //+ 0x8
	S0 = V0;
	V1 += A0;
	V1 <<= 8;
	EMU_Write32(S1 + 8,V1); //+ 0x8
	V0 = EMU_ReadS16(S0);
	EMU_Write32(S1 + 12,V0); //+ 0xC
	V0 = EMU_ReadS16(S0 + 2); //+ 0x2
	EMU_Write32(S1 + 16,V0); //+ 0x10
	V0 = EMU_ReadS16(S0 + 4); //+ 0x4
	if (!S2)
	{
		EMU_Write32(S1 + 20,V0); //+ 0x14
		ZZ_CLOCKCYCLES(27,0x80026DA8);
		goto ZZ_26C7C_12C;
	}
	EMU_Write32(S1 + 20,V0); //+ 0x14
	V0 = EMU_ReadS16(S0 + 6); //+ 0x6
	EMU_Write32(S2,V0);
	V0 = EMU_ReadS16(S0 + 8); //+ 0x8
	EMU_Write32(S2 + 4,V0); //+ 0x4
	V0 = EMU_ReadS16(S0 + 10); //+ 0xA
	EMU_Write32(S2 + 8,V0); //+ 0x8
	ZZ_CLOCKCYCLES(36,0x80026DA8);
ZZ_26C7C_12C:
	S2 = S7 & 0xFF;
	if (!S2)
	{
		A0 = S5;
		ZZ_CLOCKCYCLES(3,0x80026EE4);
		goto ZZ_26C7C_268;
	}
	A0 = S5;
	A1 = 0x4B;
	A2 = R0;
	RA = 0x80026DC4; //ZZ_26C7C_148
	A3 = 0x2;
	ZZ_CLOCKCYCLES(7,0x800325CC);
	goto ZZ_325CC;
ZZ_26C7C_148:
	V1 = S6 + 1;
	V1 = (int32_t)V1 < (int32_t)V0;
	if (!V1)
	{
		ZZ_CLOCKCYCLES(4,0x80026EE4);
		goto ZZ_26C7C_268;
	}
	V0 = EMU_ReadS16(S3 + 6); //+ 0x6
	V1 = EMU_ReadU32(S4);
	V1 += V0;
	V1 <<= 8;
	EMU_Write32(SP + 40,V1); //+ 0x28
	A0 = EMU_ReadS16(S3 + 8); //+ 0x8
	V0 = EMU_ReadU32(S4 + 4); //+ 0x4
	V0 += A0;
	V0 <<= 8;
	EMU_Write32(SP + 44,V0); //+ 0x2C
	A0 = EMU_ReadS16(S3 + 10); //+ 0xA
	V0 = EMU_ReadU32(S4 + 8); //+ 0x8
	V0 += A0;
	V0 <<= 8;
	EMU_Write32(SP + 48,V0); //+ 0x30
	V0 = EMU_ReadS16(S0 + 12); //+ 0xC
	EMU_Write32(SP + 52,V0); //+ 0x34
	V0 = EMU_ReadS16(S0 + 14); //+ 0xE
	EMU_Write32(SP + 56,V0); //+ 0x38
	V0 = EMU_ReadS16(S0 + 16); //+ 0x10
	EMU_Write32(SP + 60,V0); //+ 0x3C
	V0 = EMU_ReadU32(S1);
	V1 = V1 - V0;
	EMU_SMultiply(V1,S2);
	T0 = LO;
	V1 = (int32_t)T0 >> 8;
	V0 += V1;
	EMU_Write32(S1,V0);
	V0 = EMU_ReadU32(SP + 44); //+ 0x2C
	V1 = EMU_ReadU32(S1 + 4); //+ 0x4
	V0 = V0 - V1;
	EMU_SMultiply(V0,S2);
	T0 = LO;
	V0 = (int32_t)T0 >> 8;
	V1 += V0;
	EMU_Write32(S1 + 4,V1); //+ 0x4
	V0 = EMU_ReadU32(SP + 48); //+ 0x30
	V1 = EMU_ReadU32(S1 + 8); //+ 0x8
	V0 = V0 - V1;
	EMU_SMultiply(V0,S2);
	A0 = EMU_ReadU32(S1 + 12); //+ 0xC
	T0 = LO;
	V0 = (int32_t)T0 >> 8;
	V1 += V0;
	EMU_Write32(S1 + 8,V1); //+ 0x8
	A1 = EMU_ReadU32(SP + 52); //+ 0x34
	RA = 0x80026EB8; //ZZ_26C7C_23C
	A2 = S2;
	ZZ_CLOCKCYCLES(61,0x800315D8);
	goto ZZ_315D8;
ZZ_26C7C_23C:
	A0 = EMU_ReadU32(S1 + 16); //+ 0x10
	EMU_Write32(S1 + 12,V0); //+ 0xC
	A1 = EMU_ReadU32(SP + 56); //+ 0x38
	RA = 0x80026ECC; //ZZ_26C7C_250
	A2 = S2;
	ZZ_CLOCKCYCLES(5,0x800315D8);
	goto ZZ_315D8;
ZZ_26C7C_250:
	A0 = EMU_ReadU32(S1 + 20); //+ 0x14
	EMU_Write32(S1 + 16,V0); //+ 0x10
	A1 = EMU_ReadU32(SP + 60); //+ 0x3C
	RA = 0x80026EE0; //ZZ_26C7C_264
	A2 = S2;
	ZZ_CLOCKCYCLES(5,0x800315D8);
	goto ZZ_315D8;
ZZ_26C7C_264:
	EMU_Write32(S1 + 20,V0); //+ 0x14
	ZZ_CLOCKCYCLES(1,0x80026EE4);
ZZ_26C7C_268:
	RA = EMU_ReadU32(SP + 112); //+ 0x70
	S7 = EMU_ReadU32(SP + 108); //+ 0x6C
	S6 = EMU_ReadU32(SP + 104); //+ 0x68
	S5 = EMU_ReadU32(SP + 100); //+ 0x64
	S4 = EMU_ReadU32(SP + 96); //+ 0x60
	S3 = EMU_ReadU32(SP + 92); //+ 0x5C
	S2 = EMU_ReadU32(SP + 88); //+ 0x58
	S1 = EMU_ReadU32(SP + 84); //+ 0x54
	S0 = EMU_ReadU32(SP + 80); //+ 0x50
	SP += 120;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(12);
	ZZ_JUMPREGISTER(0x80022E90,ZZ_22CD0_1C0);
	ZZ_JUMPREGISTER(0x800209AC,ZZ_20304_6A8);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80026C7C,0x80026CE8,ZZ_26C7C);
ZZ_MARK_TARGET(0x80026CE8,0x80026D18,ZZ_26C7C_6C);
ZZ_MARK_TARGET(0x80026D18,0x80026DA8,ZZ_26C7C_9C);
ZZ_MARK_TARGET(0x80026DA8,0x80026DC4,ZZ_26C7C_12C);
ZZ_MARK_TARGET(0x80026DC4,0x80026EB8,ZZ_26C7C_148);
ZZ_MARK_TARGET(0x80026EB8,0x80026ECC,ZZ_26C7C_23C);
ZZ_MARK_TARGET(0x80026ECC,0x80026EE0,ZZ_26C7C_250);
ZZ_MARK_TARGET(0x80026EE0,0x80026EE4,ZZ_26C7C_264);
ZZ_MARK_TARGET(0x80026EE4,0x80026F14,ZZ_26C7C_268);
