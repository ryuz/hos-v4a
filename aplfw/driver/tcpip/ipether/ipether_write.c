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


/* IPパケット送信 */
FILE_SIZE IpEther_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_IPETHER			*self;
	const unsigned char	*pubData;
	const unsigned char	*pubIpAddr;
	unsigned char		*pubSendBuf;
	unsigned char		ubMacAddr[6];
	int					iPacketSize;
	
	/* upper cast */
	self = (C_IPETHER *)pDrvObj;
	
	pubData = (unsigned char *)pData;
	
	/* サブネットチェック */
	pubIpAddr = &pubData[16];
	if ( (pubIpAddr[0] & self->ubSubNetMask[0]) != (self->ubMyIpAddr[0] & self->ubSubNetMask[0])
		|| (pubIpAddr[1] & self->ubSubNetMask[1]) != (self->ubMyIpAddr[1] & self->ubSubNetMask[1])
		|| (pubIpAddr[2] & self->ubSubNetMask[2]) != (self->ubMyIpAddr[2] & self->ubSubNetMask[2])
		|| (pubIpAddr[3] & self->ubSubNetMask[3]) != (self->ubMyIpAddr[3] & self->ubSubNetMask[3]) )
	{
		pubIpAddr = self->ubGateWayIpAddr;
	}
	
	/* MACアドレス解決 */
	if ( IpEther_GetMacAddr(self, ubMacAddr, pubIpAddr) != FILE_ERR_OK )
	{
		return 0;
	}
	
	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxSend);
	
	pubSendBuf = self->ubSendBuf;
	
	/* 送り先MACアドレス */
	pubSendBuf[0]  = ubMacAddr[0];
	pubSendBuf[1]  = ubMacAddr[1];
	pubSendBuf[2]  = ubMacAddr[2];
	pubSendBuf[3]  = ubMacAddr[3];
	pubSendBuf[4]  = ubMacAddr[4];
	pubSendBuf[5]  = ubMacAddr[5];

	/* 自MACアドレス */
	pubSendBuf[6]  = self->ubMyMacAddr[0];
	pubSendBuf[7]  = self->ubMyMacAddr[1];
	pubSendBuf[8]  = self->ubMyMacAddr[2];
	pubSendBuf[9]  = self->ubMyMacAddr[3];
	pubSendBuf[10] = self->ubMyMacAddr[4];
	pubSendBuf[11] = self->ubMyMacAddr[5];
	
	/* プロトコルタイプ (IP) */
	pubSendBuf[12] = 0x08;
	pubSendBuf[13] = 0x00;
	
	/* IPデータグラム */
	memcpy(&pubSendBuf[14], pubData, Size);
	
	/* パディング */
	iPacketSize = Size + 14;
	while ( iPacketSize < 60 )
	{
		pubSendBuf[iPacketSize++] = 0x00;
	}
	
	/* 送信 */
	if ( File_Write(self->hEther, pubSendBuf, iPacketSize) != iPacketSize )
	{
		Size = 0;
	}
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxSend);
	
	return Size;
}



/* endof file */
