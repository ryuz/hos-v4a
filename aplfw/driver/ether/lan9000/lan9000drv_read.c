/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{LAN9000用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9000drv_local.h"


/** %jp{受信} */
FILE_SIZE Lan9000Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_LAN9000DRV	*self;
	C_CHRFILE		*pFile;
	FILE_SIZE		RecvSize;
	unsigned short	uhStatus;
		
	/* upper cast */
	self  = (C_LAN9000DRV *)pDrvObj;
	pFile = (C_CHRFILE *)pFileObj;


	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtx);

	while ( (RecvSize = Lan9000Hal_Recv(&self->Lan9000Hal, pBuf, Size)) == 0 )
	{
		if ( pFile->cReadMode != FILE_RMODE_BLOCKING )
		{
			break;
		}
		
		uhStatus = Lan9000Hal_GetInterruptStatus(&self->Lan9000Hal);
		Lan9000Hal_SetInterruptMask(&self->Lan9000Hal, (uhStatus | LAN9000HAL_IMASK_RCVINT));
		
		/* ブロッキングなら受信イベントを待つ */
		SysMtx_Unlock(self->hMtx);
		
		SysEvt_Wait(self->hEvtRecv);
		SysEvt_Clear(self->hEvtRecv);
		SysMtx_Lock(self->hMtx);
	}
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtx);

	return RecvSize;
}


/* end of file */
