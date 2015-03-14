#ifndef H_SPU_H
#define H_SPU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SPU_VOICECOUNT 24

extern void SPU_SetVolumeLeft(uint16_t value);
extern void SPU_SetVolumeRight(uint16_t value);

extern void SPU_SetReverbVolumeLeft(uint16_t value);
extern void SPU_SetReverbVolumeRight(uint16_t value);

extern uint16_t SPU_Voice_GetVolumeLeft(int voice);
extern void SPU_Voice_SetVolumeLeft(int voice,uint16_t value);
extern uint16_t SPU_Voice_GetVolumeRight(int voice);
extern void SPU_Voice_SetVolumeRight(int voice,uint16_t value);
extern uint16_t SPU_Voice_GetSampleRate(int voice);
extern void SPU_Voice_SetSampleRate(int voice,uint16_t value);
extern uint16_t SPU_Voice_GetStartAddress(int voice);
extern void SPU_Voice_SetStartAddress(int voice,uint16_t value);
extern uint16_t SPU_Voice_GetADSRLow(int voice);
extern void SPU_Voice_SetADSRLow(int voice,uint16_t value);
extern uint16_t SPU_Voice_GetADSRHigh(int voice);
extern void SPU_Voice_SetADSRHigh(int voice,uint16_t value);
extern uint16_t SPU_Voice_GetADSRVolume(int voice);
extern void SPU_Voice_SetADSRVolume(int voice,uint16_t value);
extern uint16_t SPU_Voice_GetLoopAddress(int voice);
extern void SPU_Voice_SetLoopAddress(int voice,uint16_t value);

extern void SPU_NoteOnLow(uint16_t value);
extern void SPU_NoteOnHigh(uint16_t value);
extern void SPU_NoteOffLow(uint16_t value);
extern void SPU_NoteOffHigh(uint16_t value);
extern void SPU_SetFMLow(uint16_t value);
extern void SPU_SetFMHigh(uint16_t value);
extern void SPU_SetNoiseLow(uint16_t value);
extern void SPU_SetNoiseHigh(uint16_t value);
extern uint16_t SPU_GetReverbLow(void);
extern void SPU_SetReverbLow(uint16_t value);
extern uint16_t SPU_GetReverbHigh(void);
extern void SPU_SetReverbHigh(uint16_t value);
extern void SPU_SetReverbStartAddress(uint16_t value);

extern uint16_t SPU_GetTransferAddress(void);
extern void SPU_SetTransferAddress(uint16_t value);
extern void SPU_Write(uint16_t value);

extern uint16_t SPU_ReadControlRegister(void);
extern void SPU_WriteControlRegister(uint16_t value);
extern void SPU_SetTransferMode(uint16_t value);
extern uint16_t SPU_ReadStatusRegister(void);

extern void SPU_SetCDVolumeLeft(uint16_t value);
extern void SPU_SetCDVolumeRight(uint16_t value);
extern void SPU_SetExternVolumeLeft(uint16_t value);
extern void SPU_SetExternVolumeRight(uint16_t value);
extern uint16_t SPU_GetCurrentVolumeLeft(void);
extern uint16_t SPU_GetCurrentVolumeRight(void);

extern void SPU_ConfigureReverb(int code,uint16_t value);

extern uint16_t SPU_Voice_GetCurrentVolumeLeft(int voice);
extern uint16_t SPU_Voice_GetCurrentVolumeRight(int voice);

#ifdef __cplusplus
}
#endif

#endif
