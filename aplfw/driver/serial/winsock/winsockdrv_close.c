/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  winsockdrv.h
 * @brief %jp{WinSockでシリアルを擬似するドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "winsockdrv_local.h"



/** クローズ */
FILE_ERR WinSockDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_WINSOCKDRV *self;

	/* upper cast */
	self = (C_WINSOCKDRV *)pDrvObj;

	if ( --self->iOpenCount == 0 )
	{
		closesocket(self->sock);
	}

	return FILE_ERR_OK;
}



/* end of file */
