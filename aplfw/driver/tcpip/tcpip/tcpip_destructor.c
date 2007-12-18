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


void TcpIp_Destructor(C_TCPIP *self)
{
	SysMtx_Delete(self->hMtxLock);
	SysMtx_Delete(self->hMtxSend);


	/* 親クラスデストラクタ呼び出し */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* endof file */
