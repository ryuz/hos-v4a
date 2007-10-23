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


void TcpIp_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_TCPIP		*self;
	
	/* upper cast */
	self = (C_TCPIP *)pDrvObj;
}


/* endof file */
