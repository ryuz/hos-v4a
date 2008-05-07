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


/* I/O用メモリの返却(必要に応じてオーバーライドすること) */
void SysMem_FreeIoMem(void *pMem)
{
	SysMem_Free(pMem);
}



/* end of file */
