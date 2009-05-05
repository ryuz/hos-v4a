/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memutil_memcopyw.c
 * @brief %jp{メモリ操作}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"


void MemUtil_MemCopyW(void *pDst, const void *pSrc, MEMSIZE Num)
{
	long		*pwDst;
	const long	*pwSrc;
	MEMSIZE		i;
	
	pwDst = (long *)pDst;
	pwSrc = (const long *)pSrc;
	
	for ( i = 0; i < Num; i++ )
	{
		*pwDst++ = *pwSrc++;
	}
}


/* end of file */
