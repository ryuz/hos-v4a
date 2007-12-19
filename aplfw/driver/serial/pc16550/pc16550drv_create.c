/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{PC16550用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550drv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS Pc16550Drv_Methods = 
	{
		{ Pc16550Drv_Delete },
		Pc16550Drv_Open,
		Pc16550Drv_Close,
		Pc16550Drv_IoControl,
		Pc16550Drv_Seek,
		Pc16550Drv_Read,
		Pc16550Drv_Write,
		Pc16550Drv_Flush,
	};


/** コンストラクタ */
HANDLE Pc16550Drv_Create(void *pRegAddr, unsigned int uiRegStep, int iIntNum, long lSysClock, int iBufSize)
{
	C_PC16550DRV *self;
	
	/* メモリ確保 */
	if ( (self = (C_PC16550DRV *)SysMem_Alloc(sizeof(C_PC16550DRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( Pc16550Drv_Constructor(self, &Pc16550Drv_Methods, pRegAddr, uiRegStep, iIntNum, lSysClock, iBufSize) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
