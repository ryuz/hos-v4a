/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_local.h
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__at91usartdrv_local_h__
#define __HOS__at91usartdrv_local_h__


#include "at91usartdrv.h"
#include "system/file/syncdrv_local.h"
#include "library/container/streambuf/streambuf.h"
#include "system/sysapi/sysapi.h"


#define AT91USART_US_CR				0x00		/* Control Register */
#define AT91USART_US_MR				0x04		/* Mode Register */
#define AT91USART_US_IER			0x08		/* Interrupt Enable Register */
#define AT91USART_US_IDR			0x0c		/* Interrupt Disable Register */
#define AT91USART_US_IMR			0x10		/* Interrupt Mask Register */
#define AT91USART_US_CSR			0x14		/* Channel Status Register */
#define AT91USART_US_RHR			0x18		/* Receiver Holding Register */
#define AT91USART_US_THR			0x1c		/* Transmitter Holding Register */
#define AT91USART_US_BRGR			0x20		/* Baud Rate Generator Register */
#define AT91USART_US_RTOR			0x24		/* Receiver Time-out Register */
#define AT91USART_US_TTGR			0x28		/* Transmitter Time-guard Register */
#define AT91USART_US_RPR			0x30		/* Receive Pointer Register */
#define AT91USART_US_RCR			0x34		/* Receive Counter Register */
#define AT91USART_US_TPR			0x38		/* Transmit Pointer Register */
#define AT91USART_US_TCR			0x3c		/* Transmit Counter Register */

#define AT91USART_REG_WRITE(self, offset, val)		SysIo_OutPortW(((char *)(self)->pRegBase + (offset)), val)
#define AT91USART_REG_READ(self, offset)			SysIo_InPortW(((char *)(self)->pRegBase + (offset)))



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

FILE_ERR  At91UsartDrv_Constructor(C_AT91USARTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize);
																															/**< コンストラクタ */
void      At91UsartDrv_Destructor(C_AT91USARTDRV *self);																	/**< デストラクタ */

HANDLE    At91UsartDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      At91UsartDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  At91UsartDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  At91UsartDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE At91UsartDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE At91UsartDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  At91UsartDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      At91UsartDrv_Isr(VPARAM Param);			/* 割込み処理 */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__armuartdrv_h__ */


/* end of file */
