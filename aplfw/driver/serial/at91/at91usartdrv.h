/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv.h
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__at91usartdrv_h__
#define __HOS__at91usartdrv_h__


#include "system/file/syncdrv.h"
#include "library/container/streambuf/streambuf.h"


/* UARTドライバ制御部 */
typedef struct c_at91usartdrv
{
	C_SYNCDRV		SyncDrv;		/* キャラクタ型デバイスドライバを継承 */

	void			*pRegBase;		/* レジスタベースアドレス */
	unsigned long	ulBaseClock;	/* ベースクロック */
	int				iIntNum;		/* 割込み番号 */
	SYSISR_HANDLE	hIsr;			/* 割込みサービスルーチンハンドル */

	int				iOpenCount;		/* オープンカウンタ */
	
	C_STREAMBUF		StmBufRecv;		/* 受信バッファ */
} C_AT91USARTDRV;



#ifdef __cplusplus
extern "C" {
#endif

HANDLE At91UsartDrv_Create(void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize);	/**< 生成 */
void   At91UsartDrv_Delete(HANDLE hDriver);															/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__at91usartdrv_h__ */


/* end of file */
