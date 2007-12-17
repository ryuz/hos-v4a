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
	
	/* 読込みシグナルを一旦クリア */
	ChrDrv_ClearReadSignal(&self->ChrDrv);
	
	for ( i = 0; i < Size; i++ )
	{
		/* 読み出し */
		while ( (c = StreamBuf_RecvChar(&self->StmBufRecv)) < 0 )
		{
			/* 受信を待つ */
			if ( ChrDrv_WaitReadSignal(&self->ChrDrv, pFile) != FILE_ERR_OK )
			{
				SysMtx_Unlock(self->hMtxRecv);	/* クリティカルセクションを出る */
				return i;
			}
			
			/* 読込みシグナルをクリアしてリトライ */
			ChrDrv_ClearReadSignal(&self->ChrDrv);
		}
		
		/* 読み出せた文字を格納 */	
		*pubBuf++ = (unsigned char)c;
	}
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxRecv);

	return i;
}


/* end of file */
