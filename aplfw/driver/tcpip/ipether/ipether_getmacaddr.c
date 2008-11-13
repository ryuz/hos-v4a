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
	unsigned char	*pubSendBuf;
	int 			i;

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
	
	
	
	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxSend);
	
	/* ARP要求送信 */
	pubSendBuf = self->ubSendBuf;

	/* 送り先MACアドレス */
	pubSendBuf[0]  = 0xff;
	pubSendBuf[1]  = 0xff;
	pubSendBuf[2]  = 0xff;
	pubSendBuf[3]  = 0xff;
	pubSendBuf[4]  = 0xff;
	pubSendBuf[5]  = 0xff;
	
	/* 自MACアドレス */
	pubSendBuf[6]  = self->ubMyMacAddr[0];
	pubSendBuf[7]  = self->ubMyMacAddr[1];
	pubSendBuf[8]  = self->ubMyMacAddr[2];
	pubSendBuf[9]  = self->ubMyMacAddr[3];
	pubSendBuf[10] = self->ubMyMacAddr[4];
	pubSendBuf[11] = self->ubMyMacAddr[5];
	
	/* プロトコルタイプ (ARP) */
	pubSendBuf[12] = 0x08;
	pubSendBuf[13] = 0x06;
	
	/* ハードウェアタイプ(Ether) */
	pubSendBuf[14] = 0x00;
	pubSendBuf[15] = 0x01;
			
	/* プロトコルタイプ(IP) */
	pubSendBuf[16] = 0x08;
	pubSendBuf[17] = 0x00;
			
	/* ハードウェアアドレス長 */
	pubSendBuf[18] = 0x06;
			
	/* プロトコルアドレス長 */
	pubSendBuf[19] = 0x04;
			
	/* オペレーション(ARP要求) */
	pubSendBuf[20] = 0x00;
	pubSendBuf[21] = 0x01;
			
	/* 送信元ハードウェアアドレス */
	pubSendBuf[22] = self->ubMyMacAddr[0];
	pubSendBuf[23] = self->ubMyMacAddr[1];
	pubSendBuf[24] = self->ubMyMacAddr[2];
	pubSendBuf[25] = self->ubMyMacAddr[3];
	pubSendBuf[26] = self->ubMyMacAddr[4];
	pubSendBuf[27] = self->ubMyMacAddr[5];
	
	/* 送信元プロトコルアドレス */
	pubSendBuf[28] = self->ubMyIpAddr[0];
	pubSendBuf[29] = self->ubMyIpAddr[1];
	pubSendBuf[30] = self->ubMyIpAddr[2];
	pubSendBuf[31] = self->ubMyIpAddr[3];
	
	/* ターゲットハードウェアアドレス */
	pubSendBuf[32] = 0x00;
	pubSendBuf[33] = 0x00;
	pubSendBuf[34] = 0x00;
	pubSendBuf[35] = 0x00;
	pubSendBuf[36] = 0x00;
	pubSendBuf[37] = 0x00;
	
	/* ターゲットプロトコルアドレス */
	pubSendBuf[38] = ubIpAddr[0];
	pubSendBuf[39] = ubIpAddr[1];
	pubSendBuf[40] = ubIpAddr[2];
	pubSendBuf[41] = ubIpAddr[3];
	
	/* パディング */
	for ( i = 42; i < 60; i++ )
	{
		pubSendBuf[i] = 0x00;
	}
			
	/* 送信 */
	File_Write(self->hEther, pubSendBuf, 60);
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxSend);
	
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
