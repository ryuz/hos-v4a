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


static const C_MEMIF SysMem_MemIf =
{
	SysMem_Alloc,
	SysMem_ReAlloc,
	SysMem_Free,
	SysMem_GetSize,
};


/* %jp{メモリインターフェースの取得} */
C_MEMIF *SysMem_GetMemIf(void)
{
	return (C_MEMIF *)&SysMem_MemIf;
}


/* end of file */
