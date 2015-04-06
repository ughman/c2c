#ifdef ZZ_INCLUDE_CODE
ZZ_56294:
	A0 <<= 16;
	V0 = 0x80070000;
	V0 -= 15268;
	A0 = (int32_t)A0 >> 14;
	A0 += V0;
	A1 <<= 16;
	A1 = (int32_t)A1 >> 16;
	A2 = A1 << 1;
	A2 += A1;
	A2 <<= 2;
	A2 = A2 - A1;
	A2 <<= 4;
	A3 = EMU_ReadU32(A0);
	T0 = 1;
	A3 += A2;
	EMU_Write8(A3 + 32,T0); //+ 0x20
	EMU_Write8(A3 + 33,R0); //+ 0x21
	V1 = EMU_ReadU32(A0);
	V1 += A2;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A1 = -257;
	V0 &= A1;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	V1 = EMU_ReadU32(A0);
	V1 += A2;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A1 = -9;
	V0 &= A1;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	V1 = EMU_ReadU32(A0);
	V1 += A2;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A1 = -3;
	V0 &= A1;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	V1 = EMU_ReadU32(A0);
	V1 += A2;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A1 = -5;
	V0 &= A1;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	V1 = EMU_ReadU32(A0);
	V1 += A2;
	V0 = EMU_ReadU32(V1 + 152); //+ 0x98
	A1 = -513;
	V0 &= A1;
	EMU_Write32(V1 + 152,V0); //+ 0x98
	V0 = EMU_ReadU32(A3 + 4); //+ 0x4
	EMU_Write8(A3 + 20,T0); //+ 0x14
	EMU_Write32(A3,V0);
	V0 = EMU_ReadU32(A0);
	A2 += V0;
	V0 = EMU_ReadU32(A2 + 152); //+ 0x98
	V0 |= 0x1;
	ZZ_JUMPREGISTER_BEGIN(RA);
	EMU_Write32(A2 + 152,V0); //+ 0x98
	ZZ_CLOCKCYCLES_JR(63);
	ZZ_JUMPREGISTER(0x80055EA0,ZZ_55CAC_1F4);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80056294,0x80056390,ZZ_56294);
