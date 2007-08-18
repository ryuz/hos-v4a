/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91uartdrv_write.c
 * @brief %jp{ATMEL AT91シリーズUART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91uartdrv_local.h"


/** %jp{送信} */
FILE_SIZE At91UartDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_AT91UARTDRV		*self;
	C_CHRFILE			*pChrFile;
	const unsigned char	*pubBuf;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self     = (C_AT91UARTDRV *)pDrvObj;
	pChrFile = (C_CHRFILE *)pFileObj;
	
	pubBuf = (const unsigned char *)pData;
	
	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxSend);
	
	for ( i = 0; i < Size; i++ )
	{
		c = *pubBuf++;
		while ( AT91UART_REG_READ(self, AT91UART_US_CSR) & 0x0002 )
		{
			if ( pChrFile->cWriteMode == FILE_WMODE_BLOCKING )
			{
				/* ブロッキングなら送信割り込みを待つ */
				AT91UART_REG_WRITE(self, AT91UART_US_IER, 0x00000002);	/* 送信割り込み許可 */		
				SysEvt_Wait(self->hEvtSend);
				SysEvt_Clear(self->hEvtSend);
			}
			else
			{
				/* ノンブロッキングなら終了 */
				goto loop_end;
			}
		}
		AT91UART_REG_WRITE(self, AT91UART_US_THR, c);
	}
loop_end:

	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxSend);

	return i;
}


/* end of file */
