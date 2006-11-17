

#ifndef __HOS__memif_h__
#define __HOS__memif_h__


#include "system/type/type.h"


#define MEMIF_MEMALIGN			MEMALIGN
#define MEMIF_ALIGNSIZE(x)		(((x) + MEMIF_MEMALIGN - 1) & ~(MEMIF_MEMALIGN - 1))


/* メモリインターフェース */
typedef struct t_memif
{
	void    *(*pfncAlloc)(MEMSIZE Size);				/* メモリの割り当て */
	void    *(*pfncReAlloc)(void *pMem, MEMSIZE Size);	/* メモリの再割り当て */
	void    (*pfncFree)(void *pMem);					/* メモリの開放 */
	MEMSIZE (*pfncGetSize)(void *pMem);					/* メモリのサイズ取得 */
} T_MEMIF;


#define MemIf_Alloc(pMemIf, Size)			((pMemIf)->pfncAlloc((Size)))
#define MemIf_ReAlloc(pMemIf, pMem, Size)	((pMemIf)->pfncReAlloc((pMem), (Size)))
#define MemIf_Free(pMemIf, pMem)			((pMemIf)->pfncFree((pMem)))
#define MemIf_GetSize(pMemIf, pMem)			((pMemIf)->pfncGetSize((pMem)))
#define MemIf_GetAlign(pMemIf)				MEMIF_MEMALIGN
#define MemIf_AlignSize(pMemIf, Size)		MEMIF_ALIGNSIZE(Size)


#endif	/* __HOS__memif_h__ */

