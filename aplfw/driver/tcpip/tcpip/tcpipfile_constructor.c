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


void TcpIpFile_Constructor(C_TCPIPFILE *self, const T_FILEOBJ_METHODS *pMethods, C_TCPIP *pTcpIp, int iMode)
{
	/* 親クラスコンストラクタ */
	SyncFile_Constructor(&self->SyncFile, pMethods, &pTcpIp->SyncDrv, iMode);
	
	/* メンバ変数初期化 */
	/* 初期化 */
	StreamBuf_Create(&self->RecvBuf, TCPIPFILE_RECV_BUFSIZE, self->ubRecvBuf);
	self->hEvtRecv = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);
}


/* end of file */
