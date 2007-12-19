/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  pc16550drv.h
 * @brief %jp{16550互換シリアル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__pc16550drv_h__
#define __HOS__pc16550drv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/syncdrv.h"
#include "pc16550hal.h"
#include "library/container/streambuf/streambuf.h"


/* PC16550用ドライバ制御部 */
typedef struct c_pc16550drv
{
	C_SYNCDRV		SyncDrv;			/* キャラクタ型デバイスドライバを継承 */

	C_PC16550HAL	Pc16550Hal;		/* ハードウェア制御クラス */
	int				iOpenCount;		/* オープンカウンタ */
	int				iIntNum;		/* 割込み番号 */
	SYSISR_HANDLE	hIsr;			/* 割込みサービスルーチンハンドル */

	C_STREAMBUF		StmBufRecv;		/* 受信バッファ */
} C_PC16550DRV;



#ifdef __cplusplus
extern "C" {
#endif

HANDLE Pc16550Drv_Create(void *pRegAddr, unsigned int uiRegStep, int iIntNum, long lSysClock, int iBufSize);	/**< 生成 */
void   Pc16550Drv_Delete(HANDLE hDriver);																		/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pc16550drv_h__ */


/* end of file */
