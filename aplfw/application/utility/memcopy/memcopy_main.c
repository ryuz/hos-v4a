/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memcopy_main.c
 * @brief %jp{メモリコピーコマンド}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "memcopy.h"


int MemCopy_Main(int argc, char *argv[])
{
	void			*pDstAddr;
	void			*pSrcAddr;
	unsigned long	ulSize;
	
	if ( argc < 4 )
	{
		StdIo_PrintFormat(
				"<usage>\n"
				" %s dst src size\n\n",
				argv[0]
			);
		return 1;
	}
	
	/* コマンドライン解析 */
	pDstAddr = (void *)strtoul(argv[1], NULL, 0);
	pSrcAddr = (void *)strtoul(argv[2], NULL, 0);
	ulSize   = strtoul(argv[3], NULL, 0);
	
	/* 表示 */
	StdIo_PrintFormat("Memory Copy: dst:%08lx src:%08lx size:%lu\n", (unsigned long)pDstAddr, pSrcAddr, ulSize);
	
	/* コピー */
	memcpy(pDstAddr, pSrcAddr, ulSize);
	
	
	return 0;
}


/* end of file */
