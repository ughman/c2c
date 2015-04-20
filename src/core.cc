#include "core.h"
#include "emu.h"

int CORE_Main(void)
{
	EMU_Invoke(0x80049E6C,0);
	EMU_Write32(0x8005F43C,1);
	EMU_Invoke(0x80015738,0);
	CORE_Loop(0x3C);
	EMU_Invoke(0x800158C4,0);
	return 0;
}

void CORE_Loop(uint32_t levelid)
{
	SP -= 224;
	EMU_Write32(SP + 200,S0); //+ 0xC8
	S0 = levelid;
	EMU_Write32(SP + 204,S1); //+ 0xCC
	V0 = EMU_Invoke(0x8002F2F8,0);
	V0 = EMU_Invoke(0x80014D6C,2,0x80067820,S0);
	V0 = EMU_Invoke(0x8002F15C,0);
	do
	{
		if (!(!(EMU_ReadU32(0x80069BDC) & 0x800) && (EMU_ReadU32(GP + 4) != 0x1 || EMU_ReadU32(0x8006CE38))) && !EMU_ReadU32(0x8006CFAC) && !EMU_ReadU32(0x8006CFB0) && EMU_ReadU32(0x8006CF30))
		{
			V0 = !EMU_ReadU32(GP + 4);
			EMU_Write32(GP + 4,V0); //+ 0x4
			if (!V0)
			{
				V0 = EMU_ReadU32(0x8006CE38);
				if (V0)
				{
					EMU_Write32(SP + 192,0); //+ 0xC0
					EMU_Invoke(0x8001CD48,5,0,EMU_ReadU32(0x8006CE38),0xC00,0x1,SP + 192);
					EMU_Write32(GP + 4,0x1); //+ 0x4
				}
				else
				{
					V0 = EMU_ReadU32(GP + 328); //+ 0x148
					A0 = EMU_ReadU32(0x800636EC);
					V1 = EMU_ReadU32(GP + 332); //+ 0x14C
					EMU_Write32(GP + 16,-1); //+ 0x10
					EMU_Write32(0x8003C13C,V0);
					EMU_Write32(A0 + 12,V1); //+ 0xC
				}
				goto ZZ_11800_1A0;
			}
			if (EMU_ReadU32(0x8006CE38))
			{
				goto ZZ_11800_1A0;
			}
			V0 = EMU_Invoke(0x80019928,6,0x8006CDE8,0x4,0x4,0,0,0);
			EMU_Write32(0x8006CE38,V0);
			if ((int32_t)V0 < -254)
			{
				V0 = EMU_ReadU32(0x800636EC);
				V1 = EMU_ReadU32(0x8003C13C);
				A0 = EMU_ReadU32(V0 + 12); //+ 0xC
				EMU_Write32(GP + 16,0x1); //+ 0x10
				EMU_Write32(GP + 328,V1); //+ 0x148
				EMU_Write32(GP + 332,A0); //+ 0x14C
				goto ZZ_11800_1A0;
			}
			EMU_Write32(GP + 4,0); //+ 0x4
			EMU_Write32(0x8006CE38,0);
		}
		EMU_Write32(GP + 16,0); //+ 0x10
ZZ_11800_1A0:
		EMU_Invoke(0x80011E80,0);
		if (EMU_ReadU32(0x8005F624) && EMU_ReadU32(0x8005F620) != 0x6396347F)
		{
			EMU_Invoke(0x800300D8,1,0x8005F620);
		}
		if ((int32_t)EMU_ReadU32(0x8005F688) == -1)
		{
			V0 = EMU_ReadU32(0x80067834);
			V0 = EMU_ReadU32(V0 + 8); //+ 0x8
			if (V0 != 0x2)
			{
				V1 = EMU_ReadU32(0x8006CE4C);
				if (V1 == 0x200 || V1 == 0x300 || V1 == 0x400)
				{
					EMU_Invoke(0x800494DC,1,0x8005F428);
					EMU_Write32(0x8005F688,0x3B);
					EMU_Write32(0x8006F014,0);
				}
			}
		}
		if ((int32_t)EMU_ReadU32(0x8005F688) != -1)
		{
			S1 = EMU_ReadU32(0x8005F688);
			EMU_Invoke(0x8001D360,5,0,0x2900,0,0,0);
			if ((int32_t)EMU_ReadU32(0x8005F688) != -2)
			{
				S0 = 0;
			}
			else
			{
				S1 = EMU_ReadU32(0x80060C20);
				S0 = 0x1;
			}
			EMU_Write32(0x8005F48C,S0);
			EMU_Write32(0x80067844,0x2);
			EMU_Invoke(0x80015340,1,0x80067820);
			EMU_Write32(GP + 4,0);
			EMU_Write32(0x8005F650,0);
			if (S1 == 0x2 || S1 == 0x3B || S1 == 0x3C)
			{
				EMU_Write32(0x8006CE30,EMU_ReadU32(0x8006CE4C));
			}
			EMU_Invoke(0x80014D6C,2,0x80067820,S1);
			EMU_Invoke(0x8002F15C,0);
			if (S0)
			{
				EMU_Write32(0x8006F688,-1);
				EMU_Invoke(0x8002F9D4,1,0x80060BF0);
			}
			EMU_Write32(0x8005F48C,0);
		}
		EMU_Invoke(0x80012C88,1,-1);
		if (!EMU_ReadU32(GP + 4))
		{
			EMU_Invoke(0x80026F14,0);
		}
		EMU_Invoke(0x80017CE8,0);
		if (!(EMU_ReadU32(0x8006CE2C) & 0x1))
		{
			goto ZZ_11800_4C8;
		}
		V0 = EMU_ReadU32(0x80060B64);
		V0 = EMU_ReadU32(V0 + 16); //+ 0x10
		if (!EMU_ReadU32(V0))
		{
			goto ZZ_11800_4C8;
		}
		EMU_Invoke(0x8004F1C0,1,0x80060000 + 2572);
		V0 = EMU_ReadU32(0x80060B64);
		V0 = EMU_ReadU32(V0 + 16); //+ 0x10
		A0 = 0x1F800280;
		A1 = V0 + 44;
		for (A2 = EMU_ReadU32(V0);A2;A2--)
		{
			V0 = EMU_ReadU32(A1 - 32); //+ 0xFFFFFFE0
			V1 = EMU_ReadU16(A1 - 36); //+ 0xFFFFFFDC
			V0 &= 0xFFFE;
			V0 <<= 16;
			EMU_Write32(A0,V0 | V1);
			A0 += 4;
			EMU_Write32(A0,EMU_ReadU32(A1 - 28));
			A0 += 4;
			V0 = EMU_ReadU32(A1 - 24); //+ 0xFFFFFFE8
			V0 = EMU_ReadU32(V0 + 20); //+ 0x14
			V1 = EMU_ReadU32(A1 - 20); //+ 0xFFFFFFEC
			EMU_Write32(A0,V0 * 4 + V1);
			A0 += 4;
			EMU_Write32(A0,EMU_ReadU32(A1 - 16));
			A0 += 4;
			V0 = EMU_ReadU32(A1 - 24); //+ 0xFFFFFFE8
			V0 = EMU_ReadU32(V0 + 16); //+ 0x10
			V1 = EMU_ReadU32(A1 - 12); //+ 0xFFFFFFF4
			EMU_Write32(A0,V0 * 4 + V1);
			A0 += 4;
			EMU_Write32(A0,EMU_ReadU32(A1 - 8));
			A0 += 4;
			EMU_Write32(A0,EMU_ReadU32(A1 - 4));
			A0 += 4;
			EMU_Write32(A0,EMU_ReadU32(A1));
			A0 += 4;
			A1 += 48;
		}
		EMU_Invoke(0x8002FE90,1,0);
		V0 = EMU_Invoke(0x800420F4,4,EMU_ReadU32(0x8005F628),EMU_ReadU32(0x800636F0),0x80062CB0,EMU_ReadU32(0x80060BDC));
		EMU_Write32(0x8006CF50,V0);
		goto ZZ_11800_4DC;
ZZ_11800_4C8:
		EMU_Invoke(0x8003BEF4,2,EMU_ReadU32(0x800636F0) + 24,0x800);
ZZ_11800_4DC:
		if (EMU_ReadU32(0x8006CE2C) & 0x20000001)
		{
			A0 = EMU_ReadU32(0x80062D28);
			if (A0 && (EMU_ReadU32(0x80062D70) & 0x10))
			{
				EMU_Invoke(0x800451EC,3,A0,EMU_ReadU32(0x800636F0),0x80062CB0);
			}
			A0 = EMU_ReadU32(0x80062D38);
			if (A0 && (EMU_ReadU32(0x80062D70) & 0x400000))
			{
				EMU_Invoke(0x800454B0,3,A0,EMU_ReadU32(0x800636F0),0x80062CB0);
			}
		}
		EMU_Invoke(0x8001C3D4,1,!EMU_ReadU32(GP + 4));
		EMU_Invoke(0x80011E88,0);
		A1 = EMU_ReadU32(0x800636F0);
		EMU_Invoke(0x8003DE2C,3,EMU_ReadU32(A1 + 8328),A1,0x80062CB0);
		EMU_Invoke(0x8001658C,0);
		EMU_Invoke(0x80011E90,0);
	} while (!EMU_ReadU32(0x8005F468));
	EMU_Write32(0x8006CE2C,0);
	EMU_Invoke(0x8001658C,0);
	EMU_Invoke(0x8001658C,0);
	V0 = EMU_Invoke(0x80015340,1,0x80067820);
	S1 = EMU_ReadU32(SP + 204); //+ 0xCC
	S0 = EMU_ReadU32(SP + 200); //+ 0xC8
	SP += 224;
}

