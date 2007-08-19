/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_write.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/** %jp{送信} */
FILE_SIZE At91UsartDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_AT91USARTDRV		*self;
	C_CHRFILE			*pChrFile;
	const unsigned char	*pubBuf;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self     = (C_AT91USARTDRV *)pDrvObj;
	pChrFile = (C_CHRFILE *)pFileObj;
	
	pubBuf = (const unsigned char *)pData;
	
	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxSend);
	
	for ( i = 0; i < Size; i++ )
	{
		c = *pubBuf++;
		while ( !(AT91USART_REG_READ(self, AT91USART_US_CSR) & 0x0002) )
		{
			if ( pChrFile->cWriteMode == FILE_WMODE_BLOCKING )
			{
				/* ブロッキングなら送信割り込みを待つ */
				AT91USART_REG_WRITE(self, AT91USART_US_IER, 0x00000002);	/* 送信割り込み許可 */		
				SysEvt_Wait(self->hEvtSend);
				SysEvt_Clear(self->hEvtSend);
			}
			else
			{
				/* ノンブロッキングなら終了 */
				goto loop_end;
			}
		}
		AT91USART_REG_WRITE(self, AT91USART_US_THR, c);
	}
loop_end:

	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxSend);

	return i;
}


/* end of file */
