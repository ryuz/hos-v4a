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
		TcpIp_Delete,
		TcpIp_Open,
		TcpIp_Close,
		TcpIp_IoControl,
		TcpIp_Seek,
		TcpIp_Read,
		TcpIp_Write,
		TcpIp_Flush,
	};


/**< コンストラクタ */
FILE_ERR TcpIp_Create(C_TCPIP *self, const char *pszIp)
{
	/* IP層オープン */
	self->hIp = File_Open(pszIp, FILE_OPEN_READ | FILE_OPEN_WRITE | FILE_OPEN_EXIST);
	if ( self->hIp == HANDLE_NULL )
	{
		return FILE_ERR_NG;
	}

	/* 親クラスコンストラクタ呼び出し */
	ChrDrv_Create(&self->ChrDrv, &TcpIp_Methods);
	
	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	
	/* ミューテックス生成 */
	self->hMtxLock = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	self->hMtxSend = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	
	/* 受信プロセス生成 */
	self->hPrcRecv = SysPrc_Create(TcpIp_Recv, (VPARAM)self, 1024, 2, SYSPRC_ATTR_NORMAL);
	
	return FILE_ERR_OK;
}


/* endof file */
