/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fatvol_local.h"


FILE_ERR FatVol_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_FATVOL	*self;
	
	/* upper cast */
	self  = (C_FATVOL *)pDrvObj;

	/* クリティカルセクションに入る */
	SysMtx_Lock(self->hMtx);
	
	/* FATの書き出し */
	FatVol_FlushFat(self);
	
	/* バッファのフラッシュ */
	FatVol_FlushClusterBuf(self);
	
	
	/* クリティカルセクションを出る */
	SysMtx_Unlock(self->hMtx);

	return FILE_ERR_OK;
}


/* end of file */
