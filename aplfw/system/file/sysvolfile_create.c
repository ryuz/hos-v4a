/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 *  %jp{ルートディレクトリや /dev ディレクトリなど、システム上の仮想ボリュームを管理}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include "sysvolfile_local.h"


static const T_FILEOBJ_METHODS SysVolFile_FileObjMethods =
	{
		{File_Close},
	};


HANDLE SysVolFile_Create(struct c_sysvol *pSysVol, int iMode)
{
	C_SYSVOLFILE *self;
	
	/* メモリ確保 */
	if ( (self = (C_SYSVOLFILE *)SysMem_Alloc(sizeof(C_SYSVOLFILE))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	SysVolFile_Constructor(self, &SysVolFile_FileObjMethods, pSysVol, iMode);	
	
	return (HANDLE)self;	
}


/* end of file */
