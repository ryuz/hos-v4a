/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{SCI用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


/** %jp{送信} */
FILE_SIZE SciDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_SCIDRV			*self;
	C_SYNCFILE			*pFile;
	const unsigned char	*pubBuf;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self  = (C_SCIDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	pubBuf = (const unsigned char *)pData;

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxSend);

	for ( i = 0; i < Size; i++ )
	{
		c = *pubBuf++;
		while ( SciHal_SendChar(&self->SciHal, c) < 0 )
		{
			if ( pFile->cWriteMode == FILE_WMODE_BLOCKING )
			{
				/* ブロッキングなら送信割り込みを待つ */
				SciHal_EnableInterrupt(&self->SciHal, SCIHAL_INT_TIE | SCIHAL_INT_RIE);
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
