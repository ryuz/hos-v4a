/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fixmemheap.h
 * @brief %jp{固定サイズメモリヒープクラス}%en{fixed size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__fixmemheap_h__
#define __HOS__fixmemheap_h__


#include "library/container/memheap/memheap_local.h"


typedef struct c_fixmemheap	C_FIXMEMHEAP;


#ifdef __cplusplus
extern "C" {
#endif

C_FIXMEMHEAP *FixMemHeap_Create(void *pMemBase, MEMSIZE BlkSize,  MEMSIZE BlkNum);
void         FixMemHeap_Delete(C_FIXMEMHEAP *self);


#ifdef __cplusplus
}
#endif



#endif	/* __HOS__memheap_h__ */


/* end of file */
