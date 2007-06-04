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
#include "tcpip_local.h"


static void Tcpip_RecvIcmp(C_TCPIP *self, unsigned char *pubBuf, int iSize);


/* 受信プロセス */
void Tcpip_Recv(VPARAM Param)
{
	C_TCPIP			*self;
	unsigned char	*pubRecvBuf;
	int				iSize;
	
	/* upper cast */
	self  = (C_TCPIP *)Param;
	
	pubRecvBuf = self->ubRecvBuf;
	
	for ( ; ; )
	{
		/* 受信 */
		if ( (iSize = File_Read(self->hIp, pubRecvBuf, 2048)) < 10 )
		{
			continue;
		}
		
		/* プロトコル判定 */
		switch ( pubRecvBuf[9] )
		{
		case 0x01:	/* ICMP */
			Tcpip_RecvIcmp(self, pubRecvBuf, iSize);
			break;
		}
	}
}

void Tcpip_SetIpCheckSum(unsigned char *pubBuf);


void Tcpip_RecvIcmp(C_TCPIP *self, unsigned char *pubBuf, int iSize)
{
	unsigned char	*pubSendBuf;
	
	pubSendBuf = self->ubSendBuf;
	
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
	pubSendBuf[9] = 0x01;
	
	/* 送信元IPアドレス */
	memcpy(&pubSendBuf[12],  &pubBuf[16], 4);

	/* 送信先IPアドレス */
	memcpy(&pubSendBuf[16],  &pubBuf[12], 4);
	
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
	
	{
		unsigned long	uwSum;
		int				i;
	
		uwSum = 0;
		for ( i = 0; i < iSize - 20; i++ )
		{
			uwSum += (unsigned short)(pubSendBuf[20 + i*2]*256 + pubSendBuf[20 + i*2 + 1]);
		}
		uwSum  = (uwSum & 0xffff) + (uwSum >> 16);
		uwSum  = (uwSum & 0xffff) + (uwSum >> 16);
		uwSum  = (~uwSum & 0xffff);
		
		pubSendBuf[22] = ((uwSum >> 8) & 0xff);
		pubSendBuf[23] = (uwSum & 0xff);
	}
	
	Tcpip_SetIpCheckSum(pubSendBuf);
	
	File_Write(self->hIp, pubSendBuf, iSize);
}



void Tcpip_SetIpCheckSum(unsigned char *pubBuf)
{
	unsigned long	uwSum;
	int				i;
	
	pubBuf[10] = 0x00;
	pubBuf[11] = 0x00;
	
	uwSum = 0;
	for ( i = 0; i < 10; i++ )
	{
		uwSum += (unsigned short)(pubBuf[i*2]*256 + pubBuf[i*2 + 1]);
	}
	uwSum  = (uwSum & 0xffff) + (uwSum >> 16);
	uwSum  = (uwSum & 0xffff) + (uwSum >> 16);
	uwSum  = (~uwSum & 0xffff);
	
	pubBuf[10] = ((uwSum >> 8) & 0xff);
	pubBuf[11] = (uwSum & 0xff);
}



/* endof file */
