/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"



/* %jp{メモリインターフェースの取得} */
C_MEMHEAP *SysMem_GetMemHeap(void)
{
	return (C_MEMHEAP *)&SysMem_SysMemHeap;
}


/* end of file */
