/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{SCI用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


/** クローズ */
FILE_ERR SciDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_SCIDRV	*self;
	
	/* upper cast */
	self = (C_SCIDRV *)pDrvObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SciHal_EnableInterrupt(&self->SciHal, 0);
		SciHal_Stop(&self->SciHal);
		StreamBuf_Clear(&self->StmBufRecv);
	}
	
	/* ディスクリプタ削除 */
	SysMem_Free(pFileObj);
	
	return FILE_ERR_OK;
}


/* end of file */
