#ifdef ZZ_INCLUDE_CODE
ZZ_5B250:
	T2 = 160;
	ZZ_JUMPREGISTER_BEGIN(T2);
	T1 = 172;
	ZZ_CLOCKCYCLES_JR(3);
	ZZ_JUMPREGISTER(0xA0,ZZ_FORCEEXIT);
	ZZ_JUMPREGISTER_END();
#endif
// CardAsyncLoadDirectory
ZZ_MARK_TARGET(0x8005B250,0x8005B25C,ZZ_5B250);
