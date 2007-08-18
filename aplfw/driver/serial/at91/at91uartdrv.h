/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91uartdrv.h
 * @brief %jp{ATMEL AT91シリーズUART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__at91uartdrv_h__
#define __HOS__at91uartdrv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/chrdrv.h"
#include "library/container/stmbuf/stmbuf.h"


/* UARTドライバ制御部 */
typedef struct c_at91uartdrv
{
	C_CHRDRV		ChrDrv;			/* キャラクタ型デバイスドライバを継承 */

	void			*pRegBase;		/* レジスタベースアドレス */
	unsigned long	ulBaseClock;	/* ベースクロック */
	int				iIntNum;		/* 割込み番号 */

	int				iOpenCount;		/* オープンカウンタ */
	SYSEVT_HANDLE	hEvtSend;		/* 送信イベント */
	SYSEVT_HANDLE	hEvtRecv;		/* 受信イベント */
	SYSMTX_HANDLE	hMtxSend;		/* 送信排他制御ミューテックス */
	SYSMTX_HANDLE	hMtxRecv;		/* 受信排他制御ミューテックス */
	C_STREAMBUF		StmBufRecv;		/* 受信バッファ */
} C_AT91UARTDRV;



#ifdef __cplusplus
extern "C" {
#endif

void At91UartDrv_Create(C_AT91UARTDRV *self, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize);	/**< コンストラクタ */
void At91UartDrv_Delete(C_DRVOBJ *pDrvObj);																			/**< デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__at91uartdrv_h__ */


/* end of file */
