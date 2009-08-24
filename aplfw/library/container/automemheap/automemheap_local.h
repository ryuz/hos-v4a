/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  automemheap_local.h
 * @brief %jp{メモリヒープクラス}%en{auto size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__automemheap_local_h__
#define __HOS__automemheap_local_h__


#include "library/container/memheap/memheap_local.h"
#include "library/container/valmemheap/valmemheap_local.h"
#include "library/container/fixmemheap/fixmemheap_local.h"


typedef struct t_automemheap_fix
{
	struct t_automemheap_fix	*pNext;
	C_FIXMEMHEAP				FixMemHeap;
} T_AUTOMEMHEAP_FIX;

typedef struct t_automemheap_val
{
	struct t_automemheap_val	*pNext;
	C_VALMEMHEAP				ValMemHeap;
} T_AUTOMEMHEAP_VAL;

typedef struct t_automemheap_mem
{
	struct t_automemheap_mem	*pNext;
} T_AUTOMEMHEAP_MEM;


/** %jp{AutoMemHeapクラス}%en{AutoMemHeap class} */
typedef struct c_automemheap
{
	C_MEMHEAP			MemHeap;		/**< 継承 */

	C_MEMHEAP			*pMemHeap;		/**< 基底ヒープ */
	
	T_AUTOMEMHEAP_FIX	*pFixList;		/**< 小ブロック用固定サイズヒープリスト */
	T_AUTOMEMHEAP_VAL	*pValList;		/**< 中ブロック用可変サイズヒープリスト */
	T_AUTOMEMHEAP_MEM	*pMemList;		/**< 大ブロック用リスト */
	
	MEMSIZE				FixSize;		/**< 小ブロック閾値 */
	MEMSIZE				FixNum;			/**< 小ブロック個数 */
	MEMSIZE				ValSize;		/**< 中ブロック閾値 */
	
	int					iFixMax;
	int					iValMax;
} C_AUTOMEMHEAP;


#ifdef __cplusplus
extern "C" {
#endif

void       AutoMemHeap_Constructor(C_AUTOMEMHEAP *self, C_MEMHEAP *pMemHeap);	/**< コンストラクタ */
void       AutoMemHeap_Destructor(C_AUTOMEMHEAP *self);							/**< デストラクタ */

void	  *AutoMemHeap_Alloc(void *pMemHeap, MEMSIZE Size);						/**< メモリの割り当て */
void	  *AutoMemHeap_ReAlloc(void *pMemHeap, void *pMem, MEMSIZE Size);		/**< メモリの再割り当て */
void	   AutoMemHeap_Free(void *pMemHeap, void *pMem);						/**< メモリの開放 */
MEMSIZE	   AutoMemHeap_GetSize(void *pMemHeap, void *pMem);						/**< メモリのサイズ取得 */
MEMSIZE	   AutoMemHeap_GetAlign(void *pMemHeap);								/**< メモリアライメントの取得 */
MEMSIZE	   AutoMemHeap_AlignSize(void *pMemHeap, MEMSIZE Size);					/**< サイズをアライメント単位に拡張 */
int        AutoMemHeap_IsMember(void *pMemHeap, void *pMem);					/**< サイズをアライメント単位に拡張 */

C_MEMHEAP *AutoMemHeap_SearchHeap(C_AUTOMEMHEAP *self, void *pMem);				/**< 所属するヒープを検索 */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__automemheap_local_h__ */


/* end of file */
