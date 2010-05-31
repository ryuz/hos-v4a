/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 * Copyright (C) 2006-2010 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <string.h>
#include "sysvol_local.h"


/* システムボリュームに登録されたデバイスを検索 */
HANDLE SysVol_GetDevice(HANDLE hSysVol, const char *pszName)
{
	T_SYSVOL_DEVINF	*pDevInf;
	C_SYSVOL		*self;
	
	self = (C_SYSVOL *)hSysVol;
	
	/* 検索 */
	if ( (pDevInf = (T_SYSVOL_DEVINF *)Assoc_Get(&self->asDevice, pszName)) == NULL )
	{
		return HANDLE_NULL;	
	}
	
	return pDevInf->hDriver;
}


/* end of file */
