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


/* システムボリュームにデバイスをぶら下げる */
FILE_ERR SysVol_AddDevice(HANDLE hSysVol, const char *pszName, HANDLE hDriver, int iAttr)
{
	T_SYSVOL_DEVINF	DevInf;
	C_SYSVOL		*self;
	
	self = (C_SYSVOL *)hSysVol;
	
	/* 登録 */
	DevInf.hDriver = hDriver;
	DevInf.iAttr   = iAttr;
	if ( Assoc_Add(&self->asDevice, pszName, &DevInf, sizeof(T_SYSVOL_DEVINF)) != ASSOC_ERR_OK )
	{
		return FILE_ERR_NG;	
	}

	return FILE_ERR_OK;
}


/* end of file */
