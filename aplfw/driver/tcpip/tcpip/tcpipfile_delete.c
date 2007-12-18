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


void TcpIpFile_Delete(HANDLE hFile)
{
	C_TCPIPFILE *self;
	
	self = (C_TCPIPFILE *)hFile;
	
	/* デストラクタ */
	TcpIpFile_Destructor(self);
	
	/* メモリ削除 */
	SysMem_Free(self);
}


/* end of file */
