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
void FatVol_Destructor(C_FATVOL *self)
{
	int	i;
	
	/* デバイスクローズ */
	File_Close(self->hBlockFile);
	
	/* クラスタバッファ開放 */
	for ( i = 0; i < self->iClusterBufNum; i++ )
	{
		SysIo_FreeIoMem(self->pClusterBuf[i].pubBuf);
	}
	SysMem_Free(self->pClusterBuf[i].pubBuf);
	
	/* ミューテックス削除 */
	SysMtx_Delete(self->hMtx);
	
	/* 親クラスデコンストラクタ呼び出し */
	VolumeObj_Delete(&self->VolumeObj);
}


/* end of file */
