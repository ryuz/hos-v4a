/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  tcpip.h
 * @brief %jp{TCP/IP プロトコル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "tcpip_local.h"


void TcpIp_Delete(C_DRVOBJ *pDrvObj)
{
	C_TCPIP	*self;
	
	/* upper cast */
	self = (C_TCPIP *)pDrvObj;

	SysMtx_Delete(self->hMtxLock);
	SysMtx_Delete(self->hMtxSend);


	/* 親クラスデストラクタ呼び出し */
	ChrDrv_Delete(&self->ChrDrv);
}


/* endof file */
