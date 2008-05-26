/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  valmemheap_alloc.c
 * @brief %jp{可変サイズメモリヒープクラス}%en{variable size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "valmemheap_local.h"



/** %jp{メモリの再割り当て} */
void *ValMemHeap_ReAlloc(void *pMemHeap, void *pMem, MEMSIZE Size)
{
	C_VALMEMHEAP	*self;
	void			*pNewMem;
	
	/* upper cast */
	self = (C_VALMEMHEAP *)pMemHeap;

	/* とりあえず手抜き */
	if ( (pNewMem = ValMemHeap_Alloc(self, Size)) != NULL )
	{
		memcpy(pNewMem, pMem, ValMemHeap_GetSize(self, pMem));
		ValMemHeap_Free(self, pMem);
	}
	
	return pNewMem;
}


/* end of file */
