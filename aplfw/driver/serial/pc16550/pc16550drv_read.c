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


/** %jp{受信} */
FILE_SIZE Pc16550Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_PC16550DRV	*self;
	C_CHRFILE		*pFile;
	unsigned char	*pubBuf;
	FILE_SIZE		i;
	int				c;
	
	/* upper cast */
	self  = (C_PC16550DRV *)pDrvObj;
	pFile = (C_CHRFILE *)pFileObj;

	pubBuf = (unsigned char *)pBuf;

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxRecv);
	
	for ( i = 0; i < Size; i++ )
	{
		/* 受信ストリームバッファを読み出す */
		while ( (c = StreamBuf_RecvChar(&self->StmBufRecv)) < 0 )
		{
			FILE_ERR err;
		
			/* バッファが空なら読込み可能シグナルを待つ */
			SysMtx_Unlock(self->hMtxRecv);
			err = ChrDrv_WaitReadSignal(&self->ChrDrv, pFile);
			SysMtx_Lock(self->hMtxRecv);
			
			if ( err != FILE_ERR_OK )
			{
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
