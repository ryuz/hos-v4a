/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_create.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS At91UsartDrv_Methods = 
	{
		{ At91UsartDrv_Delete },
		At91UsartDrv_Open,
		At91UsartDrv_Close,
		At91UsartDrv_IoControl,
		At91UsartDrv_Seek,
		At91UsartDrv_Read,
		At91UsartDrv_Write,
		At91UsartDrv_Flush,
	};


/** 生成 */
HANDLE At91UsartDrv_Create(void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize)
{
	C_AT91USARTDRV *self;
	
	/* メモリ確保 */
	if ( (self = (C_AT91USARTDRV *)SysMem_Alloc(sizeof(C_AT91USARTDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( At91UsartDrv_Constructor(self, &At91UsartDrv_Methods, pRegBase, iIntNum, ulBaseClock, iBufSize) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
