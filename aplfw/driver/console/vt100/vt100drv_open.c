/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  vt100drv_open.c
 * @brief %jp{VT100 ターミナルドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "vt100drv_local.h"
#include "system/sysapi/sysapi.h"



HANDLE Vt100Drv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_VT100DRV			*self;
	C_FILEOBJ			*pFileObj;
	
	/* upper cast */
	self = (C_VT100DRV *)pDrvObj;
	
	/* create file descriptor */
	if ( (pFileObj = SysMem_Alloc(sizeof(*pFileObj))) == NULL )
	{
		return HANDLE_NULL;
	}
	FileObj_Create(pFileObj, pDrvObj, NULL);
	
	return (HANDLE)pFileObj;
}


/* end of file */
