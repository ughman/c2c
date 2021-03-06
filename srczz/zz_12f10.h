#ifdef ZZ_INCLUDE_CODE
ZZ_12F10:
	V0 = EMU_ReadU32(GP + 40); //+ 0x28
	SP -= 32;
	EMU_Write32(SP + 24,S0); //+ 0x18
	S0 = A0;
	if (!V0)
	{
		EMU_Write32(SP + 28,RA); //+ 0x1C
		ZZ_CLOCKCYCLES(6,0x80012F80);
		goto ZZ_12F10_70;
	}
	EMU_Write32(SP + 28,RA); //+ 0x1C
	V0 = 0x80070000;
	V0 = EMU_ReadU32(V0 - 32180); //+ 0xFFFF824C
	if (V0)
	{
		A0 = 0x1;
		ZZ_CLOCKCYCLES(11,0x80012F80);
		goto ZZ_12F10_70;
	}
	A0 = 0x1;
	RA = 0x80012F44; //ZZ_12F10_34
	A1 = R0;
	ZZ_CLOCKCYCLES(13,0x80046D78);
	goto ZZ_46D78;
ZZ_12F10_34:
	if (V0)
	{
		V0 = S0 << 1;
		ZZ_CLOCKCYCLES(2,0x80012F80);
		goto ZZ_12F10_70;
	}
	V0 = S0 << 1;
	V0 += S0;
	V0 <<= 2;
	AT = 0x80070000;
	AT += V0;
	V0 = EMU_ReadU32(AT - 27956); //+ 0xFFFF92CC
	A0 = 0x7F0000;
	A0 |= 0xFFFF;
	A1 = SP + 16;
	RA = 0x80012F74; //ZZ_12F10_64
	A0 &= V0;
	ZZ_CLOCKCYCLES(12,0x80047234);
	goto ZZ_47234;
ZZ_12F10_64:
	A0 = 0x15;
	RA = 0x80012F80; //ZZ_12F10_70
	A1 = SP + 16;
	ZZ_CLOCKCYCLES(3,0x80046F20);
	goto ZZ_46F20;
ZZ_12F10_70:
	RA = EMU_ReadU32(SP + 28); //+ 0x1C
	S0 = EMU_ReadU32(SP + 24); //+ 0x18
	SP += 32;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(5);
	ZZ_JUMPREGISTER(0x80038078,ZZ_37930_748);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80012F10,0x80012F44,ZZ_12F10);
ZZ_MARK_TARGET(0x80012F44,0x80012F74,ZZ_12F10_34);
ZZ_MARK_TARGET(0x80012F74,0x80012F80,ZZ_12F10_64);
ZZ_MARK_TARGET(0x80012F80,0x80012F94,ZZ_12F10_70);
