/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv_read.c
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9118drv_local.h"


/** %jp{受信} */
FILE_SIZE Lan9118Drv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_LAN9118DRV	*self;
	C_CHRFILE		*pFile;
	unsigned char	*pubBuf;
	FILE_SIZE		i;
	int				c;
	
	/* upper cast */
	self  = (C_LAN9118DRV *)pDrvObj;
	pFile = (C_CHRFILE *)pFileObj;
	
	pubBuf = (unsigned char *)pBuf;

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtxRecv);
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtxRecv);

	return i;
}


/* end of file */
