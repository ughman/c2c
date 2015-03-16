# C2C #
This is a project to reverse engineer the game _Crash Bandicoot 2: Cortex Strikes Back_ and eventually have a complete port to C. The game engine is converted directly from MIPS machine code into a massive block of C code which utilizes a playstation emulator for I/O. Portions of the converted code can then be decompiled by hand and used in place of the original code.

## The Disassembler ##
Located in `srcdisasm/` is a custom-built MIPS disassembler written in C#. This disassembler is given the game engine's executable file and outputs a massive C source file which contains equivalent code. For example, see the following series of instructions taken directly from the game:

```
	80012B0C: 00809821 !... ADDU $S3,$A0,$R0
	80012B10: 14530002 ..S. BNE $V0,$S3,80012B1C
	80012B14: 00000000 .... NOP
	80012B18: AC600000 ..`¬ SW $R0,0($V1)
ZZ_12AE4_38:
	80012B1C: 96620004 ..b. LHU $V0,4($S3)
	80012B20: 00000000 .... NOP
	80012B24: 2442FFEC ìÿB$ ADDIU $V0,$V0,-20
	80012B28: 2C420002 ..B, SLTIU $V0,$V0,2
```

This series of instructions becomes the following code in C:

```C
	S3 = A0;
	if (V0 != S3)
	{
		ZZ_CLOCKCYCLES(13,0x80012B1C);
		goto ZZ_12AE4_38;
	}
	EMU_Write32(V1,R0);
	ZZ_CLOCKCYCLES(14,0x80012B1C);
ZZ_12AE4_38:
	V0 = EMU_ReadU16(S3 + 4); //+ 0x4
	V0 -= 20;
	V0 = V0 < 2;
```

As seen above, the disassembler's conversion is very direct and does little actual decompiling, only basic expression simplification. It is up to the programmer to do all necessary analysis to detect code structures such as loops or conditional execution. As an additional barrier, the disassembler does no analysis of indirect branches such as function pointer calls or jump tables for switch statements. Therefore, it is also up to the programmer to specify all code regions which have not been automatically detected by the disassembler. This can be seen in `srcdisasm/Main.cs`.

## The Emulator ##
Located in `srcemu/` is a modified version of the _PCSX-R_ playstation emulator. The emulator has been repurposed into an external library to implement the I/O devices used by the disassembled code. The emulator is also used to emulate the system's processor in two cases:

1. The game does an indirect branch to undetected code (see above) which has not been disassembled. A warning is issued in this case.
2. The game invokes code which does not exist within the game engine. The primary case of this is native code sections used in GOOL scripts, however these are handled using a separate interpreter in `src/gool_mips.cc`.

Additionally, the emulator implements the Geometry Transformation Engine (GTE) coprocessor used for matrix and vector math necessary for 3D rendering.

## The Disassembled Code ##
Located in `srczz/` is the output from the disassembler, one file for each function. Each destination of a direct "jump-and-link" is considered to be the start of a new function and thus begins a new file. At the top half of each file is a list of addresses occupied by the function, linking addresses to C labels as well as enabling warnings for two conditions:

1. Writing to code, which would signify broken or self-modifying code, a condition for which the disassembled code has no means of handling.
2. Branches to addresses not identified as potential branch destinations by the disassembler, which will not have an associated C label and as such cannot be handled.

Functions in the disassembled code are intended to be decompiled by hand and eventually moved out into "real" C functions within the main code base (`src/`) leaving the disassembled file as merely a call out to the new function.

As an example of hand-decompilation of code, the C code from above could be changed into:

```C
	S3 = A0;
	if (V0 == S3)
		EMU_Write32(V1,0);
	V0 = EMU_ReadU16(S3 + 4) - 20 < 2;
```

Furthermore, `V0` is actually used directly after this code as a condition for a branch and then discarded, so `EMU_ReadU16(S3 + 4) - 20 < 2` could be placed directly into the expression and V0 removed. Eventually, a decompiled function will not even rely on MIPS registers and can use real C arguments and local variables.

Decompiled functions may call functions which have yet to be decompiled by calling `EMU_Invoke` which itself is used by `main` to invoke the disassembled game's entry point routine. This allows decompilation to begin at non-leaf functions.

## The Main Code ##
The main body of code is located in `src/` and contains the core code of the project as well as interoperability code for accessing the emulator. Decompiled functions should be moved into this section of the code base and given proper function names.
