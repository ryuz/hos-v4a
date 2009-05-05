/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memutil_memsetw.c
 * @brief %jp{メモリ操作}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"


void MemUtil_MemSetW(void *pDst, unsigned long uwData, MEMSIZE Num)
{
	unsigned long	*puwDst;
	MEMSIZE			i;
	
	puwDst = (unsigned long *)pDst;
	
	for ( i = 0; i < Num; i++ )
	{
		*puwDst++ = uwData;
	}
}


/* end of file */
