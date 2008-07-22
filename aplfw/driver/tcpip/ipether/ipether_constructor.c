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
#include "ipether_local.h"


/** コンストラクタ */
FILE_ERR IpEther_Constructor(C_IPETHER *self, const T_DRVOBJ_METHODS *pMethods, const char *pszEther, const T_IPETHER_INF *pInf)
{
	/* Etherポートオープン */
	self->hEther = File_Open(pszEther, FILE_OPEN_READ | FILE_OPEN_WRITE | FILE_OPEN_EXIST);
	if ( self->hEther == HANDLE_NULL )
	{
		return FILE_ERR_NG;
	}
	
	/* 親クラスコンストラクタ呼び出し */
	SyncDrv_Constructor(&self->SyncDrv, pMethods, SYNCDRV_FACTOR_NUM);
	
	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	self->iRecvHead  = 0;
	self->iRecvNum   = 0;
	
	memcpy(self->ubMyIpAddr,      pInf->ubIpAddr, 4);
	memcpy(self->ubSubNetMask,    pInf->ubSubNetMask, 4);
	memcpy(self->ubGateWayIpAddr, pInf->ubGateWayIpAddr, 4);
	
	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);
	self->hEvtArp  = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);

	/* ミューテックス生成 */
	self->hMtxSend = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	self->hMtxRecv = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	self->hMtxArp  = SysMtx_Create(SYSMTX_ATTR_NORMAL);

	/* 受信プロセス生成 */
	self->hPrcRecv = SysPrc_Create(IpEther_Recv, (VPARAM)self, NULL, 1024, 2, SYSPRC_ATTR_NORMAL);
	SysPrc_Start(self->hPrcRecv);
	
	return FILE_ERR_OK;
}


/* endof file */
