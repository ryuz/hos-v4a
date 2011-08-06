/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


/** クローズ */
void SciDrv_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_SCIDRV	*self;
	
	/* upper cast */
	self = (C_SCIDRV *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SciHal_EnableInterrupt(&self->SciHal, 0);
		SciHal_Stop(&self->SciHal);
		StreamBuf_Clear(&self->StmBufRecv);
	}
	
	/* ディスクリプタ削除 */
	SysMem_Free(pFilePtr);
}


/* end of file */
