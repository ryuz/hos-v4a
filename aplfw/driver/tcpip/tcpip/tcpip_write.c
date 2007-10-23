/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  tcpip.h
 * @brief %jp{TCP/IP プロトコル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"
#include "tcpip_local.h"
#include "library/algorithm/ipchecksum/ipchecksum.h"


FILE_SIZE TcpIp_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_TCPIP			*self;
	C_TCPIPFILE		*pFile;
	C_IPCHECKSUM	ics;
	unsigned short	uhSum;
	unsigned char	*pubSendBuf;
	int				iSendSize;
	
	/* upper cast */
	self  = (C_TCPIP *)pDrvObj;
	pFile = (C_TCPIPFILE *)pFileObj;
	
	
	if ( pFile->iType == TCPIPFILE_TYPE_UDP )
	{
		const T_TCPIP_ADDRESS	*pAddr;
		const unsigned char		*pubData;
		
		pAddr   = (const T_TCPIP_ADDRESS *)pData;
		pubData = (const unsigned char *)pData + sizeof(T_TCPIP_ADDRESS);
		
	//	iSendSize = 
		
		SysMtx_Lock(self->hMtxSend);
		
		pubSendBuf = self->ubSendBuf;
		
		/******** IPヘッダ ********/
	
		/* バージョン4, ヘッダ長 0x14 */
		pubSendBuf[0] = 0x45;
		
		/* 優先度, サービスタイプ */	
		pubSendBuf[1] = 0x00;
		
		/* データ長 */
		pubSendBuf[2] = iSendSize / 256;	
		pubSendBuf[3] = iSendSize % 256;
		
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
		pubSendBuf[9] = 0x17;	/* UDP */
		
		/* チェックサム */
		pubSendBuf[10] = 0;
		pubSendBuf[11] = 0;
		
		/* 送信元IPアドレス */
//		memcpy(&pubSendBuf[12],  self->ubMyIpAddr, 4);
		
		/* 送信先IPアドレス */
		memcpy(&pubSendBuf[16],  &pAddr->ubAddress, 4);
		
		
		/******** IPヘッダ ********/
		
		/* 発信元ポート番号 */
		IP_SET_HALFWORD(&pubSendBuf[20], pFile->uhPortNum);
		
		/* 発信先ポート番号 */
		IP_SET_HALFWORD(&pubSendBuf[22], pFile->uhPortNum);
		
		/* データ長 */
		IP_SET_HALFWORD(&pubSendBuf[24], Size - sizeof(T_TCPIP_ADDRESS) + 8);
		
		/* チェックサム */
		IP_SET_HALFWORD(&pubSendBuf[26], 0);
		
		/* データ */
		memcpy(&pubSendBuf[28], pubData, Size - sizeof(T_TCPIP_ADDRESS));
		
	}
	
	return Size;
}


/* endof file */
