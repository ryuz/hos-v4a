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


void TcpIp_Delete(HANDLE hDriver)
{
	C_TCPIP	*self;
	
	/* upper cast */
	self = (C_TCPIP *)hDriver;

	/* デストラクタ呼び出し */
	TcpIp_Destructor(self);
	
	/* メモリ開放 */
	SysMem_Free(self);
}


/* endof file */