void CORE_Start(void)
{
	for (uint32_t i = 0x8005F53C;i < 0x8006F488;i += 4)
	{
		EMU_Write32(i,0);
	}
	V0 = EMU_ReadU32(0x8005F420);
	V0 = EMU_CheckedAdd(V0,-8);
	SP = V0 | 0x80000000;
	A1 = V0 - EMU_ReadU32(0x8005F41C) - 0x6F488;
	EMU_Write32(0x8005CDC4,A1);
	EMU_Write32(0x8005CDC0,0x8006F488);
	EMU_Write32(0x8005F5B8,RA); // $RA is garbage here
	GP = 0x8005F414;
	FP = SP;
	EMU_Invoke(0x8001144C,2,0x8006F48C,A1);
	CORE_Main();
	EMU_Break(1);
}

void CORE_VSync(int32_t count,int32_t timeout)
{
	timeout <<= 15;
	while ((int32_t)EMU_ReadU32(0x8005DF30) < count)
	{
		if (!timeout--)
		{
			EMU_Invoke(0x80049424,1,0x80010CE0);
			EMU_Invoke(0x8004A054,1,0);
			EMU_Invoke(0x8004A900,2,3,0);
			break;
		}
		EMU_Cycle(20);
		EMU_RunInterrupts();
	}
}
