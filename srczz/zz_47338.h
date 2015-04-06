#ifdef ZZ_INCLUDE_CODE
ZZ_47338:
	V1 = EMU_ReadU8(A0);
	A2 = EMU_ReadU8(A0 + 1); //+ 0x1
	A1 = V1 >> 4;
	V0 = A1 << 2;
	V0 += A1;
	V0 <<= 1;
	V1 &= 0xF;
	V0 += V1;
	A1 = V0 << 4;
	A1 = A1 - V0;
	A1 <<= 2;
	V1 = A2 >> 4;
	V0 = V1 << 2;
	V0 += V1;
	V0 <<= 1;
	A2 &= 0xF;
	V0 += A2;
	A1 += V0;
	V1 = A1 << 2;
	V1 += A1;
	V0 = V1 << 4;
	A1 = EMU_ReadU8(A0 + 2); //+ 0x2
	V0 = V0 - V1;
	A0 = A1 >> 4;
	V1 = A0 << 2;
	V1 += A0;
	V1 <<= 1;
	A1 &= 0xF;
	V1 += A1;
	V0 += V1;
	ZZ_JUMPREGISTER_BEGIN(RA);
	V0 -= 150;
	ZZ_CLOCKCYCLES_JR(32);
	ZZ_JUMPREGISTER(0x800490CC,ZZ_48F5C_170);
	ZZ_JUMPREGISTER(0x80048C3C,ZZ_48B90_AC);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80047338,0x800473B8,ZZ_47338);
