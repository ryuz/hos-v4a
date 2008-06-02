/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdrv.h
 * @brief %jp{メモリマップドファイル用デバイスドライバ}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"
#include "memdrv_local.h"



FILE_ERR MemDrv_GetInformation(C_DRVOBJ *pDrvObj, char *pszInformation, int iLen)
{
	C_MEMDRV *self;
	
	/* upper cast */
	self = (C_MEMDRV *)pDrvObj;
	
	StringFormat_FormatString
						(
							pszInformation, iLen,
							"addr:%lx size:%ld max-size:%ld",
							(unsigned long)self->pubMemAddr,
							(unsigned long)self->FileSize,
							(unsigned long)self->MemSize
						);
	
	return FILE_ERR_OK;
}


/* end of file */
