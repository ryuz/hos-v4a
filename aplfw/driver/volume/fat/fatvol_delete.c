/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol_delete.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fatvol_local.h"


/** デストラクタ */
void FatVol_Delete(HANDLE hVolume)
{
	C_FATVOL	*self;

	self = (C_FATVOL *)hVolume;
	
	/* デストラクタ呼び出し */
	FatVol_Destructor(self);
	
	/* メモリ開放 */
	SysMem_Free(self);
}


/* end of file */
