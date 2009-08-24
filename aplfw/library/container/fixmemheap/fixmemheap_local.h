/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fixmemheap_local.h
 * @brief %jp{固定サイズメモリヒープクラス}%en{fixed size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__fixmemheap_local_h__
#define __HOS__fixmemheap_local_h__


#include "library/container/memheap/memheap_local.h"



/** %jp{FixMemHeapクラス}%en{FixMemHeap class} */
typedef struct c_fixmemheap
{
	C_MEMHEAP			MemHeap;		/* 継承 */
	
	void				*pMemBase;		/**< %jp{メモリ先頭ブロックのアドレス} */
	void				**ppFree;		/**< %jp{空きブロックアドレス} */

	MEMSIZE				BlkSize;		/**< %jp{ブロックサイズ} */
	MEMSIZE				BlkNum;			/**< %jp{ブロック個数} */
} C_FIXMEMHEAP;


#ifdef __cplusplus
extern "C" {
#endif

void	FixMemHeap_Constructor(C_FIXMEMHEAP *self, void *pMemBase, MEMSIZE BlkSize,  MEMSIZE BlkNum);
#define FixMemHeap_Destructor(self)			do { } while (0)

void	*FixMemHeap_Alloc(void *pMemHeap, MEMSIZE Size);					/**< メモリの割り当て */
void	*FixMemHeap_ReAlloc(void *pMemHeap, void *pMem, MEMSIZE Size);		/**< メモリの再割り当て */
void	FixMemHeap_Free(void *pMemHeap, void *pMem);						/**< メモリの開放 */
MEMSIZE	FixMemHeap_GetSize(void *pMemHeap, void *pMem);						/**< メモリのサイズ取得 */
MEMSIZE	FixMemHeap_GetAlign(void *pMemHeap);								/**< メモリアライメントの取得 */
MEMSIZE	FixMemHeap_AlignSize(void *pMemHeap, MEMSIZE Size);					/**< サイズをアライメント単位に拡張 */
int     FixMemHeap_IsMember(void *pMemHeap, void *pMem);					/**< メモリがヒープに属しているかチェック */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__fixmemheap_local_h__ */


/* end of file */
