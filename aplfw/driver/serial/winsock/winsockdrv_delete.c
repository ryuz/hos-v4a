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



/** 削除 */
void WinSockDrv_Delete(HANDLE hDriver)
{
	C_WINSOCKDRV	*self;
	
	/* upper cast */
	self = (C_WINSOCKDRV *)hDriver;

	/* デストラクタ呼び出し */
	WinSockDrv_Destructor(self);
	
	/* メモリ削除 */
	SysMem_Free(self);
}


/* end of file */
