/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <string.h>
#include "sysvol_local.h"


/* システムボリュームに登録されたデバイスを取り外し */
FILE_ERR SysVol_RemoveDevice(HANDLE hSysVol, const char *pszName)
{
	C_SYSVOL	*self;
	
	self = (C_SYSVOL *)hSysVol;
	
	/* 登録解除 */
	if ( Assoc_Remove(&self->asDevice, pszName) != ASSOC_ERR_OK )
	{
		return FILE_ERR_NG;
	}
	
	return FILE_ERR_OK;
}


/* end of file */
