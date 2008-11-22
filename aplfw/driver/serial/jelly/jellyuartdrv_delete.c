/** 
 * Hyper Operating System  Application Framework
 *
 * @file  jellyuartdrv_delete.c
 * @brief %jp{JellyUart オブジェクト削除}%en{JellyUart  delete object}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "jellyuartdrv_local.h"


/** 削除 */
void JellyUartDrv_Delete(HANDLE hDriver)
{
	C_JELLYUARTDRV	*self;
	
	/* upper cast */
	self = (C_JELLYUARTDRV *)hDriver;

	/* %jp{デストラクタ呼び出し}%en{destructor} */
	JellyUartDrv_Destructor(self);
	
	/* %jp{メモリ開放}%en{free memory} */
	SysMem_Free(self);
}


/* end of file */
