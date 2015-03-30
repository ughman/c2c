#include "gool_mips.h"
#include "pcsx.h"
#include "emu.h"

static uint32_t dummy_r0; // for discarding writes to $R0

// casts for M_R* to force them to rvalues
#define M_OPCODE ((instruction >> 26) & 0x3F)
#define M_RS_NUM ((instruction >> 21) & 0x1F)
#define M_RT_NUM ((instruction >> 16) & 0x1F)
#define M_RD_NUM ((instruction >> 11) & 0x1F)
#define M_RS ((uint32_t)EMU_reg[M_RS_NUM])
#define M_RT ((uint32_t)EMU_reg[M_RT_NUM])
#define M_RD ((uint32_t)EMU_reg[M_RD_NUM])
#define M_RS_SET (*(M_RS_NUM ? &EMU_reg[M_RS_NUM] : &dummy_r0))
#define M_RT_SET (*(M_RT_NUM ? &EMU_reg[M_RT_NUM] : &dummy_r0))
#define M_RD_SET (*(M_RD_NUM ? &EMU_reg[M_RD_NUM] : &dummy_r0))
#define M_SHAMT ((instruction >> 6) & 0x1F)
#define M_FUNCT (instruction & 0x3F)
#define M_IMM ((int16_t)instruction)
#define M_IMM_U ((uint16_t)instruction)

static void GOOL_MIPS_OP_Invalid(struct goolenv *env,uint32_t instruction)
{
	fprintf(stderr,"GOOL_MIPS_OP_Invalid: %s\n",PCSX_Disassemble(env->oldpc));
	abort();
}

static void GOOL_MIPS_OP_ShiftLeftLogical(struct goolenv *env,uint32_t instruction)
{
	M_RD_SET = M_RT << M_SHAMT;
}

static void GOOL_MIPS_OP_ShiftRightArithmetic(struct goolenv *env,uint32_t instruction)
{
	// signed right-shifts are implementation defined
	M_RD_SET = (int32_t)M_RT / (1 << M_SHAMT);
}

static void GOOL_MIPS_OP_ShiftLeftLogicalVariable(struct goolenv *env,uint32_t instruction)
{
	M_RD_SET = M_RT << M_RS;
}

static void GOOL_MIPS_OP_JumpRegister(struct goolenv *env,uint32_t instruction)
{
	env->pcfar = M_RS;
}

static void GOOL_MIPS_OP_JumpAndLinkRegister(struct goolenv *env,uint32_t instruction)
{
	uint32_t pcfar = env->pcfar;
	env->pcfar = M_RS;
	M_RD_SET = pcfar;
}

static void GOOL_MIPS_OP_MoveFromHI(struct goolenv *env,uint32_t instruction)
{
	M_RD_SET = HI;
}

static void GOOL_MIPS_OP_MoveFromLO(struct goolenv *env,uint32_t instruction)
{
	M_RD_SET = LO;
}

static void GOOL_MIPS_OP_Multiply(struct goolenv *env,uint32_t instruction)
{
	EMU_SMultiply(M_RS,M_RT);
}

static void GOOL_MIPS_OP_Divide(struct goolenv *env,uint32_t instruction)
{
	EMU_SDivide(M_RS,M_RT);
}

static void GOOL_MIPS_OP_Add(struct goolenv *env,uint32_t instruction)
{
	M_RD_SET = M_RS + M_RT;
}

static void GOOL_MIPS_OP_Subtract(struct goolenv *env,uint32_t instruction)
{
	M_RD_SET = M_RS - M_RT;
}

static void GOOL_MIPS_OP_BitwiseAnd(struct goolenv *env,uint32_t instruction)
{
	M_RD_SET = M_RS & M_RT;
}

static void GOOL_MIPS_OP_BitwiseOr(struct goolenv *env,uint32_t instruction)
{
	M_RD_SET = M_RS | M_RT;
}

static void GOOL_MIPS_OP_BitwiseExclusiveOr(struct goolenv *env,uint32_t instruction)
{
	M_RD_SET = M_RS ^ M_RT;
}

static void GOOL_MIPS_OP_SetLessThan(struct goolenv *env,uint32_t instruction)
{
	M_RD_SET = (int32_t)M_RS < (int32_t)M_RT;
}

