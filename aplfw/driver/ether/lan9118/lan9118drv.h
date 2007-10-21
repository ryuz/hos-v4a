/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv.h
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__lan9118drv_h__
#define __HOS__lan9118drv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/chrdrv.h"
#include "library/container/stmbuf/stmbuf.h"


/* UARTドライバ制御部 */
typedef struct c_lan9118drv
{
	C_CHRDRV		ChrDrv;			/* キャラクタ型デバイスドライバを継承 */

	void			*pRegBase;		/* レジスタベースアドレス */
	int				iIntNum;		/* 割込み番号 */
	
	int				iOpenCount;		/* オープンカウンタ */
	SYSEVT_HANDLE	hEvtSend;		/* 送信イベント */
	SYSEVT_HANDLE	hEvtRecv;		/* 受信イベント */
	SYSMTX_HANDLE	hMtxSend;		/* 送信排他制御ミューテックス */
	SYSMTX_HANDLE	hMtxRecv;		/* 受信排他制御ミューテックス */
} C_LAN9118DRV;



#ifdef __cplusplus
extern "C" {
#endif

void Lan9118Drv_Create(C_LAN9118DRV *self, void *pRegBase, int iIntNum);	/**< コンストラクタ */
void Lan9118Drv_Delete(C_DRVOBJ *pDrvObj);									/**< デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__lan9118drv_h__ */


/* end of file */
