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


/* IPパケット受信 */
FILE_SIZE IpEther_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_IPETHER	*self;
	int			iRecvSize;
	
	/* upper cast */
	self = (C_IPETHER *)pDrvObj;
	
	/* 受信待ち */
	while ( self->iRecvNum <= 0 )
	{
		SysEvt_Wait(self->hEvtRecv);
		SysEvt_Clear(self->hEvtRecv);
	}
	
	iRecvSize = self->ubRecvBuf[self->iRecvHead][0] * 256 + self->ubRecvBuf[self->iRecvHead][1];
	if ( Size < iRecvSize )
	{
		iRecvSize = Size;
	}
	
	/* データコピー */
	memcpy(pBuf, &self->ubRecvBuf[self->iRecvHead][14], iRecvSize);
	
	/* リングポインタを進める */
	SysMtx_Lock(self->hMtxRecv);
	self->iRecvNum--;
	if ( self->iRecvHead >= IPETHER_RECVBUS_SIZE - 1 )
	{
		self->iRecvHead = 0;
	}
	else
	{
		self->iRecvHead++;
	}
	SysMtx_Unlock(self->hMtxRecv);
	
	return iRecvSize;
}



/* endof file */
