/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fatfile_local.h"


void FatFile_Delete(HANDLE hFile)
{
	C_FATFILE *self;
	
	self = (C_FATFILE *)hFile;
	
	/* デストラクタ */
	FatFile_Destructor(self);
	
	/* メモリ削除 */
	SysMem_Free(self);
}


/* end of file */
