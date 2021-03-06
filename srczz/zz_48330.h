#ifdef ZZ_INCLUDE_CODE
ZZ_48330:
	V1 = 0x80060000;
	V1 = EMU_ReadU32(V1 - 13012); //+ 0xFFFFCD2C
	V0 = 1;
	EMU_Write8(V1,V0);
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 - 13000); //+ 0xFFFFCD38
	V0 = EMU_ReadU8(V0);
	V0 &= 0x7;
	if (!V0)
	{
		A0 = 1;
		ZZ_CLOCKCYCLES(12,0x800483B4);
		goto ZZ_48330_84;
	}
	A0 = 1;
	V1 = 7;
	ZZ_CLOCKCYCLES(13,0x80048364);
ZZ_48330_34:
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 - 13012); //+ 0xFFFFCD2C
	EMU_Write8(V0,A0);
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 - 13000); //+ 0xFFFFCD38
	EMU_Write8(V0,V1);
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 - 13004); //+ 0xFFFFCD34
	EMU_Write8(V0,V1);
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 - 13000); //+ 0xFFFFCD38
	V0 = EMU_ReadU8(V0);
	V0 &= 0x7;
	if (V0)
	{
		ZZ_CLOCKCYCLES(20,0x80048364);
		goto ZZ_48330_34;
	}
	ZZ_CLOCKCYCLES(20,0x800483B4);
ZZ_48330_84:
	AT = 0x80060000;
	EMU_Write8(AT - 12986,R0); //+ 0xFFFFCD46
	V0 = 0x80060000;
	V0 = EMU_ReadU8(V0 - 12986); //+ 0xFFFFCD46
	A0 = 0x80060000;
	A0 = EMU_ReadU32(A0 - 13012); //+ 0xFFFFCD2C
	V1 = 0x80060000;
	V1 -= 12988;
	AT = 0x80060000;
	EMU_Write8(AT - 12987,V0); //+ 0xFFFFCD45
	V0 = 2;
	EMU_Write8(V1,V0);
	EMU_Write8(A0,R0);
	V0 = 0x80060000;
	V0 = EMU_ReadU32(V0 - 13000); //+ 0xFFFFCD38
	EMU_Write8(V0,R0);
	V1 = 0x80060000;
	V1 = EMU_ReadU32(V1 - 12996); //+ 0xFFFFCD3C
	V0 = 4901;
	EMU_Write32(V1,V0);
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(23);
	ZZ_JUMPREGISTER(0x80046CE8,ZZ_46CD8_10);
	ZZ_JUMPREGISTER(0x80047A60,ZZ_47940_120);
	ZZ_JUMPREGISTER(0x80048850,ZZ_48740_110);
	ZZ_JUMPREGISTER(0x80048158,ZZ_47E8C_2CC);
	ZZ_JUMPREGISTER(0x80047CE8,ZZ_47BC0_128);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80048330,0x80048364,ZZ_48330);
ZZ_MARK_TARGET(0x80048364,0x800483B4,ZZ_48330_34);
ZZ_MARK_TARGET(0x800483B4,0x80048410,ZZ_48330_84);
