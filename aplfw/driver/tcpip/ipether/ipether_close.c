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



void IpEther_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_IPETHER *self;
	
	/* upper cast */
	self = (C_IPETHER *)pDrvObj;

	/* クロース処理 */
	if ( --self->iOpenCount == 0 )
	{
		File_IoControl(self->hEther, FILE_IOCTL_ETHER_GETPHA, self->ubMyMacAddr, 6, 0, 0);
	}
	
	SyncFile_Delete((HANDLE)pFileObj);
}


/* endof file */
