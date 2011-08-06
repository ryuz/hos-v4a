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


void SysVol_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_SYSVOL		*self;
	C_SYSVOLFILE	*pFile;
	
	/* upper cast */
	self  = (C_SYSVOL *)pFileObj;
	pFile = (C_SYSVOLFILE *)pFilePtr;
	
	/* 削除 */
	SysVolFile_Delete(pFile);
}


/* end of file */

