

#ifndef __HOS__memory_h__
#define __HOS__memory_h__


#include "library/container/memheap/memheap.h"

#ifdef __cplusplus
extern "C" {
#endif

void      *Memory_Alloc(long lSize);		/* メモリの割り当て */
void      Memory_Free(void *pMem);			/* メモリの割り当て */
C_MEMHEAP *Memory_GetMemHeap(void);			/* メモリインターフェースの取得 */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__memory_h__ */
