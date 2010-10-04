/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  jellyi2cdrv_create.c
 * @brief %jp{Jelly I2Cデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyi2cdrv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS JellyI2cDrv_Methods = 
	{
		{ JellyI2cDrv_Delete },
		JellyI2cDrv_Open,
		JellyI2cDrv_Close,
		JellyI2cDrv_IoControl,
		NULL,
		NULL,
		NULL,
		NULL,
	};


/** 生成 */
HANDLE JellyI2cDrv_Create(void *pRegBase, unsigned long ulBaseClock)
{
	C_JELLYI2CDRV *self;
	
	/* メモリ確保 */
	if ( (self = (C_JELLYI2CDRV *)SysMem_Alloc(sizeof(C_JELLYI2CDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( JellyI2cDrv_Constructor(self, &JellyI2cDrv_Methods, pRegBase, ulBaseClock) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
