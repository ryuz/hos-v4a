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


FILE_ERR TcpIp_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_TCPIP	*self;
	
	/* upper cast */
	self = (C_TCPIP *)pDrvObj;
	
	return FILE_ERR_NG;
}


/* endof file */
