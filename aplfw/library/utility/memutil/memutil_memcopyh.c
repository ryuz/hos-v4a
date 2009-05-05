/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memutil_memcopyh.c
 * @brief %jp{メモリ操作}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"


void MemUtil_MemCopyH(void *pDst, const void *pSrc, MEMSIZE Num)
{
	short		*phDst;
	const short	*phSrc;
	MEMSIZE		i;
	
	phDst = (short *)pDst;
	phSrc = (const short *)pSrc;
	
	for ( i = 0; i < Num; i++ )
	{
		*phDst++ = *phSrc++;
	}
}


/* end of file */
