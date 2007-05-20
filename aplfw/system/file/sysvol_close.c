/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "sysvol_local.h"
#include "system/sysapi/sysapi.h"


void SysVol_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_SYSVOL    *self;
	C_SYSVOLDIR *pDir;
	
	/* upper cast */
	self = (C_SYSVOL *)pDrvObj;
	pDir = (C_SYSVOLDIR *)pFileObj;
	
	/* 削除 */
	FileObj_Delete(&pDir->FileObj);
	SysMem_Free(pDir);
}


/* end of file */

