/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91uartdrv_local.h
 * @brief %jp{ATMEL AT91シリーズUART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__at91uartdrv_local_h__
#define __HOS__at91uartdrv_local_h__


#include "at91uartdrv.h"


#define AT91UART_US_CR			0x00		/* Control Register */
#define AT91UART_US_MR			0x04		/* Mode Register */
#define AT91UART_US_IER			0x08		/* Interrupt Enable Register */
#define AT91UART_US_IDR			0x0c		/* Interrupt Disable Register */
#define AT91UART_US_IMR			0x10		/* Interrupt Mask Register */
#define AT91UART_US_CSR			0x14		/* Channel Status Register */
#define AT91UART_US_RHR			0x18		/* Receiver Holding Register */
#define AT91UART_US_THR			0x1c		/* Transmitter Holding Register */
#define AT91UART_US_BRGR		0x20		/* Baud Rate Generator Register */
#define AT91UART_US_RTOR		0x24		/* Receiver Time-out Register */
#define AT91UART_US_TTGR		0x28		/* Transmitter Time-guard Register */
#define AT91UART_US_RPR			0x30		/* Receive Pointer Register */
#define AT91UART_US_RCR			0x34		/* Receive Counter Register */
#define AT91UART_US_TPR			0x38		/* Transmit Pointer Register */
#define AT91UART_US_TCR			0x3c		/* Transmit Counter Register */

#define AT91UART_REG_WRITE(self, offset, val)	do { *(unsigned long *)((char *)(self)->pRegBase + (offset)) = (val); } while(0)
#define AT91UART_REG_READ(self, offset)			(*((unsigned long *)((char *)(self)->pRegBase + (offset))))


#ifdef __cplusplus
extern "C" {
#endif

HANDLE    At91UartDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      At91UartDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  At91UartDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  At91UartDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE At91UartDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE At91UartDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  At91UartDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      At91UartDrv_Isr(VPARAM Param);			/* 割込み処理 */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__armuartdrv_h__ */


/* end of file */
