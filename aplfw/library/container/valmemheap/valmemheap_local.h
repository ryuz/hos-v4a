/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  valmemheap_local.h
 * @brief %jp{可変サイズメモリヒープクラス}%en{variable size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__valmemheap_local_h__
#define __HOS__valmemheap_local_h__


#include "library/container/memheap/memheap_local.h"


#define VALMEMHEAP_USING		0x1234			/**< %jp{使用中} */
#define VALMEMHEAP_FREE			0xabcd			/**< %jp{未使用} */


/** %jp{ヒープメモリブロック} */
typedef struct t_valmemheap_memblk
{
	struct t_valmemheap_memblk*	pPrev;			/**< %jp{前のブロック} */
	MEMSIZE						Size;			/**< %jp{ブロックのサイズ} */
	int							iFlag;			/**< %jp{使用中フラグ} */
} T_VALMEMHEAP_MEMBLK;


/** %jp{ValMemHeapクラス}%en{ValMemHeap class} */
typedef struct c_valmemheap
{
	C_MEMHEAP			MemHeap;		/* 継承 */
	
	T_VALMEMHEAP_MEMBLK	*pMemBase;		/**< %jp{メモリ先頭ブロックのアドレス} */
	MEMSIZE				MemSize;		/**< %jp{メモリサイズ} */
	int					AlignMask;		/**< %jp{メモリアライメントサイズ} */
} C_VALMEMHEAP;


#ifdef __cplusplus
extern "C" {
#endif

void	ValMemHeap_Constructor(C_VALMEMHEAP *self, void *pMemBase, MEMSIZE MemSize, int AlignSize);
#define ValMemHeap_Destructor(self)			do { } while (0)

void	*ValMemHeap_Alloc(void *pMemHeap, MEMSIZE Size);					/**< メモリの割り当て */
void	*ValMemHeap_ReAlloc(void *pMemHeap, void *pMem, MEMSIZE Size);		/**< メモリの再割り当て */
void	ValMemHeap_Free(void *pMemHeap, void *pMem);						/**< メモリの開放 */
MEMSIZE	ValMemHeap_GetSize(void *pMemHeap, void *pMem);						/**< メモリのサイズ取得 */
MEMSIZE	ValMemHeap_GetAlign(void *pMemHeap);								/**< メモリアライメントの取得 */
MEMSIZE	ValMemHeap_AlignSize(void *pMemHeap, MEMSIZE Size);					/**< サイズをアライメント単位に拡張 */
int     ValMemHeap_IsMember(void *pMemHeap, void *pMem);					/**< メモリがヒープに属しているかチェック */

#define ValMemHeap_GetMemBlockSize(self)	(ValMemHeap_AlignSize((self), sizeof(T_VALMEMHEAP_MEMBLK)))

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__valmemheap_local_h__ */


/* end of file */