// src/gool_mips.cc:60:1: sorry, unimplemented: non-trivial designated initializers not supported
// TODO :: Get rid of this =NULL garbage when gcc stops being garbage
static goolexechandler_t GOOL_mips_table_special[64] = {
	[0] = GOOL_MIPS_OP_ShiftLeftLogical,
	[1] = NULL,
	[2] = NULL,
	[3] = GOOL_MIPS_OP_ShiftRightArithmetic,
	[4] = GOOL_MIPS_OP_ShiftLeftLogicalVariable,
	[5] = NULL,
	[6] = NULL,
	[7] = NULL,
	[8] = GOOL_MIPS_OP_JumpRegister,
	[9] = GOOL_MIPS_OP_JumpAndLinkRegister,
	[10] = NULL,
	[11] = NULL,
	[12] = NULL,
	[13] = NULL,
	[14] = NULL,
	[15] = NULL,
	[16] = GOOL_MIPS_OP_MoveFromHI,
	[17] = NULL,
	[18] = GOOL_MIPS_OP_MoveFromLO,
	[19] = NULL,
	[20] = NULL,
	[21] = NULL,
	[22] = NULL,
	[23] = NULL,
	[24] = GOOL_MIPS_OP_Multiply,
	[25] = NULL,
	[26] = GOOL_MIPS_OP_Divide,
	[27] = NULL,
	[28] = NULL,
	[29] = NULL,
	[30] = NULL,
	[31] = NULL,
	[32] = NULL,
	[33] = GOOL_MIPS_OP_Add,
	[34] = GOOL_MIPS_OP_Subtract, // should be checked for overflow
	[35] = GOOL_MIPS_OP_Subtract,
	[36] = GOOL_MIPS_OP_BitwiseAnd,
	[37] = GOOL_MIPS_OP_BitwiseOr,
	[38] = GOOL_MIPS_OP_BitwiseExclusiveOr,
	[39] = NULL,
	[40] = NULL,
	[41] = NULL,
	[42] = GOOL_MIPS_OP_SetLessThan
};

static void GOOL_MIPS_OP_Special(struct goolenv *env,uint32_t instruction)
{
	goolexechandler_t handler = GOOL_mips_table_special[M_FUNCT];
	if (!handler)
		handler = GOOL_MIPS_OP_Invalid;
	handler(env,instruction);
}

static void GOOL_MIPS_OP_BranchIfGreaterOrEqualToZero(struct goolenv *env,uint32_t instruction)
{
	if ((int32_t)M_RS >= 0)
		env->pcfar = env->pc + M_IMM * 4;
}

// TODO :: Get rid of this =NULL garbage when gcc stops being garbage
static goolexechandler_t GOOL_mips_table_regimm[64] = {
	[0] = NULL,
	[1] = GOOL_MIPS_OP_BranchIfGreaterOrEqualToZero
};

static void GOOL_MIPS_OP_RegImm(struct goolenv *env,uint32_t instruction)
{
	goolexechandler_t handler = GOOL_mips_table_regimm[M_RT_NUM];
	if (!handler)
		handler = GOOL_MIPS_OP_Invalid;
	handler(env,instruction);
}

static void GOOL_MIPS_OP_BranchIfEqual(struct goolenv *env,uint32_t instruction)
{
	if (M_RS == M_RT)
		env->pcfar = env->pc + M_IMM * 4;
}

static void GOOL_MIPS_OP_BranchIfNotEqual(struct goolenv *env,uint32_t instruction)
{
	if (M_RS != M_RT)
		env->pcfar = env->pc + M_IMM * 4;
}

static void GOOL_MIPS_OP_AddImmediate(struct goolenv *env,uint32_t instruction)
{
	M_RT_SET = M_RS + M_IMM;
}

static void GOOL_MIPS_OP_SetLessThanImmediate(struct goolenv *env,uint32_t instruction)
{
	M_RT_SET = (int32_t)M_RS < M_IMM;
}

static void GOOL_MIPS_OP_SetLessThanImmediateUnsigned(struct goolenv *env,uint32_t instruction)
{
	M_RT_SET = M_RS < M_IMM_U;
}

static void GOOL_MIPS_OP_BitwiseAndImmediate(struct goolenv *env,uint32_t instruction)
{
	M_RT_SET = M_RS & M_IMM_U;
}

