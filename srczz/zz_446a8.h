#ifdef ZZ_INCLUDE_CODE
ZZ_446A8:
	EMU_Write32(V1 + 100,RA); //+ 0x64
	RA = 0x800446B4; //ZZ_446A8_C
	A0 = EMU_CheckedAdd(V1,32);
	ZZ_CLOCKCYCLES(3,0x80043240);
	goto ZZ_43240;
ZZ_446A8_C:
	RA = 0x800446BC; //ZZ_446A8_14
	A0 = EMU_CheckedAdd(V1,32);
	ZZ_CLOCKCYCLES(2,0x800433A8);
	goto ZZ_433A8;
ZZ_446A8_14:
	RA = EMU_ReadU32(V1 + 100); //+ 0x64
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(4);
	ZZ_JUMPREGISTER(0x8004470C,ZZ_446A8_64);
	ZZ_JUMPREGISTER_END();
ZZ_446A8_24:
	EMU_Write32(V1 + 100,RA); //+ 0x64
	RA = 0x800446D8; //ZZ_446A8_30
	A0 = EMU_CheckedAdd(V1,32);
	ZZ_CLOCKCYCLES(3,0x80043240);
	goto ZZ_43240;
ZZ_446A8_30:
	T6 = EMU_ReadU32(GP + 100); //+ 0x64
	T8 = EMU_ReadU32(SP + 80); //+ 0x50
	T5 = EMU_ReadU32(GP + 96); //+ 0x60
	T6 += T8;
	RA = 0x800446F0; //ZZ_446A8_48
	A0 = EMU_CheckedAdd(V1,32);
	ZZ_CLOCKCYCLES(6,0x800433B0);
	goto ZZ_433B0;
ZZ_446A8_48:
	RA = EMU_ReadU32(V1 + 100); //+ 0x64
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(4);
	ZZ_JUMPREGISTER(0x8004470C,ZZ_446A8_64);
	ZZ_JUMPREGISTER_END();
ZZ_446A8_58:
	EMU_Write32(V1 + 104,RA); //+ 0x68
	RA = 0x8004470C; //ZZ_446A8_64
	ZZ_CLOCKCYCLES(3,0x800446A8);
	goto ZZ_446A8;
ZZ_446A8_64:
	A0 = GTE_GetRegister(GTE_CREG_TRZ);
	T9 = EMU_ReadU32(V1 + 16); //+ 0x10
	T8 = EMU_ReadU32(V1 + 8); //+ 0x8
	A0 = A0 - T9;
	if ((int32_t)A0 < 0)
	{
		A0 <<= T8;
		ZZ_CLOCKCYCLES(6,0x80044744);
		goto ZZ_446A8_9C;
	}
	A0 <<= T8;
	T9 = EMU_ReadS16(SP + 64); //+ 0x40
	T8 = EMU_ReadU32(V1 + 4); //+ 0x4
	A0 += T9;
	T9 = EMU_CheckedAdd(A0,-4096);
	if ((int32_t)T9 <= 0)
	{
		EMU_Write32(SP + 68,T8); //+ 0x44
		ZZ_CLOCKCYCLES(12,0x80044740);
		goto ZZ_446A8_98;
	}
	EMU_Write32(SP + 68,T8); //+ 0x44
	A0 = 4096;
	ZZ_CLOCKCYCLES(13,0x80044740);
ZZ_446A8_98:
	EMU_Write16(SP + 64,A0); //+ 0x40
	ZZ_CLOCKCYCLES(1,0x80044744);
ZZ_446A8_9C:
	RA = EMU_ReadU32(V1 + 104); //+ 0x68
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(4);
	ZZ_JUMPREGISTER(0x8004470C,ZZ_446A8_64);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x800446A8,0x800446B4,ZZ_446A8);
ZZ_MARK_TARGET(0x800446B4,0x800446BC,ZZ_446A8_C);
ZZ_MARK_TARGET(0x800446BC,0x800446CC,ZZ_446A8_14);
ZZ_MARK_TARGET(0x800446CC,0x800446D8,ZZ_446A8_24);
ZZ_MARK_TARGET(0x800446D8,0x800446F0,ZZ_446A8_30);
ZZ_MARK_TARGET(0x800446F0,0x80044700,ZZ_446A8_48);
ZZ_MARK_TARGET(0x80044700,0x8004470C,ZZ_446A8_58);
ZZ_MARK_TARGET(0x8004470C,0x80044740,ZZ_446A8_64);
ZZ_MARK_TARGET(0x80044740,0x80044744,ZZ_446A8_98);
ZZ_MARK_TARGET(0x80044744,0x80044754,ZZ_446A8_9C);
