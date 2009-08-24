/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memheap.h
 * @brief %jp{メモリヒープクラス(抽象クラス)}%en{memory heap class(abstract class)}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__memheap_h__
#define __HOS__memheap_h__


#include "system/type/type.h"



/** %jp{MemHeapクラス 仮想関数テーブル}%en{MemHeap class virtual function table} */
typedef struct t_memheap_methods
{
	void	*(*pfncAlloc)(void *pMemHeap, MEMSIZE Size);					/**< メモリの割り当て */
	void	*(*pfncReAlloc)(void *pMemHeap, void *pMem, MEMSIZE Size);		/**< メモリの再割り当て */
	void	(*pfncFree)(void *pMemHeap, void *pMem);						/**< メモリの開放 */
	MEMSIZE	(*pfncGetSize)(void *pMemHeap, void *pMem);						/**< メモリのサイズ取得 */
	MEMSIZE	(*pfncGetAlign)(void *pMemHeap);								/**< メモリアライメントの取得 */
	MEMSIZE	(*pfncAlignSize)(void *pMemHeap, MEMSIZE Size);					/**< サイズをアライメント単位に拡張 */
	int		(*pfncIsMember)(void *pMemHeap, void *pMem);					/**< メモリがヒープに属しているかチェック */
} T_MEMHEAP_METHODS;


/** %jp{MemHeapクラス}%en{MemHeap class} */
typedef struct c_memheap
{
	const T_MEMHEAP_METHODS		*pMethods;
} C_MEMHEAP;



#ifdef __cplusplus
extern "C" {
#endif

#define MemHeap_Alloc(self, Size)				((self)->pMethods->pfncAlloc((self), (Size)))
#define MemHeap_ReAlloc(self, pMem, Size)		((self)->pMethods->pfncReAlloc((self), (pMem), (Size)))
#define MemHeap_Free(self, pMem)				((self)->pMethods->pfncFree((self), (pMem)))
#define MemHeap_GetSize(self, pMem)				((self)->pMethods->pfncGetSize((self), (pMem)))
#define MemHeap_GetAlign(self)					((self)->pMethods->pfncGetAlign((self)))
#define MemHeap_AlignSize(self, Size)			((self)->pMethods->pfncAlignSize((self), (Size)))
#define MemHeap_IsMember(self, pMem)			((self)->pMethods->pfncIsMember((self), (pMem)))

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__memheap_h__ */


/* end of file */
