#ifdef ZZ_INCLUDE_CODE
ZZ_182B8:
	V1 = EMU_ReadS16(A1);
	V0 = EMU_ReadU32(A0);
	EMU_SMultiply(V1,V0);
	V1 = EMU_ReadS16(A1 + 2); //+ 0x2
	V0 = EMU_ReadU32(A0 + 4); //+ 0x4
	T0 = LO;
	EMU_SMultiply(V1,V0);
	V1 = EMU_ReadS16(A1 + 4); //+ 0x4
	V0 = EMU_ReadU32(A0 + 8); //+ 0x8
	A3 = LO;
	EMU_SMultiply(V1,V0);
	V0 = T0 + A3;
	V1 = LO;
	V0 += V1;
	V0 = (int32_t)V0 >> 12;
	EMU_Write32(A2,V0);
	V1 = EMU_ReadS16(A1 + 6); //+ 0x6
	V0 = EMU_ReadU32(A0);
	EMU_SMultiply(V1,V0);
	V1 = EMU_ReadS16(A1 + 8); //+ 0x8
	V0 = EMU_ReadU32(A0 + 4); //+ 0x4
	T0 = LO;
	EMU_SMultiply(V1,V0);
	V1 = EMU_ReadS16(A1 + 10); //+ 0xA
	V0 = EMU_ReadU32(A0 + 8); //+ 0x8
	A3 = LO;
	EMU_SMultiply(V1,V0);
	V0 = T0 + A3;
	V1 = LO;
	V0 += V1;
	V0 = (int32_t)V0 >> 12;
	EMU_Write32(A2 + 4,V0); //+ 0x4
	V1 = EMU_ReadS16(A1 + 12); //+ 0xC
	V0 = EMU_ReadU32(A0);
	EMU_SMultiply(V1,V0);
	V1 = EMU_ReadS16(A1 + 14); //+ 0xE
	V0 = EMU_ReadU32(A0 + 4); //+ 0x4
	T0 = LO;
	EMU_SMultiply(V1,V0);
	V1 = EMU_ReadS16(A1 + 16); //+ 0x10
	V0 = EMU_ReadU32(A0 + 8); //+ 0x8
	A3 = LO;
	EMU_SMultiply(V1,V0);
	V0 = T0 + A3;
	V1 = LO;
	V0 += V1;
	V0 = (int32_t)V0 >> 12;
	ZZ_JUMPREGISTER_BEGIN(RA);
	EMU_Write32(A2 + 8,V0); //+ 0x8
	ZZ_CLOCKCYCLES_JR(64);
	ZZ_JUMPREGISTER(0x8001EBBC,ZZ_1EB2C_90);
	ZZ_JUMPREGISTER(0x8001ECAC,ZZ_1EC34_78);
	ZZ_JUMPREGISTER(0x8001EE4C,ZZ_1ED20_12C);
	ZZ_JUMPREGISTER(0x80030D70,ZZ_30CB4_BC);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x800182B8,0x800183B8,ZZ_182B8);
