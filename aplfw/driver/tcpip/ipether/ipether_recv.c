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


static void IpEther_RecvArp(C_IPETHER *self, unsigned char *pubBuf, int iSize);
static void IpEther_RecvIp(C_IPETHER *self, unsigned char *pubBuf, int iSize);


/* 受信プロセス */
void IpEther_Recv(void)
{
	C_IPETHER		*self;
	int				iRecvTail;
	unsigned char	*pubRecvBuf;
	unsigned short	uhProtocolType;
	int				iSize;
	
	/* upper cast */
	self  = (C_IPETHER *)SysPrc_GetParam(SysPrc_GetCurrentHandle());
	
	for ( ; ; )
	{
		/* 受信位置設定 */
		SysMtx_Lock(self->hMtxRecv);
		iRecvTail = self->iRecvHead + self->iRecvNum;
		if ( iRecvTail >= IPETHER_RECVBUS_SIZE )
		{
			iRecvTail = 0;
		}
		SysMtx_Unlock(self->hMtxRecv);
		pubRecvBuf = self->ubRecvBuf[iRecvTail];
		
		/* 受信 */
		if ( (iSize = File_Read(self->hEther, pubRecvBuf, IPETHER_MAXPACKET_SIZE)) < 60 )
		{
			continue;
		}
		
		/* プロトコルタイプ判別 */
		uhProtocolType = (pubRecvBuf[12] * 256) + pubRecvBuf[13];
		switch ( uhProtocolType )
		{
		case 0x0800:	/* IP */
			IpEther_RecvIp(self, pubRecvBuf, iSize);
			break;
			
		case 0x0806:	/* ARP */
			IpEther_RecvArp(self, pubRecvBuf, iSize);
			break;
			
		}
	}
}


/* IP受信処理 */
void IpEther_RecvIp(C_IPETHER *self, unsigned char *pubBuf, int iSize)
{
	/* リングバッファを進める */
	SysMtx_Lock(self->hMtxRecv);
	if ( self->iRecvNum < IPETHER_RECVBUS_SIZE - 1 )
	{
		iSize -= 14;
		pubBuf[0] = iSize / 256;
		pubBuf[1] = iSize % 256;
		self->iRecvNum++;
	}
	SysMtx_Unlock(self->hMtxRecv);
	
	SysEvt_Set(self->hEvtRecv);
}


/* ARP処理 */
void IpEther_RecvArp(C_IPETHER *self, unsigned char *pubBuf, int iSize)
{
	int i;

	if ( pubBuf[14] == 0x00 && pubBuf[15] == 0x01		/* ハードウェアタイプ(Ether) */
		&& pubBuf[16] == 0x08 && pubBuf[17] == 0x00		/* プロトコルタイプ(IP) */
		&& pubBuf[18] == 0x06							/* ハードウェアアドレス長 */
		&& pubBuf[19] == 0x04							/* プロトコルアドレス長 */
		&& pubBuf[38] == self->ubMyIpAddr[0]
		&& pubBuf[39] == self->ubMyIpAddr[1]
		&& pubBuf[40] == self->ubMyIpAddr[2]
		&& pubBuf[41] == self->ubMyIpAddr[3] )
	{
		if ( pubBuf[20] == 0x00 && pubBuf[21] == 0x01 )		/* オペレーション(ARP要求) */
		{
			unsigned char	*pubSendBuf;
			
			/* 対局MACアドレスの登録 */
			IpEther_AddMacAddr(self, &pubBuf[22], &pubBuf[28]);
			
			/* クリティカルセクションに入る */
			SysMtx_Lock(self->hMtxSend);

			/* ARP応答を返す */
			pubSendBuf = self->ubSendBuf;

			/* 送り先MACアドレス */
			pubSendBuf[0]  = pubBuf[22];
			pubSendBuf[1]  = pubBuf[23];
			pubSendBuf[2]  = pubBuf[24];
			pubSendBuf[3]  = pubBuf[25];
			pubSendBuf[4]  = pubBuf[26];
			pubSendBuf[5]  = pubBuf[27];
			
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
			
			/* オペレーション(ARP応答) */
			pubSendBuf[20] = 0x00;
			pubSendBuf[21] = 0x02;
			
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
			pubSendBuf[32] = pubBuf[22];
			pubSendBuf[33] = pubBuf[23];
			pubSendBuf[34] = pubBuf[24];
			pubSendBuf[35] = pubBuf[25];
			pubSendBuf[36] = pubBuf[26];
			pubSendBuf[37] = pubBuf[27];
			
			/* ターゲットプロトコルアドレス */
			pubSendBuf[38] = pubBuf[28];
			pubSendBuf[39] = pubBuf[29];
			pubSendBuf[40] = pubBuf[30];
			pubSendBuf[41] = pubBuf[31];
			
			/* パディング */
			for ( i = 42; i < 60; i++ )
			{
				pubSendBuf[i] = 0x00;
			}
			
			/* 送信 */
			File_Write(self->hEther, pubSendBuf, 60);

			/* クリティカルセクションを出る */
			SysMtx_Unlock(self->hMtxSend);
		}
		else if ( pubBuf[20] == 0x00 && pubBuf[21] == 0x02 )	/* オペレーション(ARP応答) */
		{
			/* 対局MACアドレスの登録 */
			IpEther_AddMacAddr(self, &pubBuf[22], &pubBuf[28]);		
		}
	}
}


/* endof file */
