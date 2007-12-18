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
#include "tcpip_local.h"


/* 仮想関数テーブル */
static const T_DRVOBJ_METHODS TcpIp_Methods = 
	{
		{ TcpIp_Delete },
		TcpIp_Open,
		TcpIp_Close,
		TcpIp_IoControl,
		TcpIp_Seek,
		TcpIp_Read,
		TcpIp_Write,
		TcpIp_Flush,
	};


/** 生成 */
HANDLE TcpIp_Create(const char *pszIp)
{
	C_TCPIP *self;
	
	/* メモリ確保 */
	if ( (self = (C_TCPIP *)SysMem_Alloc(sizeof(C_TCPIP))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( TcpIp_Constructor(self, &TcpIp_Methods, pszIp) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* endof file */
