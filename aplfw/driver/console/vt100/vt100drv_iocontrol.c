/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  vt100drv_open.c
 * @brief %jp{VT100 ターミナルドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "vt100drv_local.h"
#include "system/sysapi/sysapi.h"

FILE_ERR  Vt100Drv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_VT100DRV			*self;
	
	/* upper cast */
	self = (C_VT100DRV *)pDrvObj;
	
	switch ( iFunc )
	{
	case FILE_IOCTL_CON_GETCH:
		*(int *)pInBuf = Vt100Drv_GetCh(self);
		return FILE_ERR_OK;

	default:
		return  FILE_ERR_NG;
	}
}


/* end of file */
