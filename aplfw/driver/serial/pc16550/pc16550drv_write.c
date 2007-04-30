/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{PC16550用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550drv_local.h"


/** %jp{送信} */
FILE_SIZE Pc16550Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_PC16550DRV		*self;
	C_CHRFILE			*pChrFile;
	const unsigned char	*pubBuf;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self     = (C_PC16550DRV *)pDrvObj;
	pChrFile = (C_CHRFILE *)pFileObj;

	pubBuf = (const unsigned char *)pData;

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxSend);

	for ( i = 0; i < Size; i++ )
	{
		c = *pubBuf++;
		while ( Pc16550Hal_SendChar(&self->Pc16550Hal, c) < 0 )
		{
			if ( pChrFile->cWriteMode == FILE_WMODE_BLOCKING )
			{
				/* ブロッキングなら送信割り込みを待つ */
				Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, PC16550HAL_IER_ERBFI | PC16550HAL_IER_ETBEI);
				SysEvt_Wait(self->hEvtSend);
				SysEvt_Clear(self->hEvtSend);
			}
			else
			{
				/* ノンブロッキングなら終了 */
				goto loop_end;
			}
		}
	}
loop_end:

	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxSend);

	return i;
}



/* end of file */
