#ifndef H_GTE_H
#define H_GTE_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

enum
{
	GTE_DREG_VXY0,
	GTE_DREG_VZ0,
	GTE_DREG_VXY1,
	GTE_DREG_VZ1,
	GTE_DREG_VXY2,
	GTE_DREG_VZ2,
	GTE_DREG_RGBC,
	GTE_DREG_OTZ,
	GTE_DREG_IR0,
	GTE_DREG_IR1,
	GTE_DREG_IR2,
	GTE_DREG_IR3,
	GTE_DREG_SXY0,
	GTE_DREG_SXY1,
	GTE_DREG_SXY2,
	GTE_DREG_SXYP,
	GTE_DREG_SZ0,
	GTE_DREG_SZ1,
	GTE_DREG_SZ2,
	GTE_DREG_SZ3,
	GTE_DREG_RGB0,
	GTE_DREG_RGB1,
	GTE_DREG_RGB2,
	GTE_DREG_RESERVED,
	GTE_DREG_MAC0,
	GTE_DREG_MAC1,
	GTE_DREG_MAC2,
	GTE_DREG_MAC3,
	GTE_DREG_IRGB,
	GTE_DREG_ORGB,
	GTE_DREG_LZCS,
	GTE_DREG_LZCR,
	GTE_CREG_RT11_RT12,
	GTE_CREG_RT13_RT21,
	GTE_CREG_RT22_RT23,
	GTE_CREG_RT31_RT32,
	GTE_CREG_RT33_NONE,
	GTE_CREG_TRX,
	GTE_CREG_TRY,
	GTE_CREG_TRZ,
	GTE_CREG_L11_L12,
	GTE_CREG_L13_L21,
	GTE_CREG_L22_L23,
	GTE_CREG_L31_L32,
	GTE_CREG_L33_NONE,
	GTE_CREG_RBK,
	GTE_CREG_GBK,
	GTE_CREG_BBK,
	GTE_CREG_LR1_LR2,
	GTE_CREG_LR3_LG1,
	GTE_CREG_LG2_LG3,
	GTE_CREG_LB1_LB2,
	GTE_CREG_LB3_NONE,
	GTE_CREG_RFC,
	GTE_CREG_GFC,
	GTE_CREG_BFC,
	GTE_CREG_OFX,
	GTE_CREG_OFY,
	GTE_CREG_H,
	GTE_CREG_DQA,
	GTE_CREG_DQB,
	GTE_CREG_ZSF3,
	GTE_CREG_ZSF4,
	GTE_CREG_FLAG,
	GTE_REG__COUNT
};

extern uint32_t GTE_GetRegister(int reg);
extern void GTE_SetRegister(int reg,uint32_t value);

extern void GTE_RotateTranslateProjectSingle(void);
extern void GTE_RotateTranslateProjectTriple(void);

extern void GTE_NormalClip(void);

extern void GTE_Multiply_V0_Rotation(void);
extern void GTE_Multiply_V1_Rotation(void);
extern void GTE_Multiply_V2_Rotation(void);
extern void GTE_Multiply_IR_Rotation(void);
extern void GTE_Multiply_V0_Light(void);
extern void GTE_Multiply_V1_Light(void);
extern void GTE_Multiply_V2_Light(void);
extern void GTE_Multiply_IR_Light(void);
extern void GTE_MultiplyAdd_V0_Rotation_Translation(void);

extern void GTE_DepthCueSingle(void);
extern void GTE_DepthCueTriple(void);
extern void GTE_DepthCueColorLight(void);

#ifdef __cplusplus
}
#endif

#endif
