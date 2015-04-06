#ifdef ZZ_INCLUDE_CODE
ZZ_17C1C:
	V0 = EMU_ReadU16(A1);
	EMU_Write16(A0,V0);
	V0 = EMU_ReadU16(A1 + 2); //+ 0x2
	EMU_Write16(A0 + 2,V0); //+ 0x2
	V0 = EMU_ReadU16(A1 + 4); //+ 0x4
	EMU_Write16(A0 + 4,V0); //+ 0x4
	V1 = EMU_ReadS16(A1 + 6); //+ 0x6
	V0 = V1 << 1;
	V0 += V1;
	V0 = -V0;
	V0 = (int32_t)V0 >> 2;
	EMU_Write16(A0 + 6,V0); //+ 0x6
	V1 = EMU_ReadS16(A1 + 8); //+ 0x8
	V0 = V1 << 1;
	V0 += V1;
	V0 = -V0;
	V0 = (int32_t)V0 >> 2;
	EMU_Write16(A0 + 8,V0); //+ 0x8
	V1 = EMU_ReadS16(A1 + 10); //+ 0xA
	V0 = V1 << 1;
	V0 += V1;
	V0 = -V0;
	V0 = (int32_t)V0 >> 2;
	EMU_Write16(A0 + 10,V0); //+ 0xA
	V0 = EMU_ReadU16(A1 + 12); //+ 0xC
	V0 = -V0;
	EMU_Write16(A0 + 12,V0); //+ 0xC
	V0 = EMU_ReadU16(A1 + 14); //+ 0xE
	V0 = -V0;
	EMU_Write16(A0 + 14,V0); //+ 0xE
	V0 = EMU_ReadU16(A1 + 16); //+ 0x10
	V0 = -V0;
	EMU_Write16(A0 + 16,V0); //+ 0x10
	V0 = EMU_ReadU32(A1 + 20); //+ 0x14
	EMU_Write32(A0 + 20,V0); //+ 0x14
	V0 = EMU_ReadU32(A1 + 24); //+ 0x18
	EMU_Write32(A0 + 24,V0); //+ 0x18
	V0 = EMU_ReadU32(A1 + 28); //+ 0x1C
	ZZ_JUMPREGISTER_BEGIN(RA);
	EMU_Write32(A0 + 28,V0); //+ 0x1C
	ZZ_CLOCKCYCLES_JR(51);
	ZZ_JUMPREGISTER(0x80017EA0,ZZ_17CE8_1B8);
	ZZ_JUMPREGISTER(0x80017FE8,ZZ_17CE8_300);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80017C1C,0x80017CE8,ZZ_17C1C);
