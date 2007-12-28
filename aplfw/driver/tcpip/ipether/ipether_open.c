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


HANDLE IpEther_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_IPETHER	*self;
	HANDLE		hFile;
	
	/* upper cast */
	self = (C_IPETHER *)pDrvObj;
	
	/* create file descriptor */
	if ( (hFile = SyncFile_Create(&self->SyncDrv, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		File_IoControl(self->hEther, FILE_IOCTL_ETHER_GETPHA, self->ubMyMacAddr, 6, 0, 0);
	}
	
	return hFile;
}


/* end of file */
