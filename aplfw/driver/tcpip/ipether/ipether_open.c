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
	C_CHRFILE	*pFile;
	
	/* upper cast */
	self = (C_IPETHER *)pDrvObj;

	/* create file descriptor */
	if ( (pFile = SysMem_Alloc(sizeof(C_CHRFILE))) == NULL )
	{
		return HANDLE_NULL;
	}
	ChrFile_Create(pFile, pDrvObj, NULL);
	
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		File_IoControl(self->hEther, FILE_IOCTL_ETHER_GETPHA, self->ubMyMacAddr, 6, 0, 0);
	}
	
	return (HANDLE)pFile;
}


/* end of file */
