/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  tcpip.h
 * @brief %jp{TCP/IP プロトコル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "tcpip_local.h"


void TcpIp_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_TCPIP		*self;
	C_TCPIPFILE	*pFile;
	
	/* upper cast */
	self  = (C_TCPIP *)pFileObj;
	pFile = (C_TCPIPFILE *)pFilePtr;
	
	/* クローズ処理 */
	self->iOpenCount--;
	
	/* ディスクリプタ削除 */
	TcpIpFile_Delete(pFile);		
}


/* endof file */
