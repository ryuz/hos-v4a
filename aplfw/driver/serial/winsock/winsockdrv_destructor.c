/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  winsockdrv.h
 * @brief %jp{WinSockでシリアルを擬似するドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "winsockdrv_local.h"


/** デストラクタ */
void WinSockDrv_Destructor(C_WINSOCKDRV *self)
{
	

	/* 親クラスデストラクタ */
	SyncDrv_Destructor(&self->SyncDrv);
}



/* end of file */
