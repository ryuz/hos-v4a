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


void MemUtil_MemSetH(void *pDst, unsigned short uhData, MEMSIZE Num)
{
	unsigned short	*puhDst;
	MEMSIZE			i;
	
	puhDst = (unsigned short *)pDst;
	
	for ( i = 0; i < Num; i++ )
	{
		*puhDst++ = uhData;
	}
}


/* end of file */
