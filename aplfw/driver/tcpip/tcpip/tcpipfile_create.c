/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "tcpipfile_local.h"


static const T_FILEOBJ_METHODS TcpIpFile_FileObjMethods =
	{
		{File_Close},	/* デストラクタ */
	};


HANDLE TcpIpFile_Create(C_TCPIP *pTcpIp, int iMode)
{
	C_TCPIPFILE *self;

	/* create file descriptor */
	if ( (self = (C_TCPIPFILE *)SysMem_Alloc(sizeof(C_TCPIPFILE))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	TcpIpFile_Constructor(self, &TcpIpFile_FileObjMethods, pTcpIp, iMode);
	
	return (HANDLE)self;
}


/* end of file */
