/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.h
 * @brief %jp{16550互換シリアル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__pc16550drv_h__
#define __HOS__pc16550drv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/chrdrv.h"
#include "pc16550hal.h"
#include "library/container/streambuf/streambuf.h"


/* PC16550用ドライバ制御部 */
typedef struct c_pc16550drv
{
	C_CHRDRV		ChrDrv;			/* キャラクタ型デバイスドライバを継承 */

	C_PC16550HAL	Pc16550Hal;		/* ハードウェア制御クラス */
	int				iOpenCount;		/* オープンカウンタ */
	int				iIntNum;		/* 割込み番号 */
	SYSEVT_HANDLE	hEvtSend;		/* 送信イベント */
	SYSEVT_HANDLE	hEvtRecv;		/* 受信イベント */
	SYSMTX_HANDLE	hMtxSend;		/* 送信排他制御ミューテックス */
	SYSMTX_HANDLE	hMtxRecv;		/* 受信排他制御ミューテックス */
	C_STREAMBUF		StmBufRecv;		/* 受信バッファ */
} C_PC16550DRV;



#ifdef __cplusplus
extern "C" {
#endif

void Pc16550Drv_Create(C_PC16550DRV *self, void *pRegAddr, unsigned int uiRegStep, int iIntNum, long lSysClock, int iBufSize);	/**< コンストラクタ */
void Pc16550Drv_Delete(C_DRVOBJ *pDrvObj);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pc16550drv_h__ */


/* end of file */
