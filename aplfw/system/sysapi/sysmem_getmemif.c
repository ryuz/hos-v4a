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


static const T_MEMIF SysMem_MemIf =
{
	SysMem_Alloc,
	SysMem_ReAlloc,
	SysMem_Free,
	SysMem_GetSize,
};


/* メモリインターフェースの取得 */
const T_MEMIF *SysMem_GetMemIf(void)
{
	return &SysMem_MemIf;
}


/* end of file */
