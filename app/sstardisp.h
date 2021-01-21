#ifndef __SSTARDISP__H__
#define __SSTARDISP__H__

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

#include <mi_disp_datatype.h>

int sstar_disp_init(MI_DISP_PubAttr_t* pstDispPubAttr);
int sstar_disp_Deinit(MI_DISP_PubAttr_t *pstDispPubAttr);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__SSTARDISP__H__
