/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"


/* システムメモリの返却 */
MEMSIZE SysMem_GetSize(void *pMem)
{
	return SysMemHeap_GetSize(&SysMem_SysMemHeap, pMem);
}


/* end of file */
