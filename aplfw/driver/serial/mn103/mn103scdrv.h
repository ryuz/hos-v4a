/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv.h
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__mn103scdrv_h__
#define __HOS__mn103scdrv_h__


#include "system/file/syncdrv_local.h"
#include "library/container/streambuf/streambuf.h"


/* UARTドライバ制御部 */
typedef struct c_mn103scdrv
{
	C_SYNCDRV		SyncDrv;		/* キャラクタ型デバイスドライバを継承 */
	
	void			*pRegBase;		/* レジスタベースアドレス */
	int				iIntNumTx;		/* 送信割込み番号 */
	int				iIntNumRx;		/* 受信割込み番号 */
	SYSISR_HANDLE	hIsrTx;			/* 送信割込みサービスルーチンハンドル */
	SYSISR_HANDLE	hIsrRx;			/* 受信割込みサービスルーチンハンドル */
	
	int				iOpenCount;		/* オープンカウンタ */
	
	C_STREAMBUF		StmBufRecv;		/* 受信バッファ */
} C_MN103SCDRV;



#ifdef __cplusplus
extern "C" {
#endif

HANDLE Mn103ScDrv_Create(void *pRegBase, int iIntNumRx, int iIntNumTx, int iBufSize);	/**< 生成 */
void   Mn103ScDrv_Delete(HANDLE hDriver);												/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__mn103scdrv_h__ */


/* end of file */