static void GOOL_MIPS_OP_BitwiseOrImmediate(struct goolenv *env,uint32_t instruction)
{
	M_RT_SET = M_RS | M_IMM_U;
}

static void GOOL_MIPS_OP_BitwiseExclusiveOrImmediate(struct goolenv *env,uint32_t instruction)
{
	M_RT_SET = M_RS ^ M_IMM_U;
}

static void GOOL_MIPS_OP_LoadUpperImmediate(struct goolenv *env,uint32_t instruction)
{
	M_RT_SET = M_IMM_U << 16;
}

static void GOOL_MIPS_OP_LoadHalfword(struct goolenv *env,uint32_t instruction)
{
	M_RT_SET = EMU_ReadS16(M_RS + M_IMM);
}

static void GOOL_MIPS_OP_LoadWord(struct goolenv *env,uint32_t instruction)
{
	M_RT_SET = EMU_ReadU32(M_RS + M_IMM);
}

static void GOOL_MIPS_OP_StoreHalfword(struct goolenv *env,uint32_t instruction)
{
	EMU_Write16(M_RS + M_IMM,M_RT);
}

static void GOOL_MIPS_OP_StoreWord(struct goolenv *env,uint32_t instruction)
{
	EMU_Write32(M_RS + M_IMM,M_RT);
}

// TODO :: Get rid of this =NULL garbage when gcc stops being garbage
static goolexechandler_t GOOL_mips_table[64] = {
	[0] = GOOL_MIPS_OP_Special,
	[1] = GOOL_MIPS_OP_RegImm,
	[2] = NULL,
	[3] = NULL,
	[4] = GOOL_MIPS_OP_BranchIfEqual,
	[5] = GOOL_MIPS_OP_BranchIfNotEqual,
	[6] = NULL,
	[7] = NULL,
	[8] = NULL,
	[9] = GOOL_MIPS_OP_AddImmediate,
	[10] = GOOL_MIPS_OP_SetLessThanImmediate,
	[11] = GOOL_MIPS_OP_SetLessThanImmediateUnsigned,
	[12] = GOOL_MIPS_OP_BitwiseAndImmediate,
	[13] = GOOL_MIPS_OP_BitwiseOrImmediate,
	[14] = GOOL_MIPS_OP_BitwiseExclusiveOrImmediate,
	[15] = GOOL_MIPS_OP_LoadUpperImmediate,
	[16] = NULL,
	[17] = NULL,
	[18] = NULL,
	[19] = NULL,
	[20] = NULL,
	[21] = NULL,
	[22] = NULL,
	[23] = NULL,
	[24] = NULL,
	[25] = NULL,
	[26] = NULL,
	[27] = NULL,
	[28] = NULL,
	[29] = NULL,
	[30] = NULL,
	[31] = NULL,
	[32] = NULL,
	[33] = GOOL_MIPS_OP_LoadHalfword,
	[34] = NULL,
	[35] = GOOL_MIPS_OP_LoadWord,
	[36] = NULL,
	[37] = NULL,
	[38] = NULL,
	[39] = NULL,
	[40] = NULL,
	[41] = GOOL_MIPS_OP_StoreHalfword,
	[42] = NULL,
	[43] = GOOL_MIPS_OP_StoreWord
};

void GOOL_MIPS_ExecuteOnce(struct goolenv *env,uint32_t instruction)
{
	goolexechandler_t handler = GOOL_mips_table[M_OPCODE];
	if (!handler)
		handler = GOOL_MIPS_OP_Invalid;
	handler(env,instruction);
}

void GOOL_MIPS_ExecuteFromZZ(uint32_t pc)
{
	struct goolenv env;
	env.pc = pc;
	env.pcfar = pc + 4;
	env.language = env.languagefar = GOOL_LANGUAGE_MIPS;
	RA = 0xDEADBEEF;
	while (env.pc != 0xDEADBEEF)
	{
		uint32_t instruction = EMU_ReadU32(env.pc);
		env.oldpc = env.pc;
		env.pc = env.pcfar;
		env.pcfar = env.pcfar + 4;
		env.language = env.languagefar;
		GOOL_MIPS_ExecuteOnce(&env,instruction);
	}
}
