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


/* システムメモリの再割り当て */
void *SysMem_ReAlloc(void *pMem, MEMSIZE Size)
{
	return SysMemHeap_ReAlloc(&SysMem_SysMemHeap, pMem, Size);
}


/* end of file */
