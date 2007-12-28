/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  tcpip.h
 * @brief %jp{TCP/IP プロトコル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__tcpipfile_local_h__
#define __HOS__tcpipfile_local_h__


#include "tcpipfile.h"
#include "system/file/syncfile_local.h"
#include "system/sysapi/sysapi.h"



#ifdef __cplusplus
extern "C" {
#endif

void  TcpIpFile_Constructor(C_TCPIPFILE *self, const T_FILEOBJ_METHODS *pMethods, C_TCPIP *pTcpIp, int iMode);
void  TcpIpFile_Destructor(C_TCPIPFILE *self);

#ifdef __cplusplus
}
#endif



#endif	/*  __HOS__tcpipfile_local_h__ */


/* end of file */
