#include "memory.h"
#include "system/sysapi/sysapi.h"


/* メモリの割り当て(ユーザー用) */
void *Memory_Alloc(long lSize)
{
	if ( SysCtx_IsIsr() )
	{
		for ( ; ; ) ;	/* assert */
		
		return NULL;
	}

	/* とりあえずそのまま、そのうちプロセス終了で開放できるように改造 */
	return SysMem_Alloc(lSize);
}

/* メモリの割り当て(ユーザー用) */
void  Memory_Free(void *pMem)
{
	SysMem_Free(pMem);
}


/* メモリヒープクラスの取得(ユーザー用) */
C_MEMHEAP *Memory_GetMemHeap(void)
{
	return SysMem_GetMemHeap();
}

