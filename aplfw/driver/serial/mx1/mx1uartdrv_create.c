/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_create.c
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mx1uartdrv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS Mx1UartDrv_Methods = 
	{
		{ Mx1UartDrv_Delete },
		Mx1UartDrv_Open,
		Mx1UartDrv_Close,
		Mx1UartDrv_IoControl,
		Mx1UartDrv_Seek,
		Mx1UartDrv_Read,
		Mx1UartDrv_Write,
		Mx1UartDrv_Flush,
	};


/** 生成 */
HANDLE Mx1UartDrv_Create(void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize)
{
	C_MX1UARTDRV *self;
	
	/* メモリ確保 */
	if ( (self = (C_MX1UARTDRV *)SysMem_Alloc(sizeof(C_MX1UARTDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( Mx1UartDrv_Constructor(self, &Mx1UartDrv_Methods, pRegBase, iIntNum, ulBaseClock, iBufSize) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
