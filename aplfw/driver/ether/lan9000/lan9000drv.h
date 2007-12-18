/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000drv.h
 * @brief %jp{LAN9000ファミリー用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__lan9000drv_h__
#define __HOS__lan9000drv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/syncdrv.h"
#include "lan9000hal.h"


/* LAN9000ファミリー用ドライバ制御部 */
typedef struct c_lan9000drv
{
	C_SYNCDRV		SyncDrv;			/* キャラクタ型デバイスドライバを継承 */

	C_LAN9000HAL	Lan9000Hal;		/* ハードウェア制御クラス */
	int				iOpenCount;		/* オープンカウンタ */
	int				iIntNum;		/* 割込み番号 */
	SYSISR_HANDLE	hIsr;			/* 割り込みサービスハンドル */
	SYSMTX_HANDLE	hMtx;			/* 排他制御ミューテックス */
	SYSEVT_HANDLE	hEvtSend;		/* 送信イベント */
	SYSEVT_HANDLE	hEvtRecv;		/* 受信イベント */
} C_LAN9000DRV;



#ifdef __cplusplus
extern "C" {
#endif

void Lan9000Drv_Create(C_LAN9000DRV *self, void *pRegAddr, int iIntNum);	/**< コンストラクタ */
void Lan9000Drv_Delete(C_DRVOBJ *pDrvObj);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__lan9000drv_h__ */


/* end of file */
