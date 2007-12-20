/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_create.c
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mn103scdrv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS Mn103ScDrv_Methods = 
	{
		{ Mn103ScDrv_Delete },
		Mn103ScDrv_Open,
		Mn103ScDrv_Close,
		Mn103ScDrv_IoControl,
		Mn103ScDrv_Seek,
		Mn103ScDrv_Read,
		Mn103ScDrv_Write,
		Mn103ScDrv_Flush,
	};


/** 生成 */
HANDLE Mn103ScDrv_Create(void *pRegBase, int iIntNumRx, int iIntNumTx, int iBufSize)
{
	C_MN103SCDRV *self;
	
	/* メモリ確保 */
	if ( (self = (C_MN103SCDRV *)SysMem_Alloc(sizeof(C_MN103SCDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( Mn103ScDrv_Constructor(self, &Mn103ScDrv_Methods, pRegBase, iIntNumRx, iIntNumTx, iBufSize) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
