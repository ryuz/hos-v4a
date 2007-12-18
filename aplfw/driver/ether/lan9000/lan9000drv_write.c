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


/** %jp{送信} */
FILE_SIZE Lan9000Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_LAN9000DRV	*self;
	C_SYNCFILE		*pFile;
	FILE_SIZE		SendSize;
	unsigned short	uhStatus;
	
	/* upper cast */
	self  = (C_LAN9000DRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtx);

	while ( (SendSize = Lan9000Hal_Send(&self->Lan9000Hal, pData, Size)) == 0 )
	{
		if ( pFile->cWriteMode != FILE_WMODE_BLOCKING )
		{
			break;
		}
		
		/* ブロッキングなら送信割り込みを待つ */
		uhStatus = Lan9000Hal_GetInterruptStatus(&self->Lan9000Hal);
		Lan9000Hal_SetInterruptMask(&self->Lan9000Hal, (uhStatus | LAN9000HAL_IMASK_ALLOCINT));
		
		SysMtx_Unlock(self->hMtx);
		SysEvt_Wait(self->hEvtSend);
		SysEvt_Clear(self->hEvtSend);
		SysMtx_Lock(self->hMtx);
	}
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtx);

	return SendSize;
}



/* end of file */
