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


/* 仮想関数テーブル */
static const T_DRVOBJ_METHODS IpEther_Methods = 
	{
		IpEther_Delete,
		IpEther_Open,
		IpEther_Close,
		IpEther_IoControl,
		IpEther_Seek,
		IpEther_Read,
		IpEther_Write,
		IpEther_Flush,
	};


/**< コンストラクタ */
void IpEther_Create(C_IPETHER *self, HANDLE hEther, const T_IPETHER_INF *pInf)
{
	/* 親クラスコンストラクタ呼び出し */
	ChrDrv_Create(&self->ChrDrv, &IpEther_Methods);

	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	self->hEther     = hEther;
	self->iRecvHead  = 0;
	self->iRecvNum   = 0;
	
	memcpy(self->ubMyIpAddr,      pInf->ubIpAddr, 4);
	memcpy(self->ubSubNetMask,    pInf->ubSubNetMask, 4);
	memcpy(self->ubGateWayIpAddr, pInf->ubGateWayIpAddr, 4);
	
	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create();
	self->hEvtArp  = SysEvt_Create();

	/* ミューテックス生成 */
	self->hMtxSend = SysMtx_Create();
	self->hMtxRecv = SysMtx_Create();
	self->hMtxArp  = SysMtx_Create();

	/* 受信プロセス生成 */
	self->hPrcRecv = SysPrc_Create(IpEther_Recv, (VPARAM)self, 1024, 2);
	SysPrc_Start(self->hPrcRecv);
}


/* endof file */
