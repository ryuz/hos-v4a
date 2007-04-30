/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  winsockdrv.h
 * @brief %jp{WinSockでシリアルを擬似するドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__winsockdrv_h__
#define __HOS__winsockdrv_h__


#define SIZE	WINSIZE
#include <winsock2.h>
#include "system/file/drvobj.h"
#include "system/sysapi/sysapi.h"
#include "library/container/stmbuf/stmbuf.h"


/* WinSock用ドライバ制御部 */
typedef struct c_winsockdrv
{
	C_DRVOBJ		DrvObj;			/* デバイスドライバクラスを継承 */
	
	int				iOpenCount;
	SYSEVT_HANDLE	hEvtSend;
	SYSEVT_HANDLE	hEvtRecv;
	SYSMTX_HANDLE	hMtxSend;
	SYSMTX_HANDLE	hMtxRecv;

	SOCKET			sock0;
	SOCKET			sock;

	C_STREAMBUF		StmBuf;
} C_WINSOCKDRV;



#ifdef __cplusplus
extern "C" {
#endif

void WinSockDrv_Create(C_WINSOCKDRV *self, int iPortNum, int iIntNum, int iBufSize);		/**< コンストラクタ */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__winsockdrv_h__ */


/* end of file */
