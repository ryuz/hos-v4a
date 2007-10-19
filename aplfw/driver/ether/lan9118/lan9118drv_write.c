/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv_write.c
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9118drv_local.h"


/** %jp{送信} */
FILE_SIZE Lan9118Drv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_LAN9118DRV		*self;
	C_CHRFILE			*pFile;
	const unsigned char	*pubBuf;
	FILE_SIZE			i;
	int					c;
	
	/* upper cast */
	self  = (C_LAN9118DRV *)pDrvObj;
	pFile = (C_CHRFILE *)pFileObj;
	
	pubBuf = (const unsigned char *)pData;
	
	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxSend);
	
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxSend);

	return 0;
}


/* end of file */
