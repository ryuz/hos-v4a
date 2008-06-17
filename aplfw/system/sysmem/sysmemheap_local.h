/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysmemheap_alloc.c
 * @brief %jp{システムメモリヒープクラス}%en{system memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__sysmemheap_local_h__
#define __HOS__sysmemheap_local_h__


#include "library/container/memheap/memheap_local.h"
#include "system/sysapi/sysapi.h"



/** %jp{SysMemHeapクラス}%en{SysMemHeap class} */
typedef struct c_sysmemheap
{
	C_MEMHEAP			MemHeap;		/* 継承 */
	
	C_MEMHEAP			*pMemHeap;		/* 委譲関係 */
	SYSMTX_HANDLE		hMtx;
} C_SYSMEMHEAP;


#ifdef __cplusplus
extern "C" {
#endif

void	SysMemHeap_Constructor(C_SYSMEMHEAP *self, C_MEMHEAP *pMemHeap);
void    SysMemHeap_Destructor(C_SYSMEMHEAP *self);

void	*SysMemHeap_Alloc(void *pMemHeap, MEMSIZE Size);					/**< メモリの割り当て */
void	*SysMemHeap_ReAlloc(void *pMemHeap, void *pMem, MEMSIZE Size);		/**< メモリの再割り当て */
void	SysMemHeap_Free(void *pMemHeap, void *pMem);						/**< メモリの開放 */
MEMSIZE	SysMemHeap_GetSize(void *pMemHeap, void *pMem);						/**< メモリのサイズ取得 */
MEMSIZE	SysMemHeap_GetAlign(void *pMemHeap);								/**< メモリアライメントの取得 */
MEMSIZE	SysMemHeap_AlignSize(void *pMemHeap, MEMSIZE Size);					/**< サイズをアライメント単位に拡張 */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__sysmemheap_local_h__ */


/* end of file */
