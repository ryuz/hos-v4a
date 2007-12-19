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
	C_SYNCDRV		SyncDrv;		/* キャラクタ型デバイスドライバを継承 */

	void			*pRegBase;		/* レジスタベースアドレス */
	unsigned long	ulBaseClock;	/* ベースクロック */
	int				iIntNum;		/* 割込み番号 */
	SYSISR_HANDLE	hIsrTx;			/* 送信割込みサービスルーチンハンドル */
	SYSISR_HANDLE	hIsrRx;			/* 受信割込みサービスルーチンハンドル */

	int				iOpenCount;		/* オープンカウンタ */

	C_STREAMBUF		StmBufRecv;		/* 受信バッファ */
} C_MX1UARTDRV;



#ifdef __cplusplus
extern "C" {
#endif

HANDLE Mx1UartDrv_Create(void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize);	/**< 生成 */
void   Mx1UartDrv_Delete(HANDLE hDriver);														/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__mx1uartdrv_h__ */


/* end of file */
