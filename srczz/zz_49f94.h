#ifdef ZZ_INCLUDE_CODE
ZZ_49F94:
	T2 = 176;
	ZZ_JUMPREGISTER_BEGIN(T2);
	T1 = 12;
	ZZ_CLOCKCYCLES_JR(3);
	ZZ_JUMPREGISTER(0xB0,ZZ_FORCEEXIT);
	ZZ_JUMPREGISTER_END();
#endif
// EnableEvent
ZZ_MARK_TARGET(0x80049F94,0x80049FA0,ZZ_49F94);
