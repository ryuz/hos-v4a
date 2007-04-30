/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{PC16550用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550drv_local.h"


/** クローズ */
void Pc16550Drv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_PC16550DRV	*self;
	
	/* upper cast */
	self = (C_PC16550DRV *)pDrvObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNum);
		Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, 0);
		Pc16550Hal_Stop(&self->Pc16550Hal);
		StreamBuf_ClearBuf(&self->StmBufRecv);
	}
}


/* end of file */
