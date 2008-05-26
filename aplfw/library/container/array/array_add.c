
#include <stdio.h>
#include <string.h>
#include "array.h"


/* データの追加 */
ARRAY_ERR Array_Add(C_ARRAY *self, const void *pData, long lSize)
{
	void        *pMem;
	ARRAY_INDEX Index;
	ARRAY_ERR   err;

	/* メモリ確保 */
	if ( (pMem = (void *)MemHeap_Alloc(self->pMemHeap, lSize)) == NULL )
	{
		return ARRAY_ERR_NG;
	}

	/* 末尾に追加 */
	Index = self->Size;

	/* サイズ拡張 */
	if ( (err = Array_SetSize(self, self->Size + 1)) != ARRAY_ERR_OK )
	{
		MemHeap_Free(self->pMemHeap, pMem);
		return err;
	}
	
	/* データ格納 */
	memcpy(pMem, pData, lSize);
	self->ppArray[Index] = pMem;

	return ARRAY_ERR_OK;
}


/* end of file */
