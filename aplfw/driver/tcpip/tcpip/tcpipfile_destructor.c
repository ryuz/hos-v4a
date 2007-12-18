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


void TcpIpFile_Destructor(C_TCPIPFILE *self)
{
	/* 親クラスデストラクタ */		
	SyncFile_Destructor(&self->SyncFile);
}


/* end of file */
