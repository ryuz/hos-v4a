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


/* システムメモリの返却 */
void  SysMem_Free(void *pMem)
{
	SysMemHeap_Free(&SysMem_SysMemHeap, pMem);
}



/* end of file */
