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


/** %jp{受信} */
FILE_SIZE SciDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_SCIDRV	*self;
	C_CHRFILE		*pChrFile;
	unsigned char	*pubBuf;
	FILE_SIZE		i;
	int				c;
	
	/* upper cast */
	self     = (C_SCIDRV *)pDrvObj;
	pChrFile = (C_CHRFILE *)pFileObj;

	pubBuf = (unsigned char *)pBuf;

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxRecv);

	for ( i = 0; i < Size; i++ )
	{
		while ( (c = StreamBuf_RecvChar(&self->StmBufRecv)) < 0 )
		{
			if ( pChrFile->cReadMode == FILE_RMODE_BLOCKING )
			{
				/* ブロッキングなら受信イベントを待つ */
				SysEvt_Wait(self->hEvtRecv);
				SysEvt_Clear(self->hEvtRecv);
			}
			else
			{
				/* ノンブロッキングなら終了 */
				goto loop_end;
			}
		}
		*pubBuf++ = (unsigned char)c;
	}
loop_end:
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxRecv);

	return i;
}


/* end of file */
