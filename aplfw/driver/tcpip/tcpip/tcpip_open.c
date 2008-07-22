/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ipether.h
 * @brief %jp{Ether上にIPプロトコルを実装(つまりMAC層近辺)}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "tcpip_local.h"


HANDLE TcpIp_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_TCPIP		*self;
	HANDLE		hFile;
	C_TCPIPFILE	*pFile;
	
	/* upper cast */
	self = (C_TCPIP *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = TcpIpFile_Create(self, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	pFile = (C_TCPIPFILE *)hFile;
	
	
	if ( self->iOpenCount++ == 0 )
	{
		/* デバイスオープン処理 */
	}
	
	
	/* オープン処理 */
	if ( strncmp(pszPath, "udp:", 4) == 0 )
	{
		/* UDPポートオープン */
		pFile->iType     = TCPIPFILE_TYPE_UDP;
		pFile->uhPortNum = (unsigned short)atoi(&pszPath[4]);
		
		/* リストに登録 */
		if ( self->pUdpHead == NULL )
		{
			pFile->pNext   = pFile;
			pFile->pPrev   = pFile;
			self->pUdpHead = pFile;
		}
		else
		{
			pFile->pNext = self->pUdpHead;
			pFile->pPrev = pFile->pPrev;
			pFile->pNext->pPrev = pFile;
			pFile->pPrev->pNext = pFile;			
		}
	}
	
	return (HANDLE)pFile;
}


/* end of file */
