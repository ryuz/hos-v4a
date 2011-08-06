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


FILE_ERR IpEther_IoControl(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_IPETHER	*self;
	C_SYNCFILE	*pFile;
	
	/* upper cast */
	self  = (C_IPETHER *)pFileObj;
	pFile = (C_SYNCFILE *)pFilePtr;
	
	switch ( iFunc )
	{
	case FILE_IOCTL_IP_GETIP:
		memcpy(pInBuf, self->ubMyIpAddr, 4);		
		return FILE_ERR_OK;
	
	default:
		return SyncDrv_IoControl(pFileObj, pFilePtr, iFunc, pInBuf, InSize, pOutBuf, OutSize);
	}
}


/* endof file */
