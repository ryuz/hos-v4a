/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
* http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS SciDrv_Methods = 
	{
		{ SciDrv_Delete },
		SciDrv_Open,
		SciDrv_Close,
		SciDrv_IoControl,
		SciDrv_Seek,
		SciDrv_Read,
		SciDrv_Write,
		SciDrv_Flush,
	};


/** 生成 */
HANDLE SciDrv_Create(void *pRegBase, int iIntNum, unsigned long ulSysClock, int iBufSize)
{
	C_SCIDRV *self;
	
	/* メモリ確保 */
	if ( (self = (C_SCIDRV *)SysMem_Alloc(sizeof(C_SCIDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( SciDrv_Constructor(self, &SciDrv_Methods, pRegBase, iIntNum, ulSysClock, iBufSize) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
