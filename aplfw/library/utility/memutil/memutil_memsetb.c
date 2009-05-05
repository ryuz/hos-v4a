/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memutil_memsetb.c
 * @brief %jp{メモリ操作}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"


void MemUtil_MemSetB(void *pDst, unsigned char ubData, MEMSIZE Num)
{
	unsigned char	*pubDst;
	MEMSIZE			i;
	
	pubDst = (unsigned char *)pDst;
	
	for ( i = 0; i < Num; i++ )
	{
		*pubDst++ = ubData;
	}
}


/* end of file */
