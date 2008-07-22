/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  tcpip.h
 * @brief %jp{TCP/IP プロトコル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "hosaplfw.h"
#include "tcpip_local.h"
#include "library/algorithm/ipchecksum/ipchecksum.h"


static void TcpIp_IcmpRecv(C_TCPIP *self, const unsigned char *pubBuf, int iSize);
static void TcpIp_UdpRecv(C_TCPIP *self, const unsigned char *pubBuf, int iSize);
static void TcpIp_TcpRecv(C_TCPIP *self, const unsigned char *pubBuf, int iSize);


/* 受信プロセス */
void TcpIp_Recv(void)
{
	C_TCPIP			*self;
	unsigned char	*pubRecvBuf;
	int				iSize;
	
	/* upper cast */
	self  = (C_TCPIP *)SysPrc_GetParam(SysPrc_GetCurrentHandle());
	
	pubRecvBuf = self->ubRecvBuf;
	
	for ( ; ; )
	{
		/* 受信 */
		if ( (iSize = File_Read(self->hIp, pubRecvBuf, 2048)) < 20 )
		{
			continue;
		}
		
		/* プロトコル判定 */
		switch ( pubRecvBuf[9] )
		{
		case 0x01:	/* ICMP */
			TcpIp_IcmpRecv(self, pubRecvBuf, iSize);
			break;

		case 0x06:	/* TCP */
			TcpIp_TcpRecv(self, pubRecvBuf, iSize);
			break;

		case 0x11:	/* UDP */
			TcpIp_UdpRecv(self, pubRecvBuf, iSize);
			break;
		}
	}
}


/* ICMP受信処理 */
void TcpIp_IcmpRecv(C_TCPIP *self, const unsigned char *pubBuf, int iSize)
{
	C_IPCHECKSUM	ics;
	unsigned short	uhSum;
	unsigned char	*pubSendBuf;
	
	SysMtx_Lock(self->hMtxSend);
	
	pubSendBuf = self->ubSendBuf;
	
	
	/******** IPヘッダ ********/
	
	/* バージョン4, ヘッダ長 0x14 */
	pubSendBuf[0] = 0x45;
	
	/* 優先度, サービスタイプ */	
	pubSendBuf[1] = 0x00;
	
	/* データ長 */
	pubSendBuf[2] = iSize / 256;	
	pubSendBuf[3] = iSize % 256;
	
	/* ID */
	pubSendBuf[4] = self->uhPacketId / 256;
	pubSendBuf[5] = self->uhPacketId % 256;
	self->uhPacketId++;
	
	/* フラグメント */
	pubSendBuf[6] = 0x00;
	pubSendBuf[7] = 0x00;
	
	/* TTL */
	pubSendBuf[8] = 0xff;
	
	/* プロトコル */
	pubSendBuf[9] = 0x01;	/* ICMP */
	
	/* 送信元IPアドレス */
	memcpy(&pubSendBuf[12],  &pubBuf[16], 4);

	/* 送信先IPアドレス */
	memcpy(&pubSendBuf[16],  &pubBuf[12], 4);
	
	
	
	/******** ICMP ********/
	
	/* タイプ */
	pubSendBuf[20] = 0x00;

	/* コード */
	pubSendBuf[21] = 0x00;

	/* チェックサム */
	pubSendBuf[22] = 0x00;
	pubSendBuf[23] = 0x00;

	/* ID */
	pubSendBuf[24] = pubBuf[24];
	pubSendBuf[25] = pubBuf[25];
	
	/* シーケンス番号 */
	pubSendBuf[26] = pubBuf[26];
	pubSendBuf[27] = pubBuf[27];
	
	/* データ */
	memcpy(&pubSendBuf[28], &pubBuf[28], iSize - 28);
	
	/* ICPM部のチェックサム計算 */
	IpCheckSum_Create(&ics);
	IpCheckSum_Update(&ics, &pubSendBuf[20], iSize - 20);
	uhSum = IpCheckSum_GetDigest(&ics);
	IpCheckSum_Delete(&ics);

	pubSendBuf[22] = uhSum / 256;
	pubSendBuf[23] = uhSum % 256;
	
	/* 送信 */	
	File_Write(self->hIp, pubSendBuf, iSize);

	SysMtx_Unlock(self->hMtxSend);
}


/* UDP受信処理 */
void TcpIp_UdpRecv(C_TCPIP *self, const unsigned char *pubBuf, int iSize)
{
	const unsigned char ubDumy[2] = {0, 17};
	C_TCPIPFILE		*pFile;
	T_TCPIP_ADDRESS	Addr;
	C_IPCHECKSUM	ics;
	unsigned short	uhDstPort;
	unsigned short	uhSrcPort;
	unsigned short	uhUdpSize;
	unsigned short	uhCheckSum;
	unsigned short	uhSum;
	
	
	/* データ取得 */
	uhSrcPort  = IP_GET_HALFWORD(&pubBuf[20]);
	uhDstPort  = IP_GET_HALFWORD(&pubBuf[22]);
	uhUdpSize  = IP_GET_HALFWORD(&pubBuf[24]);
	uhCheckSum = IP_GET_HALFWORD(&pubBuf[26]);
	
	
	/* チェックサム計算開始 */	
	IpCheckSum_Create(&ics);
	
	/* UDP擬似ヘッダ（pseudo header）*/
	IpCheckSum_Update(&ics, &pubBuf[12], 8);	/* 送信元アドレス＆ 送信先アドレス */
	IpCheckSum_Update(&ics, ubDumy, 2);
	IpCheckSum_Update(&ics, &pubBuf[24], 2);	/* パケット長 */
	
	/* パケット */
	IpCheckSum_Update(&ics, &pubBuf[20], 6);
	IpCheckSum_Update(&ics, &pubBuf[28], uhUdpSize - 8);
	
	uhSum = IpCheckSum_GetDigest(&ics);
	
	IpCheckSum_Delete(&ics);

	/* チェックサム照合 */	
	if ( uhCheckSum != 0x0000 && uhCheckSum != uhSum )
	{
		return;
	}
	
	
	/* 転送元アドレス情報格納 */
	memcpy(Addr.ubAddress, &pubBuf[12], 4);
	Addr.uhPort = uhSrcPort;
	
	
	SysMtx_Lock(self->hMtxLock);
	
	/* 受信ポート探索 */
	pFile = self->pUdpHead;
	if ( pFile != NULL )
	{
		do
		{
			if ( pFile->uhPortNum == uhDstPort )
			{
				/* 受信バッファに格納 */
				if ( StreamBuf_RefFreeSize(&pFile->RecvBuf) >= sizeof(uhUdpSize) + sizeof(Addr) + (uhUdpSize - 8) )
				{
					StreamBuf_SendData(&pFile->RecvBuf, &uhUdpSize, sizeof(uhUdpSize));
					StreamBuf_SendData(&pFile->RecvBuf, &Addr, sizeof(Addr));
					StreamBuf_SendData(&pFile->RecvBuf, &pubBuf[28], uhUdpSize - 8);
					SysEvt_Set(pFile->hEvtRecv);
				}
			}
			
			pFile = pFile->pNext;
		} while ( pFile != self->pUdpHead );
	}
	
	SysMtx_Unlock(self->hMtxLock);
}


void TcpIp_TcpRecv(C_TCPIP *self, const unsigned char *pubBuf, int iSize)
{
	const unsigned char *pubRecvTcp;
	unsigned short		uhMyPort;
	unsigned short		uhYourPort;

	pubRecvTcp = &pubBuf[20];
	
	uhYourPort = (pubRecvTcp[0] << 8) + pubRecvTcp[1];
	uhMyPort   = (pubRecvTcp[2] << 8) + pubRecvTcp[3];
	
	if ( pubRecvTcp[13] == TCP_FLAG_SYN )
	{
		unsigned long	uwSeqNum;
		unsigned char	*pubSendBuf;
		unsigned char	*pubSendTcp;
		C_IPCHECKSUM	ics;
		
		pubSendBuf = self->ubSendBuf;
		pubSendTcp = &pubSendBuf[20];
		
		
		/******** IPヘッダ ********/
		
		/* バージョン4, ヘッダ長 0x14 */
		pubSendBuf[0] = 0x45;
		
		/* 優先度, サービスタイプ */	
		pubSendBuf[1] = 0x00;
		
		/* データ長 */
		pubSendBuf[2] = iSize / 256;
		pubSendBuf[3] = iSize % 256;
		
		/* ID */
		pubSendBuf[4] = self->uhPacketId / 256;
		pubSendBuf[5] = self->uhPacketId % 256;
		self->uhPacketId++;
		
		/* フラグメント */
		pubSendBuf[6] = 0x00;
		pubSendBuf[7] = 0x00;
		
		/* TTL */
		pubSendBuf[8] = 0xff;
		
		/* プロトコル */
		pubSendBuf[9] = 0x06;	/* TCP */
		
		/* 送信元IPアドレス */
		memcpy(&pubSendBuf[12],  &pubBuf[16], 4);

		/* 送信先IPアドレス */
		memcpy(&pubSendBuf[16],  &pubBuf[12], 4);
		
		
		
		/******** TCP ********/
		/*

		pubSendTcp[0] = 0x00;

		IP_SET_HALFWORD(&pubRecvTcp[0], uhMyPort);
		IP_SET_HALFWORD(&pubRecvTcp[2], uhYourPort);
		
		uwSeqNum = IP_GET_WORD(&pubRecvTcp[4]);
		IpCheckSum_Create(&ics);
		IpCheckSum_Update(&ics, &pubSendBuf[20], iSize - 20);
		uhSum = IpCheckSum_GetDigest(&ics);
		IpCheckSum_Delete(&ics);
		*/
	}
}






/* endof file */
