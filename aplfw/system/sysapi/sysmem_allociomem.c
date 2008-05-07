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


/* I/O用メモリのの割り当て(必要に応じてオーバーライドすること) */
void *SysMem_AllocIoMem(MEMSIZE Size)
{
	return SysMem_Alloc(Size);
}


/* end of file */
