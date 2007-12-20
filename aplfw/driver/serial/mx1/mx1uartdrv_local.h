/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_local.h
 * @brief %jp{Freescale MX1 UART用デバイスドライバ ローカルヘッダファイル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__mx1uartdrv_local_h__
#define __HOS__mx1uartdrv_local_h__


#include "mx1uartdrv.h"
#include "system/file/syncdrv_local.h"
#include "library/container/streambuf/streambuf.h"
#include "system/sysapi/sysapi.h"


#define MX1UART_URXD(n)			(0x00+4*(n))
#define MX1UART_UTXD(n)			(0x40+4*(n))
#define MX1UART_UCR1			0x80
#define MX1UART_UCR2			0x84
#define MX1UART_UCR3			0x88
#define MX1UART_UCR4			0x8c
#define MX1UART_UFCR			0x90
#define MX1UART_USR1			0x94
#define MX1UART_USR2			0x98
#define MX1UART_UESC			0x9c
#define MX1UART_UTIM			0xa0
#define MX1UART_UBIR			0xa4
#define MX1UART_UBMR			0xa8
#define MX1UART_UBRC			0xac
#define MX1UART_BIPR1			0xb0
#define MX1UART_BIPR2			0xb4
#define MX1UART_BIPR3			0xb8
#define MX1UART_BIPR4			0xbc
#define MX1UART_BMPR1			0xc0
#define MX1UART_BMPR2			0xc4
#define MX1UART_BMPR3		    0xc8
#define MX1UART_BMPR4		    0xcc
#define MX1UART_UTS			    0xd0

#define MX1UART_REG_WRITE(self, offset, val)	SysIo_OutPortW(((char *)(self)->pRegBase + (offset)), val)
#define MX1UART_REG_READ(self, offset)			SysIo_InPortW(((char *)(self)->pRegBase + (offset)))



/* UART用ドライバ制御クラス */
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

FILE_ERR  Mx1UartDrv_Constructor(C_MX1UARTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize);	/**< コンストラクタ */
void      Mx1UartDrv_Destructor(C_MX1UARTDRV *self);																											/**< デストラクタ */


HANDLE    Mx1UartDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      Mx1UartDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  Mx1UartDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  Mx1UartDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE Mx1UartDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE Mx1UartDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  Mx1UartDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      Mx1UartDrv_IsrTx(VPARAM Param);			/* 割込み処理 */
void      Mx1UartDrv_IsrRx(VPARAM Param);			/* 割込み処理 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__armuartdrv_h__ */


/* end of file */
