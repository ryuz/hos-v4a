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


/* MACアドレス解決 */
FILE_ERR IpEther_GetMacAddr(C_IPETHER *self, unsigned char ubMacAddr[6], const unsigned char ubIpAddr[4])
{
	int i;

	SysMtx_Lock(self->hMtxArp);
	
	/* テーブル検索 */
	for ( i = 0; i < IPETHER_ARPTBL_SIZE; i++ )
	{
		if ( memcmp(self->ArpTbl[i].ubIpAddr, ubIpAddr, 4) == 0 )
		{
			memcpy(ubMacAddr, &self->ArpTbl[i].ubMacAddr, 6);
			SysMtx_Unlock(self->hMtxArp);
			return FILE_ERR_OK;
		}
	}
	
	SysMtx_Unlock(self->hMtxArp);
	
	return FILE_ERR_NG;
}


void IpEther_AddMacAddr(C_IPETHER *self, const unsigned char ubMacAddr[6], const unsigned char ubIpAddr[4])
{
	int i;
	
	SysMtx_Lock(self->hMtxArp);
	
	/* 重複削除 */
	for ( i = 0; i < IPETHER_ARPTBL_SIZE; i++ )
	{
		if ( memcmp(self->ArpTbl[i].ubIpAddr, ubIpAddr, 4) == 0 )
		{
			memmove(&self->ArpTbl[i], &self->ArpTbl[i+1], (IPETHER_ARPTBL_SIZE-i-1) * sizeof(T_IPETHER_ARPTBL));
		}
	}
	
	/* 追加 */
	memmove(&self->ArpTbl[0], &self->ArpTbl[1], (IPETHER_ARPTBL_SIZE-1) * sizeof(T_IPETHER_ARPTBL));
	memcpy(self->ArpTbl[0].ubIpAddr, ubIpAddr, 4);
	memcpy(self->ArpTbl[0].ubMacAddr, ubMacAddr, 6);

	SysMtx_Unlock(self->hMtxArp);
}


/* end of file */
