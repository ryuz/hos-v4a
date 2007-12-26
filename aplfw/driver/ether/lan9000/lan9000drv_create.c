/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000drv.h
 * @brief %jp{LAN9000ファミリー用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9000drv_local.h"


/* 仮想関数テーブル */
static const T_DRVOBJ_METHODS Lan9000Drv_Methods = 
	{
		{ Lan9000Drv_Delete },
		Lan9000Drv_Open,
		Lan9000Drv_Close,
		Lan9000Drv_IoControl,
		Lan9000Drv_Seek,
		Lan9000Drv_Read,
		Lan9000Drv_Write,
		Lan9000Drv_Flush,
	};


/** 生成 */
HANDLE Lan9000Drv_Create(void *pRegBase, int iIntNum)
{
	C_LAN9000DRV *self;
	
	/* メモリ確保 */
	if ( (self = (C_LAN9000DRV *)SysMem_Alloc(sizeof(C_LAN9000DRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( Lan9000Drv_Constructor(self, &Lan9000Drv_Methods, pRegBase, iIntNum) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
