/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv.h
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__mx1uartdrv_h__
#define __HOS__mx1uartdrv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/syncdrv.h"
#include "library/container/streambuf/streambuf.h"


/* ARM製 Integrator UART用ドライバ制御部 */
typedef struct c_mx1uartdrv
{
	C_SYNCDRV		SyncDrv;			/* キャラクタ型デバイスドライバを継承 */

	void			*pRegBase;		/* レジスタベースアドレス */
	unsigned long	ulBaseClock;	/* ベースクロック */
	int				iIntNum;		/* 割込み番号 */

	int				iOpenCount;		/* オープンカウンタ */

	SYSEVT_HANDLE	hEvtSend;		/* 送信イベント */
	SYSEVT_HANDLE	hEvtRecv;		/* 受信イベント */

	SYSMTX_HANDLE	hMtxSend;		/* 送信排他制御ミューテックス */
	SYSMTX_HANDLE	hMtxRecv;		/* 受信排他制御ミューテックス */
	C_STREAMBUF		StmBufRecv;		/* 受信バッファ */
} C_MX1UARTDRV;



#ifdef __cplusplus
extern "C" {
#endif

void Mx1UartDrv_Create(C_MX1UARTDRV *self, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize);	/**< コンストラクタ */
void Mx1UartDrv_Delete(C_DRVOBJ *pDrvObj);																			/**< デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__mx1uartdrv_h__ */


/* end of file */
