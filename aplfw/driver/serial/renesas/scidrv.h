/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.h
 * @brief %jp{SCI用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__renesas_scidrv_h__
#define __HOS__renesas_scidrv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/chrdrv.h"
#include "scihal.h"
#include "library/container/streambuf/streambuf.h"


/* SCI用ドライバ制御部 */
typedef struct c_scidrv
{
	C_CHRDRV		ChrDrv;			/* キャラクタ型デバイスドライバを継承 */

	C_SCIHAL		SciHal;			/* ハードウェア制御クラス */
	int				iOpenCount;		/* オープンカウンタ */
	SYSEVT_HANDLE	hEvtSend;		/* 送信イベント */
	SYSEVT_HANDLE	hEvtRecv;		/* 受信イベント */
	SYSMTX_HANDLE	hMtxSend;		/* 送信排他制御ミューテックス */
	SYSMTX_HANDLE	hMtxRecv;		/* 受信排他制御ミューテックス */
	C_STREAMBUF		StmBufRecv;		/* 受信バッファ */
} C_SCIDRV;



#ifdef __cplusplus
extern "C" {
#endif

/* SCI用デバイスドライバ */
void SciDrv_Create(C_SCIDRV *self, void *pRegAddr, int iIntNum, unsigned long ulSysClock, int iBufSize);	/**< コンストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__renesas_scidrv_h__ */


/* end of file */
