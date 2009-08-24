/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  automemheap_alloc.c
 * @brief %jp{メモリヒープクラス}%en{auto size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "automemheap_local.h"



/** %jp{メモリの割り当て} */
void *AutoMemHeap_Alloc(void *pMemHeap, MEMSIZE Size)
{
	C_AUTOMEMHEAP	*self;
	void			*pMem;
	int				i;
	
	/* upper cast */
	self = (C_AUTOMEMHEAP *)pMemHeap;
	
	if ( Size <= self->FixSize )
	{
		T_AUTOMEMHEAP_FIX	*pFixHeap;
		
		/* 固定サイズプールから取る */
		for ( i = 0, pFixHeap = self->pFixList; pFixHeap != NULL; pFixHeap = pFixHeap->pNext, i++ )
		{
			if ( (pMem = FixMemHeap_Alloc(&pFixHeap->FixMemHeap, Size)) != NULL )
			{
				return pMem;
			}
			i++;
		}
		
		/* 新規確保 */
		if ( i < self->iFixMax )
		{
			if ( (pFixHeap = MemHeap_Alloc(self->pMemHeap, sizeof(T_AUTOMEMHEAP_FIX) + (self->FixSize * self->FixNum))) != NULL )
			{
				pMem = (void *)((char *)pFixHeap + sizeof(T_AUTOMEMHEAP_FIX));
				FixMemHeap_Constructor(&pFixHeap->FixMemHeap, pMem, self->FixSize, self->FixNum);
				
				/* リストに追加 */
				pFixHeap->pNext = self->pFixList;
				self->pFixList  = pFixHeap;
				
				if ( (pMem = FixMemHeap_Alloc(&pFixHeap->FixMemHeap, Size)) != NULL )
				{
					return pMem;
				}
			}
		}
	}
	else if ( Size < self->ValSize )
	{
		T_AUTOMEMHEAP_VAL	*pValHeap;
		
		/* 可変サイズプールから取る */
		for ( i = 0, pValHeap = self->pValList; pValHeap != NULL; pValHeap = pValHeap->pNext, i++ )
		{
			if ( (pMem = ValMemHeap_Alloc(&pValHeap->ValMemHeap, Size)) != NULL )
			{
				return pMem;
			}
			i++;
		}
		
		/* 新規確保 */
		if ( i < self->iValMax )
		{
			if ( (pValHeap = MemHeap_Alloc(self->pMemHeap, sizeof(T_AUTOMEMHEAP_VAL) + self->ValSize)) != NULL )
			{
				pMem = (void *)((char *)pValHeap + sizeof(T_AUTOMEMHEAP_VAL));
				ValMemHeap_Constructor(&pValHeap->ValMemHeap, pMem, self->ValSize, MemHeap_AlignSize(self->pMemHeap, 1));
				
				/* リストに追加 */
				pValHeap->pNext = self->pValList;
				self->pValList  = pValHeap;
				
				if ( (pMem = ValMemHeap_Alloc(&pValHeap->ValMemHeap, Size)) != NULL )
				{
					return pMem;
				}
			}
		}
	}
	
	/* 直接取る */
	{
		T_AUTOMEMHEAP_MEM	*pMemHeap;
		
		if ( (pMemHeap = MemHeap_Alloc(self->pMemHeap, MemHeap_AlignSize(self->pMemHeap, sizeof(T_AUTOMEMHEAP_MEM)) + Size)) != NULL )
		{
			pMem = (void *)((char *)pMemHeap + MemHeap_AlignSize(self->pMemHeap, sizeof(T_AUTOMEMHEAP_MEM)));
			
			/* リストに追加 */
			pMemHeap->pNext = self->pMemList;
			self->pMemList  = pMemHeap;

			return pMem;
		}
	}
	
	return NULL;
}


/* end of file */
