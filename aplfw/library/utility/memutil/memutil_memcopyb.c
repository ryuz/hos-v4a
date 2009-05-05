/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memutil_memcopyb.c
 * @brief %jp{メモリ操作}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"


void MemUtil_MemCopyB(void *pDst, const void *pSrc, MEMSIZE Num)
{
	char		*pbDst;
	const char	*pbSrc;
	MEMSIZE		i;
	
	pbDst = (char *)pDst;
	pbSrc = (const char *)pSrc;
	
	for ( i = 0; i < Num; i++ )
	{
		*pbDst++ = *pbSrc++;
	}
}


/* end of file */
