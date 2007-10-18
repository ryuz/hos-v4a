/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ipether.h
 * @brief %jp{Ether上にIPプロトコルを実装(つまりMAC層近辺)}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "tcpip_local.h"


/* 仮想関数テーブル */
static const T_DRVOBJ_METHODS TcpIp_Methods = 
	{
		Tcpip_Delete,
		Tcpip_Open,
		Tcpip_Close,
		Tcpip_IoControl,
		Tcpip_Seek,
		Tcpip_Read,
		Tcpip_Write,
		Tcpip_Flush,
	};


/**< コンストラクタ */
void Tcpip_Create(C_TCPIP *self, HANDLE hIp)
{
	/* 親クラスコンストラクタ呼び出し */
	ChrDrv_Create(&self->ChrDrv, &TcpIp_Methods);
	
	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	self->hIp        = hIp;
	
	/* ミューテックス生成 */
	self->hMtxLock = SysMtx_Create();
	self->hMtxSend = SysMtx_Create();
	
	/* 受信プロセス生成 */
	self->hPrcRecv = SysPrc_Create(Tcpip_Recv, (VPARAM)self, 1024, 2);
	SysPrc_Start(self->hPrcRecv);
}


/* endof file */
