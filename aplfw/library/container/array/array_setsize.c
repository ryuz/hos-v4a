
#include <stdio.h>
#include "array.h"


/* データの追加 */
ARRAY_ERR Array_SetSize(C_ARRAY *self, ARRAY_INDEX Size)
{
	int i;

	if ( self->Size == Size)
	{
		return ARRAY_ERR_OK;
	}
	
	if ( self->Size > Size )	/* 縮小なら */
	{
		/* 縮小分を削除 */
		for ( i = Size; i < self->Size; i++ )
		{
			if ( self->ppArray[i] != NULL )
			{
				MemHeap_Free(self->pMemHeap, self->ppArray[i]);
			}
		}
		self->Size = Size;
	}
	else
	{
		/* 必要ならメモリ拡張 */
		if ( self->ArraySize < Size )
		{
			ARRAY_INDEX NewSize;
			void        **ppNewArray;
			
			NewSize  = Size + ARRAY_SIZE_UNIT;
			NewSize -= NewSize % ARRAY_SIZE_UNIT;
			ppNewArray = (void **)MemHeap_ReAlloc(self->pMemHeap, self->ppArray, NewSize);
			if ( ppNewArray == NULL )
			{
				return ARRAY_ERR_NG;
			}
			self->ppArray   = ppNewArray;
			self->ArraySize = NewSize;
		}

		/* 追加分を初期化 */
		for ( i = self->Size; i < Size; i++ )
		{
			self->ppArray[i] = NULL;
		}
		self->Size = Size;
	}

	return ARRAY_ERR_OK;
}


/* end of file */
