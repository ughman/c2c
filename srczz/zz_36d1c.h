#ifdef ZZ_INCLUDE_CODE
ZZ_36D1C:
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(2);
	ZZ_JUMPREGISTER(0x80036C70,ZZ_36C10_60);
	ZZ_JUMPREGISTER(0x80036CBC,ZZ_36C8C_30);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x80036D1C,0x80036D24,ZZ_36D1C);
