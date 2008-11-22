/** 
 * Hyper Operating System  Application Framework
 *
 * @file  jellyuartdrv_create.c
 * @brief %jp{JellyUart オブジェクト生成}%en{JellyUart  create object}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyuartdrv_local.h"


/** %jp{オブジェクト生成}%en{create object} */
HANDLE JellyUartDrv_Create(void *pRegBase, int iIntNumRx, int iIntNumTx, int iBufSize)
{
	C_JELLYUARTDRV *self;
	
	/* %jp{メモリ確保}%en{Memory allocate} */
	if ( (self = (C_JELLYUARTDRV *)SysMem_Alloc(sizeof(C_JELLYUARTDRV))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* %jp{コンストラクタ呼び出し}%en{constructor} */
	if ( JellyUartDrv_Constructor(self, NULL, pRegBase, iIntNumRx, iIntNumTx, iBufSize) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */
