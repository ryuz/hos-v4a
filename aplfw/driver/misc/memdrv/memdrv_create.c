/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdrv.h
 * @brief %jp{メモリマップドファイル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "memdrv_local.h"




/** 生成 */
HANDLE MemDrv_Create(void *pMemAddr, FILE_POS MemSize, FILE_POS IniSize, int iAttr)
{
	C_MEMDRV *self;
	
	/* メモリ確保 */
	if ( (self = (C_MEMDRV *)SysMem_Alloc(sizeof(C_MEMDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	MemDrv_Constructor(self, NULL, pMemAddr, MemSize, IniSize, iAttr);
	
	return (HANDLE)self;
}


/* end of file */
