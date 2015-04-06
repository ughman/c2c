#ifdef ZZ_INCLUDE_CODE
ZZ_54CF8:
	SP -= 24;
	T3 = A0;
	V0 = T3 << 16;
	V1 = 0x80070000;
	V1 -= 15268;
	V0 = (int32_t)V0 >> 14;
	T2 = V0 + V1;
	V1 = A1 << 16;
	V1 = (int32_t)V1 >> 16;
	V0 = V1 << 1;
	V0 += V1;
	V0 <<= 2;
	V0 = V0 - V1;
	EMU_Write32(SP + 16,RA); //+ 0x10
	V1 = EMU_ReadU32(T2);
	T1 = V0 << 4;
	T0 = V1 + T1;
	V0 = EMU_ReadU32(T0 + 4); //+ 0x4
	V1 = EMU_ReadU32(T0 + 4); //+ 0x4
	A0 = EMU_ReadU32(T0 + 4); //+ 0x4
	EMU_Write32(T0,V0);
	EMU_Write32(T0 + 8,V1); //+ 0x8
	EMU_Write32(T0 + 12,A0); //+ 0xC
	V1 = EMU_ReadU32(T2);
	V1 += T1;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A0 = -513;
	V0 &= A0;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	V1 = EMU_ReadU32(T2);
	A2 &= 0xFF;
	V1 += T1;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A0 = -5;
	V0 &= A0;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	V0 = 1;
	if (A2 != V0)
	{
		EMU_Write8(T0 + 32,A3); //+ 0x20
		ZZ_CLOCKCYCLES(40,0x80054DE0);
		goto ZZ_54CF8_E8;
	}
	EMU_Write8(T0 + 32,A3); //+ 0x20
	A0 = A1 << 8;
	A0 |= T3;
	A0 <<= 16;
	V1 = EMU_ReadU32(T2);
	A0 = (int32_t)A0 >> 16;
	V1 += T1;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A3 = 1;
	V0 |= 0x1;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	A1 = EMU_ReadU16(T0 + 88); //+ 0x58
	A2 = EMU_ReadU16(T0 + 90); //+ 0x5A
	V0 = 1;
	EMU_Write8(T0 + 33,R0); //+ 0x21
	RA = 0x80054DD8; //ZZ_54CF8_E0
	EMU_Write8(T0 + 20,V0); //+ 0x14
	ZZ_CLOCKCYCLES(56,0x800598A0);
	goto ZZ_598A0;
ZZ_54CF8_E0:
	ZZ_CLOCKCYCLES(2,0x80054E04);
	goto ZZ_54CF8_10C;
ZZ_54CF8_E8:
	if (A2)
	{
		ZZ_CLOCKCYCLES(2,0x80054E04);
		goto ZZ_54CF8_10C;
	}
	V1 = EMU_ReadU32(T2);
	V1 += T1;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	V0 |= 0x2;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	ZZ_CLOCKCYCLES(9,0x80054E04);
ZZ_54CF8_10C:
	RA = EMU_ReadU32(SP + 16); //+ 0x10
	SP += 24;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(4);
	ZZ_JUMPREGISTER(0x80054BF8,ZZ_54BD0_28);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80054CF8,0x80054DD8,ZZ_54CF8);
ZZ_MARK_TARGET(0x80054DD8,0x80054DE0,ZZ_54CF8_E0);
ZZ_MARK_TARGET(0x80054DE0,0x80054E04,ZZ_54CF8_E8);
ZZ_MARK_TARGET(0x80054E04,0x80054E14,ZZ_54CF8_10C);
