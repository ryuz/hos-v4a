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


FILE_ERR FatVol_Shutdown(C_VOLUMEOBJ *pVolObj)
{
	C_FATVOL	*self;
	
	/* upper cast */
	self  = (C_FATVOL *)pVolObj;
	
	/* 開いているファイルがあれば失敗 */	
	if ( self->iOpenCount> 0 )
	{
		return FILE_ERR_NG;
	}
	
	/* フラッシュ */
	FatVol_FlushClusterBuf(self);
	FatVol_FlushFat(self);
	
	
	return FILE_ERR_OK;
}


/* end of file */
