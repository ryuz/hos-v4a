/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.h
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "fatvol_local.h"



/* コンストラクタ */
HANDLE FatVol_Create(const char *pszPath)
{
	C_FATVOL	*self;
	
	/* メモリ確保 */
	if ( (self = (C_FATVOL *)SysMem_Alloc(sizeof(C_FATVOL))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( FatVol_Constructor(self, NULL, pszPath) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}



/* end of file */
