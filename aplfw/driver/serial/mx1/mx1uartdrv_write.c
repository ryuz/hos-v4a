/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_write.c
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mx1uartdrv_local.h"


/** %jp{送信} */
FILE_SIZE Mx1UartDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_MX1UARTDRV		*self;
	C_CHRFILE			*pFile;
	const unsigned char	*pubBuf;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self  = (C_MX1UARTDRV *)pDrvObj;
	pFile = (C_CHRFILE *)pFileObj;

	pubBuf = (const unsigned char *)pData;

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxSend);

	for ( i = 0; i < Size; i++ )
	{
		c = *pubBuf++;
		while ( !(MX1UART_REG_READ(self, MX1UART_USR2) & 0x0008) )
		{
			if ( pFile->cWriteMode == FILE_WMODE_BLOCKING )
			{
				/* ブロッキングなら送信割り込みを待つ */
		/*		ARMUART_REG_WRITE(self, ARMUART_UARTIMSC, 0x0070); */	/*送信/受信割り込み許可 */		
		/*		SysEvt_Wait(self->hEvtSend);
				SysEvt_Clear(self->hEvtSend);	*/
			}
			else
			{
				/* ノンブロッキングなら終了 */
				goto loop_end;
			}
		}
		MX1UART_REG_WRITE(self, MX1UART_UTXD(0), c);
	}
loop_end:

	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxSend);

	return i;
}



/* end of file */
