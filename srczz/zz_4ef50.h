#ifdef ZZ_INCLUDE_CODE
ZZ_4EF50:
	T0 = EMU_ReadU32(A0);
	T1 = EMU_ReadU32(A0 + 4); //+ 0x4
	T2 = EMU_ReadU32(A0 + 8); //+ 0x8
	T3 = EMU_ReadU32(A0 + 12); //+ 0xC
	T4 = EMU_ReadU32(A0 + 16); //+ 0x10
	GTE_SetRegister(GTE_CREG_RT11_RT12,T0);
	GTE_SetRegister(GTE_CREG_RT13_RT21,T1);
	GTE_SetRegister(GTE_CREG_RT22_RT23,T2);
	GTE_SetRegister(GTE_CREG_RT31_RT32,T3);
	GTE_SetRegister(GTE_CREG_RT33_NONE,T4);
	T0 = EMU_ReadU16(A1);
	T1 = EMU_ReadU32(A1 + 4); //+ 0x4
	T2 = EMU_ReadU32(A1 + 12); //+ 0xC
	AT = 0xFFFF0000;
	T1 &= AT;
	T0 |= T1;
	GTE_SetRegister(GTE_DREG_VXY0,T0);
	GTE_SetRegister(GTE_DREG_VZ0,T2);
	GTE_Multiply_V0_Rotation();
	T0 = EMU_ReadU16(A1 + 2); //+ 0x2
	T1 = EMU_ReadU32(A1 + 8); //+ 0x8
	T2 = EMU_ReadS16(A1 + 14); //+ 0xE
	T1 <<= 16;
	T0 |= T1;
	T3 = GTE_GetRegister(GTE_DREG_IR1);
	T4 = GTE_GetRegister(GTE_DREG_IR2);
	T5 = GTE_GetRegister(GTE_DREG_IR3);
	GTE_SetRegister(GTE_DREG_VXY0,T0);
	GTE_SetRegister(GTE_DREG_VZ0,T2);
	GTE_Multiply_V0_Rotation();
	T0 = EMU_ReadU16(A1 + 4); //+ 0x4
	T1 = EMU_ReadU32(A1 + 8); //+ 0x8
	T2 = EMU_ReadU32(A1 + 16); //+ 0x10
	AT = 0xFFFF0000;
	T1 &= AT;
	T0 |= T1;
	T6 = GTE_GetRegister(GTE_DREG_IR1);
	T7 = GTE_GetRegister(GTE_DREG_IR2);
	T8 = GTE_GetRegister(GTE_DREG_IR3);
	GTE_SetRegister(GTE_DREG_VXY0,T0);
	GTE_SetRegister(GTE_DREG_VZ0,T2);
	GTE_Multiply_V0_Rotation();
	T3 &= 0xFFFF;
	T6 <<= 16;
	T6 |= T3;
	EMU_Write32(A0,T6);
	T5 &= 0xFFFF;
	T8 <<= 16;
	T8 |= T5;
	EMU_Write32(A0 + 12,T8); //+ 0xC
	T0 = GTE_GetRegister(GTE_DREG_IR1);
	T1 = GTE_GetRegister(GTE_DREG_IR2);
	T0 &= 0xFFFF;
	T4 <<= 16;
	T0 |= T4;
	EMU_Write32(A0 + 4,T0); //+ 0x4
	T7 &= 0xFFFF;
	T1 <<= 16;
	T1 |= T7;
	EMU_Write32(A0 + 8,T1); //+ 0x8
	EMU_Write32(A0 + 16,GTE_GetRegister(GTE_DREG_IR3)); //+ 0x10
	V0 = A0;
	ZZ_JUMPREGISTER_BEGIN(RA);
	ZZ_CLOCKCYCLES_JR(67);
	ZZ_JUMPREGISTER(0x8001EA88,ZZ_1E9C8_C0);
	ZZ_JUMPREGISTER(0x8001EAF8,ZZ_1E9C8_130);
	ZZ_JUMPREGISTER(0x80017DD8,ZZ_17CE8_F0);
	ZZ_JUMPREGISTER(0x80017E34,ZZ_17CE8_14C);
	ZZ_JUMPREGISTER(0x8001EDF4,ZZ_1ED20_D4);
	ZZ_JUMPREGISTER_END();
#endif
ZZ_MARK_TARGET(0x8004EF50,0x8004F05C,ZZ_4EF50);
