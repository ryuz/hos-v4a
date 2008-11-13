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


FILE_SIZE TcpIp_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_TCPIP			*self;
	C_TCPIPFILE		*pFile;
	C_IPCHECKSUM	ics;
	unsigned char	*pubSendBuf;
	unsigned short	uhSendSize;
	int				i;
	FILE_SIZE		SizeRet;
	
	/* upper cast */
	self  = (C_TCPIP *)pDrvObj;
	pFile = (C_TCPIPFILE *)pFileObj;
	
	
	if ( pFile->iType == TCPIPFILE_TYPE_UDP )
	{
		unsigned char 			ubDumyHeader[2] = {0x00, 0x11};
		const T_TCPIP_ADDRESS	*pAddr;
		const unsigned char		*pubPayload;
		unsigned short			uhPayloadSize;
		unsigned short			uhSum;
		
		pAddr         = (const T_TCPIP_ADDRESS *)pData;
		pubPayload    = (const unsigned char *)pData + sizeof(T_TCPIP_ADDRESS);
		uhPayloadSize = Size - sizeof(T_TCPIP_ADDRESS);
		uhSendSize    = uhPayloadSize + 28;
		
		/* バッファ準備 */
		pubSendBuf   = pFile->ubSendBuf;
		
		
		/******** IPヘッダ ********/
		
		/* バージョン4, ヘッダ長 0x14 */
		pubSendBuf[0] = 0x45;
		
		/* 優先度, サービスタイプ */	
		pubSendBuf[1] = 0x00;
		
		/* データ長 */
		IP_SET_HALFWORD(&pubSendBuf[2], uhSendSize);
		
		/* ID */
		IP_SET_HALFWORD(&pubSendBuf[4], self->uhPacketId);
		self->uhPacketId++;
		
		/* フラグメント */
		pubSendBuf[6] = 0x00;
		pubSendBuf[7] = 0x00;
		
		/* TTL */
		pubSendBuf[8] = 0xff;
		
		/* プロトコル */
		pubSendBuf[9] = 17;		/* UDP */
		
		/* チェックサム */
		IP_SET_HALFWORD(&pubSendBuf[10], 0);
		
		/* 送信元IPアドレス */
		memcpy(&pubSendBuf[12],  self->ubMyIpAddr, 4);
		
		/* 送信先IPアドレス */
		memcpy(&pubSendBuf[16],  &pAddr->ubAddress, 4);
		
		
		/******** IPヘッダ ********/
		
		/* 発信元ポート番号 */
		IP_SET_HALFWORD(&pubSendBuf[20], pFile->uhPortNum);
		
		/* 発信先ポート番号 */
		IP_SET_HALFWORD(&pubSendBuf[22], pAddr->uhPort);
		
		/* データ長 */
		IP_SET_HALFWORD(&pubSendBuf[24], uhPayloadSize + 8);
		
		/* チェックサム */
		IP_SET_HALFWORD(&pubSendBuf[26], 0);
		
		/* ペイロードデータ */
		memcpy(&pubSendBuf[28], pubPayload, uhPayloadSize);
		
		/* チェックサム計算 */
		IpCheckSum_Create(&ics);
		IpCheckSum_Update(&ics, &pubSendBuf[12], 8);					/* 送信元IP＋宛先IP */
		IpCheckSum_Update(&ics, ubDumyHeader, 2);						/* 00h, 11h */
		IpCheckSum_Update(&ics, &pubSendBuf[24], 2);					/* UDPデータ長 */
		IpCheckSum_Update(&ics, &pubSendBuf[20], 8 + uhPayloadSize);	/* UDPヘッダ＋ペイロード */	
		uhSum = IpCheckSum_GetDigest(&ics);
		IP_SET_HALFWORD(&pubSendBuf[26], uhSum);
		IpCheckSum_Delete(&ics);
		
		for ( i = 0; i < 10; i++ )
		{
			SysMtx_Lock(self->hMtxSend);
			SizeRet = File_Write(self->hIp, pubSendBuf, uhSendSize);
			SysMtx_Unlock(self->hMtxSend);
			if ( SizeRet > 0 )
			{
				break;
			}
			
			SysTim_Wait(100);
		}
	}
	
	return Size;
}


/* endof file */
