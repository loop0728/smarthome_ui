#ifndef __AUDIODETECT_H__
#define __AUDIODETECT_H__
#include "base_types.h"


#ifdef __cplusplus
extern "C" {               // 告诉编译器下列代码要以C链接约定的模式进行链接
#endif

typedef void* (*VoiceAnalyzeCallback)(int);

HANDLE SSTAR_VoiceDetectInit();
int SSTAR_VoiceDetectDeinit(HANDLE hDSpotter);
int SSTAR_VoiceDetectStart(HANDLE hDSpotter, VoiceAnalyzeCallback pfnCallback);
void SSTAR_VoiceDetectStop();

#ifdef __cplusplus
}
#endif

#endif
