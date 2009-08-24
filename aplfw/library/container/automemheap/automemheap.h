/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  automemheap.h
 * @brief %jp{メモリヒープクラス}%en{auto size memory heap class}
 *
 * Copyright (C) 2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__automemheap_h__
#define __HOS__automemheap_h__


#include "library/container/memheap/memheap_local.h"


typedef struct c_automemheap	C_AUTOMEMHEAP;


#ifdef __cplusplus
extern "C" {
#endif

C_AUTOMEMHEAP *AutoMemHeap_Create(C_MEMHEAP *pMemHeap);
void          AutoMemHeap_Delete(C_AUTOMEMHEAP *self);

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__memheap_h__ */


/* end of file */
